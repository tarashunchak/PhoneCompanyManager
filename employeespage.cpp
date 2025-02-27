#include "employeespage.h"
#include "ui_employeespage.h"

EmployeesPage::EmployeesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesPage)
{
    ui->setupUi(this);
}

EmployeesPage::~EmployeesPage()
{
    delete ui;
}
