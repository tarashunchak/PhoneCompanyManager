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
    ui->delete_employee_btn->setStyleSheet("background-color:transparent;");

    ui->requests_statistic_tableView->setModel(TABLE_MODELS.req_qmodel);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    SetConnections();
}

EmployeesDetailsPage::~EmployeesDetailsPage()
{
    delete ui;
}

void EmployeesDetailsPage::SetConnections(){
    connect(ui->save_comment_btn, &QPushButton::clicked, this, [this](){
        DatabaseManager::saveCommentToDB(DatabaseManager::TABLE::EMPLOYEES
                                         , ui->empl_id_Label->property("id").toInt()
                                         , ui->comment_textEdit->property("comment_id").toInt()
                                         , ui->comment_textEdit->toPlainText());
    });
    connect(ui->delete_employee_btn, &QPushButton::clicked, ui->delete_employee_widget, &QWidget::show);
    connect(ui->cancel_btn, &QPushButton::clicked, ui->delete_employee_widget, &QWidget::close);
    connect(ui->confirm_btn, &QPushButton::clicked, this, [this](){
        ui->delete_employee_widget->close();
        DatabaseManager::deleteRecord(DatabaseManager::TABLE::EMPLOYEES, CurrentEmployee::id.toUInt());
        emit on_return_btn_clicked();
    });
}

void EmployeesDetailsPage::SetEmployeeInfo(const uint empl_id){
    auto query = DatabaseManager::currentEmployee(empl_id);
    ui->empl_id_Label->setText(CurrentEmployee::id);
    ui->empl_id_Label->setProperty("id", CurrentEmployee::id);
    ui->phone_Label->setText(CurrentEmployee::first_name + " " + CurrentEmployee::last_name);
    ui->email_Label->setText(CurrentEmployee::phone);
    ui->full_name_Label->setText(CurrentEmployee::email);
    ui->department_Label->setText(CurrentEmployee::department_name);
    ui->department_Label->setProperty("department_id", CurrentEmployee::department_id);
    ui->position_Label->setText(CurrentEmployee::position_name);
    ui->position_Label->setProperty("position_id", CurrentEmployee::position_id);
    ui->comment_textEdit->setPlainText(CurrentEmployee::comment_text);
    ui->comment_textEdit->setProperty("comment_id", CurrentEmployee::comment_id);
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
