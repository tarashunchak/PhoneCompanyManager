#include "dashboard.h"
#include "ui_dashboard.h"

#include "databasemanager.h"

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
    , db(&DatabaseManager::instance().getDatabase())
    , qmodel(new QSqlQueryModel(this))

{
    ui->setupUi(this);

    ui->dashboard_btn->setIcon(QIcon("./img/dashboards.png"));
    ui->customers_btn->setIcon(QIcon("./img/customers.png"));
    ui->employees_btn->setIcon(QIcon("./img/employee.png"));
    ui->tariffs_btn->setIcon(QIcon("./img/tariffs.png"));
    ui->requests_btn->setIcon(QIcon("./img/requests.png"));

    setTableViewConnection();

}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::setTableViewConnection(){
    qmodel->setQuery("SELECT *FROM Customers ORDER BY registration_date DESC LIMIT 10;");
    ui->tableView->setModel(qmodel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->verticalHeader()->setVisible(false);
}
