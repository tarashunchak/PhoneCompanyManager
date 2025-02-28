#include "buttonslogicmanager.h"

ButtonsLogicManager::ButtonsLogicManager(QStackedWidget* widget, QObject* parent)
    : QObject(parent)
    , sWidget(widget)
    , dashboard(new Dashboard())
    , customersP(new CustomersPage())
    , employeesP(new EmployeesPage())
    , tariffsP(new TariffsPage())

{

    sWidget->addWidget(dashboard);
    sWidget->addWidget(customersP);
    sWidget->addWidget(employeesP);
    sWidget->addWidget(tariffsP);

    sWidget->setCurrentWidget(dashboard);

    setUpNavigation();

}


void ButtonsLogicManager::setUpNavigation(){

    //Dashboard Page Signals
    connect(dashboard, &Dashboard::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);
    connect(dashboard, &Dashboard::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);
    connect(dashboard, &Dashboard::on_tariffs_btn_clicked, this, &ButtonsLogicManager::showTariffsPage);

    //Customers Page Signals
    connect(customersP, &CustomersPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(customersP, &CustomersPage::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);
    connect(customersP, &CustomersPage::on_tariffs_btn_clicked, this, &ButtonsLogicManager::showTariffsPage);

    //Employees Page Signals
    connect(employeesP, &EmployeesPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(employeesP, &EmployeesPage::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);
    connect(employeesP, &EmployeesPage::on_tariffs_btn_clicked, this, &ButtonsLogicManager::showTariffsPage);

    //Tariffs Page Signals
    connect(tariffsP, &TariffsPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(tariffsP, &TariffsPage::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);
    connect(tariffsP, &TariffsPage::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);

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

void ButtonsLogicManager::showTariffsPage()const{
    sWidget->setCurrentWidget(tariffsP);
}
