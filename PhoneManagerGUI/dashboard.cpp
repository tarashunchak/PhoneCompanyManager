#include "dashboard.h"
#include "ui_dashboard.h"

#include "databasemanager.h"
#include "buttonsstylemanager.h"

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
    , db(&DatabaseManager::instance().getDatabase())
    , qmodel(new QSqlQueryModel(this))

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
