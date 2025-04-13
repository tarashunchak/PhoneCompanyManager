#include "includes/customersdetailspage.h"
#include "ui_customersdetailspage.h"
#include "includes/databasemanager.h"
#include "includes/buttonsstylemanager.h"
#include <QSqlQuery>
#include <QSqlError>

CustomersDetailsPage::CustomersDetailsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersDetailsPage)
    , db(&DatabaseManager::instance().getDatabase())
    , qmodel(new QSqlTableModel{})
    , tariff_chart(new PieChart{})
{
    ui->setupUi(this);

    tariff_chart->setParent(ui->tariffs_history);
    tariff_chart->resize(ui->tariffs_history->size());

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });

    SetTableViewStyle();

    ui->profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});
    ui->cust_profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});
    ui->return_btn->setIcon(QIcon{"./img/return.svg"});
}

CustomersDetailsPage::~CustomersDetailsPage()
{
    db = nullptr;
    delete ui;
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
    ui->tableView->setGeometry(50, 510, 980, 450);
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
    QSqlQuery chart_query;
    chart_query.prepare("SELECT Tariffs.tariff_name AS name, Tariffs.id AS id FROM Customers "
                  "JOIN Tariffs ON Tariffs.id = Customers.tariff_id "
                  "WHERE Customers.id = :id;");
    chart_query.bindValue(":id", id);
    if(!chart_query.exec() || !chart_query.next()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo fault!!!: " << chart_query.lastError();
        return;
    }

    tariff_chart->setQuery(std::move(chart_query), "name", "id");
}
