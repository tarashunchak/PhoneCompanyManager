#include "employeespage.h"
#include "ui_employeespage.h"

EmployeesPage::EmployeesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesPage)
{
    ui->setupUi(this);

    ui->dashboard_btn->setIcon(QIcon("./img/dashboards.png"));
    ui->customers_btn->setIcon(QIcon("./img/customers.png"));
    ui->employees_btn->setIcon(QIcon("./img/employee.png"));
    ui->tariffs_btn->setIcon(QIcon("./img/tariffs.png"));
    ui->requests_btn->setIcon(QIcon("./img/requests.png"));
}

EmployeesPage::~EmployeesPage()
{
    delete ui;
}

void EmployeesPage::SetEmployeesCards(){

}
