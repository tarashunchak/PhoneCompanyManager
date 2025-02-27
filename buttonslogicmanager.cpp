#include "buttonslogicmanager.h"

ButtonsLogicManager::ButtonsLogicManager(QStackedWidget* widget, QObject* parent)
    : QObject(parent)
    , sWidget(widget)
    , dashboard(new Dashboard())
    , customersP(new CustomersPage())
    , employeesP(new EmployeesPage())

{

    sWidget->addWidget(dashboard);
    sWidget->addWidget(customersP);
    sWidget->addWidget(employeesP);

    sWidget->setCurrentWidget(dashboard);

    setUpNavigation();

}


void ButtonsLogicManager::setUpNavigation(){

    //Dashboard Page Signals
    connect(dashboard, &Dashboard::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);
    connect(dashboard, &Dashboard::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);

    //Customers Page Signals
    connect(customersP, &CustomersPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(customersP, &CustomersPage::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);

    //Employees Page Signals
    connect(employeesP, &EmployeesPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(employeesP, &EmployeesPage::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);

}


void ButtonsLogicManager::showDashboardPage()const{
    sWidget->setCurrentWidget(dashboard);
}

void ButtonsLogicManager::showCustomersPage()const{
    sWidget->setCurrentWidget(customersP);
}

void ButtonsLogicManager::showEmployeesPage()const{
    sWidget->setCurrentWidget(employeesP);
}
