#include "includes/customersdetailspage.h"
#include "ui_customersdetailspage.h"
#include "includes/databasemanager.h"
#include "includes/buttonsstylemanager.h"
#include "includes/currentuser.h"
#include <QSqlQuery>
#include <QSqlError>

CustomersDetailsPage::CustomersDetailsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersDetailsPage)
    , db(&DatabaseManager::instance().getDatabase())
    , qmodel(new QSqlTableModel{})
    , tariff_chart(new PieChart{})
    , usage_chart(new LineChart{})
{
    ui->setupUi(this);

    tariff_chart->setParent(ui->tariffs_history);
    tariff_chart->resize(ui->tariffs_history->size());

    usage_chart->setParent(ui->usage_history);
    usage_chart->resize(ui->usage_history->size());

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });

    SetTableViewStyle();

    ui->name_label->setAlignment(Qt::AlignCenter);
    ui->profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});
    ui->cust_profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});
    ui->return_btn->setIcon(QIcon{"./img/exit.png"});

}

CustomersDetailsPage::~CustomersDetailsPage()
{
    db = nullptr;
    delete ui;
}

void CustomersDetailsPage::setCurrentUser(){
    QSqlQuery query;
    query.prepare("SELECT *FROM Employees WHERE id = :empl_id;");
    const int empl_id = CurrentUser::getCurrentUserID();
    query.bindValue(":empl_id", empl_id);
    if(query.exec() && query.next()){
        ui->name_label->setText(query.value("full_name").toString());
    }else{
        qDebug() << "setCurrentUser Dashboard Page fault!" << query.lastError();
        return;
    }
}

void CustomersDetailsPage::SetConnections(){
    connect(ui->return_btn, &QPushButton::clicked, this, [this](){emit on_return_btn_clicked();});
}

void CustomersDetailsPage::SetCustomerInfo(const int id){
    QSqlQuery query;
    query.prepare("SELECT *FROM Customers WHERE id = :id;");
    query.bindValue(":id", id);

    if(!query.exec() || !query.next()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo fault!!!: " << query.lastError();
        return;
    }

    ui->full_name_Label->setText(query.value("full_name").toString());
    ui->phone_Label->setText(query.value("phone").toString());
    ui->reg_date_Label->setText(query.value("date").toString());

    qmodel->setQuery(std::move(query));

    ui->tableView->setModel(qmodel);

    SetCharts(id);
}

void CustomersDetailsPage::SetTableViewStyle(){
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setStyleSheet(
        "QTableView{"
        "background-color:rgb(100, 100, 100);"
        "color:black;"
        "font-size:16px;"
        "}"
    );
}

void CustomersDetailsPage::SetCharts(const int id){
    QSqlQuery tariff_query{};
    tariff_query.prepare("SELECT Tariffs.tariff_name AS name, Tariffs.id AS id FROM Customers "
                  "JOIN Tariffs ON Tariffs.id = Customers.tariff_id "
                  "WHERE Customers.id = :id;");
    tariff_query.bindValue(":id", id);
    if(!tariff_query.exec()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo::tariff_query fault!!!: " << tariff_query.lastError();
        return;
    }
    tariff_chart->setQuery(std::move(tariff_query), "name", "id");

    QSqlQuery usage_query{};
    usage_query.prepare("SELECT date(date) AS usage_date, COUNT(*) AS count FROM Usage "
                        "WHERE cust_id = :id AND date(date) >= date('now', '-6 days') "
                        "GROUP BY usage_date ORDER BY usage_date ASC;");
    usage_query.bindValue(":id", id);
    usage_chart->setQuery(std::move(usage_query), "count", "usage_date");
}
