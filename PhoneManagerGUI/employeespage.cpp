#include "employeespage.h"
#include "ui_employeespage.h"

#include "buttonsshadowmanager.h"

EmployeesPage::EmployeesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesPage)
{
    ui->setupUi(this);

    ButtonsShadowManager::setSideBarButtonsShadow({
                                       ui->dashboard_btn,
                                       ui->customers_btn,
                                       ui->employees_btn,
                                       ui->tariffs_btn,
                                       ui->requests_btn,
                                       ui->log_out_btn
    });
}

EmployeesPage::~EmployeesPage()
{
    delete ui;
}
