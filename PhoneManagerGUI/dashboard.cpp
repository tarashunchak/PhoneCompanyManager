#include "dashboard.h"
#include "ui_dashboard.h"

#include <QSqlQuery>
#include <QSqlError>
#include "databasemanager.h"
#include "buttonsstylemanager.h"
#include "currentuser.h"

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
    , db(&DatabaseManager::instance().getDatabase())
    , qmodel(new QSqlQueryModel(this))
    , cust_chart_view(new QChartView)
    , req_chart_view(new QChartView)

{
    ui->setupUi(this);

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });
    setTableViewConnection();
    setCustomersStatictics();
    setRequestsStatictics();

}

Dashboard::~Dashboard()
{
    db = nullptr;
    delete ui;
}

void Dashboard::setCurrentUser(){
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

void Dashboard::setTableViewConnection(){
    qmodel->setQuery("SELECT *FROM Customers ORDER BY registration_date DESC LIMIT 10;");
    ui->tableView->setModel(qmodel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->verticalHeader()->setVisible(false);
}
