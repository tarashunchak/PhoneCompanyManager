#include "includes/customersdetailspage.h"
#include "ui_customersdetailspage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QHeaderView>
#include "includes/databasemanager.h"

QString CustomersDetailsPage::CurrentCustomer::id = {};
QString CustomersDetailsPage::CurrentCustomer::first_name = {};
QString CustomersDetailsPage::CurrentCustomer::last_name = {};
QString CustomersDetailsPage::CurrentCustomer::phone = {};
QString CustomersDetailsPage::CurrentCustomer::email = {};
QString CustomersDetailsPage::CurrentCustomer::reg_date = {};
QString CustomersDetailsPage::CurrentCustomer::date_of_B = {};
QString CustomersDetailsPage::CurrentCustomer::tariff_name = {};
QString CustomersDetailsPage::CurrentCustomer::tariff_id = {};
QString CustomersDetailsPage::CurrentCustomer::comment_text = {};
QString CustomersDetailsPage::CurrentCustomer::comment_id = {};
QString CustomersDetailsPage::CurrentCustomer::balance = {};
QString CustomersDetailsPage::CurrentCustomer::employee_id = {};
QString CustomersDetailsPage::CurrentCustomer::is_active = {};

CustomersDetailsPage::CustomersDetailsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersDetailsPage)
    , tariff_pie_chart(new PieChart{})
    , TABLE_MODELS{new QSqlTableModel{/*req_qmodel*/}
                   , new QSqlTableModel{/*payments_qmodel*/}
                   , new QSqlTableModel{/*messages_qmodel*/}}
{
    ui->setupUi(this);

    tariff_pie_chart->setParent(ui->tariffs_history);
    tariff_pie_chart->resize(ui->tariffs_history->size());

    ui->no_request_label->setVisible(false);

    SetTableViewStyle();

    ui->cust_profile_pic->setPixmap(QPixmap{"./img/profile_photo_cust.svg"});
    ui->return_btn->setIcon(QIcon{"./img/exit.png"});
    ui->delete_customer_btn->setIcon(QIcon{"./img/delete_can.png"});
    ui->delete_customer_btn->setStyleSheet("background-color:transparent;");

    ui->delete_customer_widget->close();

    SetConnections();
}

CustomersDetailsPage::~CustomersDetailsPage()
{
    delete ui;
}

void CustomersDetailsPage::SetConnections(){
    connect(ui->return_btn, &QPushButton::clicked, this, [this](){emit on_return_btn_clicked();});
    connect(ui->open_chat_btn, &QPushButton::clicked, this, [this](){
        emit on_open_chat_btn_clicked(ui->phone_Label->text());
    });
    connect(ui->save_comment_btn, &QPushButton::clicked, this, [this](){
        DatabaseManager::saveCommentToDB(DatabaseManager::TABLE::CUSTOMERS
                                         , ui->cust_id_label->property("id").toInt()
                                         , ui->comment_textEdit->property("comment_id").toInt()
                                         , ui->comment_textEdit->toPlainText());
    });
    connect(ui->delete_customer_btn, &QPushButton::clicked, ui->delete_customer_widget, &QWidget::show);
    connect(ui->cancel_btn, &QPushButton::clicked, ui->delete_customer_widget, &QWidget::close);
    connect(ui->confirm_btn, &QPushButton::clicked, this, [this](){
        ui->delete_customer_widget->close();
        DatabaseManager::deleteRecord(DatabaseManager::TABLE::CUSTOMERS, CurrentCustomer::id.toUInt());
        emit on_return_btn_clicked();
    });
}

void CustomersDetailsPage::SetCustomerInfo(const uint id){
    auto query = DatabaseManager::currentCustomer(id);
    ui->current_balance_label->setText(CurrentCustomer::balance);
    ui->cust_id_label->setText(CurrentCustomer::id);
    ui->cust_id_label->setProperty("id", CurrentCustomer::id);
    ui->full_name_Label->setText(CurrentCustomer::first_name + " " + CurrentCustomer::last_name);
    ui->phone_Label->setText(CurrentCustomer::phone);
    ui->reg_date_Label->setText(CurrentCustomer::reg_date);
    ui->current_tariff_label->setText(CurrentCustomer::tariff_name);
    ui->comment_textEdit->setPlainText(CurrentCustomer::comment_text);
    ui->comment_textEdit->setProperty("comment_id", CurrentCustomer::comment_id);

    TABLE_MODELS.payments_qmodel->setQuery(std::move(query));

    SetCharts();
}

void CustomersDetailsPage::SetPaymentsHistory()const{
    QSqlQuery query;
    query.prepare("SELECT * FROM payments "
                  "WHERE cust_id = :cust_id;");
    query.bindValue(":cust_id", CurrentCustomer::id);
    ui->no_payments_label->setVisible(!query.exec());
    TABLE_MODELS.payments_qmodel->setQuery(std::move(query));
}

void CustomersDetailsPage::SetTableViewStyle(){
    ui->requests_statistic_tableView->setModel(TABLE_MODELS.req_qmodel);
    ui->requests_statistic_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->payments_statistic_tableView->setModel(TABLE_MODELS.payments_qmodel);
    ui->payments_statistic_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->payments_statistic_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->payments_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->payments_statistic_tableView->horizontalHeader()->setStyleSheet(
        "QHeaderView{"
        "   border:1px solid rgba(0, 0, 0, 0.4);"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:18px;"
        "   color:black;"
        "   height:36px;"
        "}"
    );
}

void CustomersDetailsPage::SetTariffsChart()const{
    QSqlQuery query;
    query.prepare("SELECT t.tariff_name AS name, t.id AS id "
                         "FROM customers c "
                         "JOIN tariffs t ON t.id = c.tariff_id "
                         "WHERE c.id = :id;");
    query.bindValue(":id", CurrentCustomer::id);
    if(!query.exec()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo::query fault!!!: " << query.lastError();
        return;
    }
    tariff_pie_chart->setQuery(std::move(query), "name", "id");
}

void CustomersDetailsPage::SetRequestsHistory()const{
    auto query = DatabaseManager::requestsHistory(DatabaseManager::PAGE::CUSTOMERS_DETAILS_PAGE);
    if(!query.exec() || !query.next()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo::query fault!!!: " << query.lastError();
        ui->requests_statistic_tableView->setVisible(false);
        ui->no_request_label->setVisible(true);
        return;
    }
    TABLE_MODELS.req_qmodel->setQuery(std::move(query));
    if(!TABLE_MODELS.req_qmodel->rowCount()){
        ui->requests_statistic_tableView->setVisible(false);
        ui->no_request_label->setVisible(true);
    }else{
        ui->requests_statistic_tableView->setVisible(true);
        ui->no_request_label->setVisible(false);
    }
}

void CustomersDetailsPage::SetCharts(){
    SetTariffsChart();
    SetRequestsHistory();
    SetPaymentsHistory();
}
