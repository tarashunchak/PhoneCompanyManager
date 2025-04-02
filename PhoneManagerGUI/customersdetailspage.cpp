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
{
    ui->setupUi(this);

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });

}

CustomersDetailsPage::~CustomersDetailsPage()
{
    db = nullptr;
    delete ui;
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
    query.clear();
    query.prepare("SELECT *FROM Usage WHERE cust_id = :id;");
    query.bindValue(":id", id);

    if(!query.exec() || !query.next()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo fault!!!: " << query.lastError();
        return;
    }

    qmodel->setQuery(std::move(query));

    ui->tableView->setModel(qmodel);

}
