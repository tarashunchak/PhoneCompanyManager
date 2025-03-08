#include "buttonslogicmanager.h"

ButtonsLogicManager::ButtonsLogicManager(QStackedWidget* widget, QObject* parent)
    : QObject(parent)
    , sWidget(widget)
    , loginPage(new LoginPage)
    , dashboardPage(new Dashboard())
    , customersPage(new CustomersPage())
    , employeesPage(new EmployeesPage())
    , tariffsPage(new TariffsPage())
    , requestsPage(new RequestsPage())

{

    sWidget->addWidget(loginPage);
    sWidget->addWidget(dashboardPage);
    sWidget->addWidget(customersPage);
    sWidget->addWidget(employeesPage);
    sWidget->addWidget(tariffsPage);
    sWidget->addWidget(requestsPage);

    sWidget->setCurrentWidget(dashboardPage);

    setUpNavigation();

}


void ButtonsLogicManager::setUpNavigation(){

    //Dashboard Page Signals/Slots connections
    connect(dashboardPage, &Dashboard::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);
    connect(dashboardPage, &Dashboard::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);
    connect(dashboardPage, &Dashboard::on_tariffs_btn_clicked, this, &ButtonsLogicManager::showTariffsPage);
    connect(dashboardPage, &Dashboard::on_requests_btn_clicked, this, &ButtonsLogicManager::showRequestsPage);

    //Customers Page Signals/Slots connections
    connect(customersPage, &CustomersPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(customersPage, &CustomersPage::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);
    connect(customersPage, &CustomersPage::on_tariffs_btn_clicked, this, &ButtonsLogicManager::showTariffsPage);
    connect(customersPage, &CustomersPage::on_requests_btn_clicked, this, &ButtonsLogicManager::showRequestsPage);

    //Employees Page Signals/Slots connections
    connect(employeesPage, &EmployeesPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(employeesPage, &EmployeesPage::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);
    connect(employeesPage, &EmployeesPage::on_tariffs_btn_clicked, this, &ButtonsLogicManager::showTariffsPage);
    connect(employeesPage, &EmployeesPage::on_requests_btn_clicked, this, &ButtonsLogicManager::showRequestsPage);

    //Tariffs Page Signals/Slots connections
    connect(tariffsPage, &TariffsPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(tariffsPage, &TariffsPage::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);
    connect(tariffsPage, &TariffsPage::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);
    connect(tariffsPage, &TariffsPage::on_tariffs_btn_clicked, this, &ButtonsLogicManager::showTariffsPage);
    connect(tariffsPage, &TariffsPage::on_requests_btn_clicked, this, &ButtonsLogicManager::showRequestsPage);

    //Requests Page Signals/Slots connections
    connect(requestsPage, &RequestsPage::on_dashboard_btn_clicked, this, &ButtonsLogicManager::showDashboardPage);
    connect(requestsPage, &RequestsPage::on_customers_btn_clicked, this, &ButtonsLogicManager::showCustomersPage);
    connect(requestsPage, &RequestsPage::on_employees_btn_clicked, this, &ButtonsLogicManager::showEmployeesPage);
    connect(requestsPage, &RequestsPage::on_tariffs_btn_clicked, this, &ButtonsLogicManager::showTariffsPage);
    connect(requestsPage, &RequestsPage::on_requests_btn_clicked, this, &ButtonsLogicManager::showRequestsPage);

}


void ButtonsLogicManager::showDashboardPage()const{
    sWidget->setCurrentWidget(dashboardPage);
}

void ButtonsLogicManager::showCustomersPage()const{
    sWidget->setCurrentWidget(customersPage);
}

void ButtonsLogicManager::showEmployeesPage()const{
    sWidget->setCurrentWidget(employeesPage);
}

void ButtonsLogicManager::showTariffsPage()const{
    tariffsPage->SetTariffsCards();
    sWidget->setCurrentWidget(tariffsPage);
}

void ButtonsLogicManager::showRequestsPage()const{
    sWidget->setCurrentWidget(requestsPage);
}
