#include "includes/navigationmanager.h"
#include "includes/currentuser.h"

NavigationManager::NavigationManager(QStackedWidget* sWidget, QObject* parent, QWidget* side_menu)
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
    , left_side_menu(side_menu)
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

NavigationManager::~NavigationManager(){
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

    //Customers Page Signals/Slots connections
    connect(customersPage, &CustomersPage::customer_selected, this, &NavigationManager::showCustomersDetailsPage);

    //Customers Details Page Signals/Slots connections
    connect(customersDetailsPage, &CustomersDetailsPage::on_return_btn_clicked, this, &NavigationManager::showCustomersPage);

    //Employees Page Signals/Slots connections

    //Requests Page Signals/Slots connections
}

static void hide_side_menu(QWidget* menu, QStackedWidget* sWidget){
    sWidget->setGeometry(0, 0, 1920, 1080);
    menu->setVisible(false);
}

static void show_side_menu(QWidget* menu, QStackedWidget* sWidget){
    sWidget->setGeometry(250, 0, 1670, 1080);
    menu->setVisible(true);
}

void NavigationManager::showLoginPage()const{
    hide_side_menu(left_side_menu, sWidget);
    CurrentUser::setCurrentUserID(0);
    sWidget->setCurrentWidget(loginPage);
}

void NavigationManager::showDashboardPage()const{
    show_side_menu(left_side_menu, sWidget);
    dashboardPage->setCurrentUser();
    dashboardPage->setCustomersStatistics();
    dashboardPage->setRequestsStatistics();
    sWidget->setCurrentWidget(dashboardPage);
}

void NavigationManager::showCustomersPage()const{
    show_side_menu(left_side_menu, sWidget);
    customersPage->SetCustomersCards();
    sWidget->setCurrentWidget(customersPage);
}

void NavigationManager::showEmployeesPage()const{
    show_side_menu(left_side_menu, sWidget);
    employeesPage->SetEmployeesCards();
    sWidget->setCurrentWidget(employeesPage);
}

void NavigationManager::showTariffsPage()const{
    show_side_menu(left_side_menu, sWidget);
    tariffsPage->setCurrentUser();
    tariffsPage->setTariffsCards();
    sWidget->setCurrentWidget(tariffsPage);
}

void NavigationManager::showRequestsPage()const{
    show_side_menu(left_side_menu, sWidget);
    requestsPage->setCurrentUser();
    requestsPage->setTableView();
    sWidget->setCurrentWidget(requestsPage);
}

void NavigationManager::showRegistrationPage()const{
    hide_side_menu(left_side_menu, sWidget);
    sWidget->setCurrentWidget(registrationPage);
}

void NavigationManager::showCustomersDetailsPage(const int id)const{
    show_side_menu(left_side_menu, sWidget);
    customersDetailsPage->setCurrentUser();
    customersDetailsPage->SetCustomerInfo(id);
    sWidget->setCurrentWidget(customersDetailsPage);
}

void NavigationManager::showPasswordRecoveryPage()const{
    hide_side_menu(left_side_menu, sWidget);
    sWidget->setCurrentWidget(passwordRecoveryPage);
}
