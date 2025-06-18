#include "employeesdetailspage.h"
#include "ui_employeesdetailspage.h"
#include "includes/databasemanager.h"
#include <QSqlQuery>
#include <QtConcurrent/QtConcurrent>

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

    ui->customers_statistic_tableView->setModel(TABLE_MODELS.cust_qmodel);
    ui->customers_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->requests_statistic_tableView->setModel(TABLE_MODELS.req_qmodel);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->current_customers_tableView->setModel(TABLE_MODELS.curr_cust_qmodel);
    ui->current_customers_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    SetTableViewStyle();
    SetConnections();
    ui->no_curr_customers_label->setVisible(false);
    ui->no_customers_label->setVisible(false);
    ui->no_requests_label->setVisible(false);
}

EmployeesDetailsPage::~EmployeesDetailsPage()
{
    delete ui;
}

void EmployeesDetailsPage::SetConnections(){
    connect(ui->save_comment_btn, &QPushButton::clicked, this, [this](){
        int comment_id = CurrentEmployee::comment_id.toInt();
        QString text = ui->comment_textEdit->toPlainText();
        DatabaseManager::saveCommentToDB(TABLE::EMPLOYEES
                               , CurrentEmployee::id.toUInt(), comment_id, text);
    });
    connect(ui->delete_employee_btn, &QPushButton::clicked, ui->delete_employee_widget, &QWidget::show);
    connect(ui->cancel_btn, &QPushButton::clicked, ui->delete_employee_widget, &QWidget::close);
    connect(ui->confirm_btn, &QPushButton::clicked, this, [this](){
        ui->delete_employee_widget->close();
        DatabaseManager::deleteRecord<TABLE::EMPLOYEES>("id", CurrentEmployee::id.toUInt());
        emit on_return_btn_clicked();
    });
}

void EmployeesDetailsPage::SetEmployeeInfo(const uint empl_id){
    auto query = DatabaseManager::currentEmployee(empl_id);
    ui->empl_id_Label->setText(CurrentEmployee::id);
    ui->full_name_Label->setText(CurrentEmployee::first_name + " " + CurrentEmployee::last_name);
    ui->phone_Label->setText(CurrentEmployee::phone);
    ui->email_Label->setText(CurrentEmployee::email);
    ui->hire_date_Label->setText(CurrentEmployee::hire_date);
    ui->department_Label->setText(CurrentEmployee::department_name);
    ui->position_Label->setText(CurrentEmployee::position_name);
    ui->comment_textEdit->setPlainText(CurrentEmployee::comment_text);
    SetRequestsHistory();
    SetCurrentCustomers();
    SetCustomersHistory();
    bool is_curr_user = (CurrentEmployee::id.toUInt() == CurrentUser::getCurrentEmployeeID());
    ui->delete_employee_btn->setVisible(!is_curr_user);
    ui->comment_textEdit->setEnabled(!is_curr_user);
    ui->save_comment_btn->setEnabled(!is_curr_user);
}

void EmployeesDetailsPage::SetCustomersHistory()const{
    QSqlQuery query(QSqlDatabase::database("remote"));
    query.prepare("SELECT id AS ID, "
                  "(first_name || ' ' || last_name) AS \"Full name\", "
                  "phone AS Phone "
                  "FROM customers "
                  "WHERE added_by_id = ?;");
    query.addBindValue(CurrentEmployee::id);
    if(!query.exec())
        qDebug() << "cannot select customers history on employee details page";
    TABLE_MODELS.cust_qmodel->setQuery(std::move(query));
}

void EmployeesDetailsPage::SetRequestsHistory()const{
    auto query = DatabaseManager::requestsHistory(PAGE::EMPLOYEES_DETAILS_PAGE);
    //if(!query.exec() || !query.next()){
        //qDebug() << "In EmployeesDetailsPage::SetRequestsHistory::query fault!!!: " << query.lastError();
        //ui->requests_statistic_tableView->setVisible(false);
        //ui->no_customers_label->setVisible(true);
        //return;
    //}
    //query.previous();
    query.exec();
    TABLE_MODELS.req_qmodel->setQuery(std::move(query));
    //ui->requests_statistic_tableView->setVisible(true);
    //ui->no_requests_label->setVisible(false);
}

void EmployeesDetailsPage::SetTableViewStyle(){
    static QString header_style{
        "QHeaderView{"
        "   border:1px solid rgba(0, 0, 0, 0.4);"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:18px;"
        "   color:black;"
        "   height:36px;"
        "}"
    };
    ui->requests_statistic_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->requests_statistic_tableView->horizontalHeader()->setStyleSheet(header_style);
    ui->customers_statistic_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->customers_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->customers_statistic_tableView->horizontalHeader()->setStyleSheet(header_style);
    ui->current_customers_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->current_customers_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->current_customers_tableView->horizontalHeader()->setStyleSheet(header_style);
}

void EmployeesDetailsPage::SetCurrentCustomers()const{
    QSqlQuery query(QSqlDatabase::database("remote"));
    query.prepare("SELECT id AS ID, phone AS Phone, "
                  "(first_name || ' ' || last_name) AS \"Full name\" "
                  "FROM customers WHERE employee_id = ?;");
    query.addBindValue(CurrentEmployee::id);
    if(!query.exec() && !query.first()){
        //ui->no_curr_customers_label->setVisible(true);
        qDebug() << "ERROR IN SETCURRENTCUSTOMERS QUERY!!!";
    }else{
        query.previous();
        QSqlQueryModel* model = TABLE_MODELS.curr_cust_qmodel;
        model->setQuery(std::move(query));
        //ui->no_curr_customers_label->setVisible(false);
    }
}
