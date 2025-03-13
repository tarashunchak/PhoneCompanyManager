#include "navigationmanager.h"

NavigationManager::NavigationManager(QStackedWidget* widget, QObject* parent)
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

    sWidget->setCurrentWidget(loginPage);

    setUpNavigation();

}


void NavigationManager::setUpNavigation(){

    //Dashboard Page Signals/Slots connections
    connect(dashboardPage, &Dashboard::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(dashboardPage, &Dashboard::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(dashboardPage, &Dashboard::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(dashboardPage, &Dashboard::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(dashboardPage, &Dashboard::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);

    //Customers Page Signals/Slots connections
    connect(customersPage, &CustomersPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(customersPage, &CustomersPage::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(customersPage, &CustomersPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(customersPage, &CustomersPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);

    //Employees Page Signals/Slots connections
    connect(employeesPage, &EmployeesPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(employeesPage, &EmployeesPage::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(employeesPage, &EmployeesPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(employeesPage, &EmployeesPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);

    //Tariffs Page Signals/Slots connections
    connect(tariffsPage, &TariffsPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(tariffsPage, &TariffsPage::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(tariffsPage, &TariffsPage::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(tariffsPage, &TariffsPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(tariffsPage, &TariffsPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);

    //Requests Page Signals/Slots connections
    connect(requestsPage, &RequestsPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(requestsPage, &RequestsPage::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(requestsPage, &RequestsPage::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(requestsPage, &RequestsPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(requestsPage, &RequestsPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);

}

void NavigationManager::showLoginPage()const{
    sWidget->setCurrentWidget(loginPage);
}

void NavigationManager::showDashboardPage()const{
    sWidget->setCurrentWidget(dashboardPage);
}

void NavigationManager::showCustomersPage()const{
    sWidget->setCurrentWidget(customersPage);
}

void NavigationManager::showEmployeesPage()const{
    sWidget->setCurrentWidget(employeesPage);
}

void NavigationManager::showTariffsPage()const{
    tariffsPage->SetTariffsCards();
    sWidget->setCurrentWidget(tariffsPage);
}

void NavigationManager::showRequestsPage()const{
    sWidget->setCurrentWidget(requestsPage);
}
