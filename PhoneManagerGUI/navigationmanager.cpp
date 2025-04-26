#include "includes/navigationmanager.h"
#include "includes/currentuser.h"

NavigationManager::NavigationManager(QStackedWidget* sWidget, QObject* parent)
    : QObject(parent)
    , sWidget(sWidget)
    , loginPage(new LoginPage{})
    , registrationPage(new RegistrationPage{})
    , passwordRecoveryPage(new PasswordRecoveryPage{})
    , dashboardPage(new Dashboard{})
    , customersPage(new CustomersPage{})
    , employeesPage(new EmployeesPage{})
    , tariffsPage(new TariffsPage{})
    , requestsPage(new RequestsPage{})
    , customersDetailsPage(new CustomersDetailsPage{})

{

    sWidget->addWidget(loginPage);
    sWidget->addWidget(registrationPage);
    sWidget->addWidget(passwordRecoveryPage);
    sWidget->addWidget(dashboardPage);
    sWidget->addWidget(customersPage);
    sWidget->addWidget(employeesPage);
    sWidget->addWidget(tariffsPage);
    sWidget->addWidget(requestsPage);
    sWidget->addWidget(customersDetailsPage);

    sWidget->setCurrentWidget(loginPage);

    setUpNavigation();

}

void NavigationManager::setUpNavigation(){

    //Login Page Signals/Slots connections
    connect(loginPage, &LoginPage::login_succsess, this, &NavigationManager::showDashboardPage);
    connect(loginPage, &LoginPage::on_registration_btn_clicked, this, &NavigationManager::showRegistrationPage);
    connect(loginPage, &LoginPage::on_pass_rec_btn_clicked, this, &NavigationManager::showPasswordRecoveryPage);

    //RegistrationPage Signals/Slots connections
    connect(registrationPage, &RegistrationPage::successful_registration, this, &NavigationManager::showLoginPage);
    connect(registrationPage, &RegistrationPage::on_return_to_login_btn_clicked, this, &NavigationManager::showLoginPage);

    //PasswordRecoveryPage Signals/Slots connections
    connect(passwordRecoveryPage, &PasswordRecoveryPage::on_return_to_login_btn_clicked, this, &NavigationManager::showLoginPage);

    //Dashboard Page Signals/Slots connections
    connect(dashboardPage, &Dashboard::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(dashboardPage, &Dashboard::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(dashboardPage, &Dashboard::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(dashboardPage, &Dashboard::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(dashboardPage, &Dashboard::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);
    connect(dashboardPage, &Dashboard::on_log_out_btn_clicked, this, &NavigationManager::showLoginPage);

    //Customers Page Signals/Slots connections
    connect(customersPage, &CustomersPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(customersPage, &CustomersPage::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(customersPage, &CustomersPage::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(customersPage, &CustomersPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(customersPage, &CustomersPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);
    connect(customersPage, &CustomersPage::on_log_out_btn_clicked, this, &NavigationManager::showLoginPage);
    connect(customersPage, &CustomersPage::customer_selected, this, &NavigationManager::showCustomersDetailsPage);

    //Customers Details Page Signals/Slots connections
    connect(customersDetailsPage, &CustomersDetailsPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(customersDetailsPage, &CustomersDetailsPage::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(customersDetailsPage, &CustomersDetailsPage::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(customersDetailsPage, &CustomersDetailsPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(customersDetailsPage, &CustomersDetailsPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);
    connect(customersDetailsPage, &CustomersDetailsPage::on_log_out_btn_clicked, this, &NavigationManager::showLoginPage);
    connect(customersDetailsPage, &CustomersDetailsPage::on_return_btn_clicked, this, &NavigationManager::showCustomersPage);

    //Employees Page Signals/Slots connections
    connect(employeesPage, &EmployeesPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(employeesPage, &EmployeesPage::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(employeesPage, &EmployeesPage::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(employeesPage, &EmployeesPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(employeesPage, &EmployeesPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);
    connect(employeesPage, &EmployeesPage::on_log_out_btn_clicked, this, &NavigationManager::showLoginPage);

    //Tariffs Page Signals/Slots connections
    connect(tariffsPage, &TariffsPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(tariffsPage, &TariffsPage::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(tariffsPage, &TariffsPage::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(tariffsPage, &TariffsPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(tariffsPage, &TariffsPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);
    connect(tariffsPage, &TariffsPage::on_log_out_btn_clicked, this, &NavigationManager::showLoginPage);

    //Requests Page Signals/Slots connections
    connect(requestsPage, &RequestsPage::on_dashboard_btn_clicked, this, &NavigationManager::showDashboardPage);
    connect(requestsPage, &RequestsPage::on_customers_btn_clicked, this, &NavigationManager::showCustomersPage);
    connect(requestsPage, &RequestsPage::on_employees_btn_clicked, this, &NavigationManager::showEmployeesPage);
    connect(requestsPage, &RequestsPage::on_tariffs_btn_clicked, this, &NavigationManager::showTariffsPage);
    connect(requestsPage, &RequestsPage::on_requests_btn_clicked, this, &NavigationManager::showRequestsPage);
    connect(requestsPage, &RequestsPage::on_log_out_btn_clicked, this, &NavigationManager::showLoginPage);

}

void NavigationManager::showLoginPage()const{
    CurrentUser::setCurrentUserID(0);
    sWidget->setCurrentWidget(loginPage);
}

void NavigationManager::showDashboardPage()const{
    dashboardPage->setCurrentUser();
    dashboardPage->setCustomersStatistics();
    dashboardPage->setRequestsStatistics();
    sWidget->setCurrentWidget(dashboardPage);
}

void NavigationManager::showCustomersPage()const{
    customersPage->SetCustomersCards();
    sWidget->setCurrentWidget(customersPage);
}

void NavigationManager::showEmployeesPage()const{
    employeesPage->SetEmployeesCards();
    sWidget->setCurrentWidget(employeesPage);
}

void NavigationManager::showTariffsPage()const{
    tariffsPage->setCurrentUser();
    tariffsPage->setTariffsCards();
    sWidget->setCurrentWidget(tariffsPage);
}

void NavigationManager::showRequestsPage()const{
    requestsPage->setCurrentUser();
    requestsPage->setTableView();
    sWidget->setCurrentWidget(requestsPage);
}

void NavigationManager::showRegistrationPage()const{
    sWidget->setCurrentWidget(registrationPage);
}

void NavigationManager::showCustomersDetailsPage(const int id)const{
    customersDetailsPage->setCurrentUser();
    customersDetailsPage->SetCustomerInfo(id);
    sWidget->setCurrentWidget(customersDetailsPage);
}

void NavigationManager::showPasswordRecoveryPage()const{
    sWidget->setCurrentWidget(passwordRecoveryPage);
}
