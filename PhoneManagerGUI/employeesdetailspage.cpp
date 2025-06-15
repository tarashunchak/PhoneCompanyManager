#include "employeesdetailspage.h"
#include "ui_employeesdetailspage.h"
#include "includes/databasemanager.h"
#include <QSqlQuery>

QString EmployeesDetailsPage::CurrentEmployee::id = {};
QString EmployeesDetailsPage::CurrentEmployee::first_name = {};
QString EmployeesDetailsPage::CurrentEmployee::last_name = {};
QString EmployeesDetailsPage::CurrentEmployee::department_id = {};
QString EmployeesDetailsPage::CurrentEmployee::department_name = {};
QString EmployeesDetailsPage::CurrentEmployee::position_id = {};
QString EmployeesDetailsPage::CurrentEmployee::position_name = {};
QString EmployeesDetailsPage::CurrentEmployee::hire_date = {};
QString EmployeesDetailsPage::CurrentEmployee::salary = {};
QString EmployeesDetailsPage::CurrentEmployee::phone = {};
QString EmployeesDetailsPage::CurrentEmployee::email = {};
//QPixmap EmployeesDetailsPage::CurrentEmployee::photo = {};
QString EmployeesDetailsPage::CurrentEmployee::is_active = {};
QString EmployeesDetailsPage::CurrentEmployee::date_of_B = {};
QString EmployeesDetailsPage::CurrentEmployee::comment_text= {};
QString EmployeesDetailsPage::CurrentEmployee::comment_id = {};

EmployeesDetailsPage::EmployeesDetailsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeeDetailsPage)
{
    ui->setupUi(this);

    ui->delete_employee_widget->setVisible(false);
    ui->cust_profile_pic->setPixmap(QPixmap{"./img/profile_photo_cust.svg"});
    ui->return_btn->setIcon(QIcon{"./img/exit.png"});
    ui->delete_employee_btn->setIcon(QIcon{"./img/delete_can.png"});

    ui->requests_statistic_tableView->setModel(TABLE_MODELS.req_qmodel);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    SetTableViewStyle();
    SetConnections();
}

EmployeesDetailsPage::~EmployeesDetailsPage()
{
    delete ui;
}

void EmployeesDetailsPage::SetConnections(){
    connect(ui->save_comment_btn, &QPushButton::clicked, this, [this](){
        int comment_id = CurrentEmployee::comment_id.toInt();
        QString text = ui->comment_textEdit->toPlainText();
        DatabaseManager::saveCommentToDB(DatabaseManager::TABLE::EMPLOYEES
                               , CurrentEmployee::id.toUInt(), comment_id, text);
    });
    connect(ui->delete_employee_btn, &QPushButton::clicked, ui->delete_employee_widget, &QWidget::show);
    connect(ui->cancel_btn, &QPushButton::clicked, ui->delete_employee_widget, &QWidget::close);
    connect(ui->confirm_btn, &QPushButton::clicked, this, [this](){
        ui->delete_employee_widget->close();
        QtConcurrent::run([](){
            DatabaseManager::deleteRecord<DatabaseManager::TABLE::EMPLOYEES>("id", CurrentEmployee::id.toUInt());
        });
        emit on_return_btn_clicked();
    });
}

void EmployeesDetailsPage::SetEmployeeInfo(const uint empl_id){
    auto query = DatabaseManager::currentEmployee(empl_id);
    ui->empl_id_Label->setText(CurrentEmployee::id);
    ui->phone_Label->setText(CurrentEmployee::first_name + " " + CurrentEmployee::last_name);
    ui->email_Label->setText(CurrentEmployee::phone);
    ui->full_name_Label->setText(CurrentEmployee::email);
    ui->department_Label->setText(CurrentEmployee::department_name);
    ui->position_Label->setText(CurrentEmployee::position_name);
    ui->comment_textEdit->setPlainText(CurrentEmployee::comment_text);
    SetRequestsHistory();
}

void EmployeesDetailsPage::SetRequestsHistory()const{
    auto query = DatabaseManager::requestsHistory(DatabaseManager::PAGE::EMPLOYEES_DETAILS_PAGE);
    if(!query.exec() || !query.next()){
        qDebug() << "In EmployeesDetailsPage::SetRequestsHistory::query fault!!!: " << query.lastError();
        ui->requests_statistic_tableView2->setVisible(false);
        ui->no_payments_label->setVisible(true);
        return;
    }
    TABLE_MODELS.req_qmodel->setQuery(std::move(query));
    bool is_model_empty = !TABLE_MODELS.req_qmodel->rowCount();
    ui->requests_statistic_tableView->setVisible(!is_model_empty);
    ui->no_requests_label->setVisible(is_model_empty);
}

void EmployeesDetailsPage::SetTableViewStyle(){
    ui->requests_statistic_tableView->setModel(TABLE_MODELS.req_qmodel);
    ui->requests_statistic_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->requests_statistic_tableView->horizontalHeader()->setStyleSheet(
        "QHeaderView{"
        "   border:1px solid rgba(0, 0, 0, 0.4);"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:18px;"
        "   color:black;"
        "   height:36px;"
        "}"
        );
}
