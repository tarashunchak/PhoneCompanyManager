#include "employeesdetailspage.h"
#include "ui_employeesdetailspage.h"

EmployeeDetailsPage::EmployeeDetailsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeeDetailsPage)
{
    ui->setupUi(this);
}

EmployeeDetailsPage::~EmployeeDetailsPage()
{
    delete ui;
}
