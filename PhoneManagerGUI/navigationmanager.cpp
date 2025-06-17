#include "includes/navigationmanager.h"
#include "includes/currentuser.h"
#include "includes/buttonsstylemanager.h"

static void hide_side_menu(QWidget* menu, QStackedWidget* sWidget){
    sWidget->setGeometry(0, 0, 1920, 1080);
    menu->setVisible(false);
}

static void show_side_menu(QWidget* menu, QStackedWidget* sWidget){
    sWidget->setGeometry(250, 0, 1670, 1080);
    menu->setVisible(true);
}

NavigationManager::NavigationManager(QStackedWidget* sWidget
                                     , QObject* parent, QWidget* side_menu)
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
    , employeesChatPage(new EmployeesChatPage{})
    , employeesDetailsPage(new EmployeesDetailsPage{})
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
    sWidget->addWidget(employeesChatPage);
    sWidget->addWidget(employeesDetailsPage);

    sWidget->setCurrentWidget(loginPage);
    setUpNavigation();
}

bool NavigationManager::is_chat_page = false;

void NavigationManager::setUpNavigation(){
    //Login Page Signals/Slots connections
    connect(loginPage, &LoginPage::login_succsess
            , this, &NavigationManager::showDashboardPage);
    connect(loginPage, &LoginPage::on_registration_btn_clicked
            , this, &NavigationManager::showRegistrationPage);
    connect(loginPage, &LoginPage::on_pass_rec_btn_clicked
            , this, &NavigationManager::showPasswordRecoveryPage);

    //RegistrationPage Signals/Slots connections
    connect(registrationPage, &RegistrationPage::successful_registration
            , this, &NavigationManager::showLoginPage);
    connect(registrationPage, &RegistrationPage::on_return_to_login_btn_clicked
            , this, &NavigationManager::showLoginPage);

    //PasswordRecoveryPage Signals/Slots connections
    connect(passwordRecoveryPage, &PasswordRecoveryPage::on_return_to_login_btn_clicked
            , this, &NavigationManager::showLoginPage);

    //Customers Page Signals/Slots connections
    connect(customersPage, &CustomersPage::customer_selected
            , this, &NavigationManager::showCustomersDetailsPage);
    connect(customersPage, &CustomersPage::on_close_open_filter_btn_clicked
            , this, [this](){
        static bool flag = true;
        if(flag)
            emit hide_small_buttons();
        else
            emit show_small_buttons();
        flag = !flag;
    });

    //Customers Details Page Signals/Slots connections
    connect(customersDetailsPage, &CustomersDetailsPage::on_return_btn_clicked
            , this, &NavigationManager::showCustomersPage);
    connect(customersDetailsPage, &CustomersDetailsPage::on_open_chat_btn_clicked
            , this, [this](const QString& phone)
    {
        emit open_chat(phone);
    });

    //Employees Page Signals/Slots connections
    connect(employeesPage, &EmployeesPage::employee_selected
            , this, &NavigationManager::showEmployeesDetailsPage);

    //Employees Details Page Signals/Slots connections
    connect(employeesDetailsPage, &EmployeesDetailsPage::on_return_btn_clicked
            , this, &NavigationManager::showEmployeesPage);

    //Requests Page Signals/Slots connections
    connect(employeesChatPage, &EmployeesChatPage::on_partner_profile_pic_btn_clicked
            , this, &NavigationManager::showEmployeesDetailsPage);
    connect(employeesChatPage, &EmployeesChatPage::notify_employee, this, [this](){
        emit notify_employee();
    });
}

void NavigationManager::showLoginPage()const{
    QSqlQuery query(QSqlDatabase::database("remote"));
    query.prepare("UPDATE users "
                  "SET is_online = false "
                  "WHERE id = ?;");
    query.addBindValue(CurrentUser::getCurrentUserID());
    query.exec();
    hide_side_menu(left_side_menu, sWidget);
    CurrentUser::setCurrentUserID(-1);
    employeesChatPage->closeCurrentChat();
    sWidget->setCurrentWidget(loginPage);
    emit hide_small_buttons();
}

void NavigationManager::showDashboardPage()const{
    is_chat_page = false;
    ButtonsStyleManager::SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::DASHBOARD_BTN);
    show_side_menu(left_side_menu, sWidget);
    dashboardPage->setCustomersStatistics();
    dashboardPage->setRequestsStatistics();
    sWidget->setCurrentWidget(dashboardPage);
    emit show_small_buttons();
}

void NavigationManager::showCustomersPage()const{
    is_chat_page = false;
    ButtonsStyleManager::SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::CUSTOMERS_BTN);
    customersPage->SetCustomersCards();
    customersPage->updateFilterWidgets();
    customersPage->close_filter_widget();
    sWidget->setCurrentWidget(customersPage);
}

void NavigationManager::showEmployeesPage()const{
    is_chat_page = false;
    ButtonsStyleManager::SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::EMPLOYEES_BTN);
    employeesPage->SetEmployeesCards();
    employeesPage->setCurrentUser();
    sWidget->setCurrentWidget(employeesPage);
}

void NavigationManager::showTariffsPage()const{
    is_chat_page = false;
    ButtonsStyleManager::SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::TARIFFS_BTN);
    tariffsPage->setCurrentUser();
    tariffsPage->setTariffsCards();
    sWidget->setCurrentWidget(tariffsPage);
}

void NavigationManager::showRequestsPage()const{
    is_chat_page = false;
    ButtonsStyleManager::SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::REQUESTS_BTN);
    requestsPage->showUnassignmentRequests();
    sWidget->setCurrentWidget(requestsPage);
}

void NavigationManager::showRegistrationPage()const{
    hide_side_menu(left_side_menu, sWidget);
    sWidget->setCurrentWidget(registrationPage);
}

void NavigationManager::showCustomersDetailsPage(const uint id)const{
    is_chat_page = false;
    ButtonsStyleManager::SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::CUSTOMERS_BTN);
    customersDetailsPage->SetCustomerInfo(id);
    sWidget->setCurrentWidget(customersDetailsPage);
}

void NavigationManager::showChatsPage()const{
    is_chat_page = true;
    emit notify_employee();
    ButtonsStyleManager::SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::CHATS_BTN);
    show_side_menu(left_side_menu, sWidget);
    employeesChatPage->fillChatsWidget();
    sWidget->setCurrentWidget(employeesChatPage);
}

void NavigationManager::showPasswordRecoveryPage()const{
    hide_side_menu(left_side_menu, sWidget);
    sWidget->setCurrentWidget(passwordRecoveryPage);
}

void NavigationManager::showEmployeesDetailsPage(const uint id)const{
    is_chat_page = false;
    employeesDetailsPage->SetEmployeeInfo(id);
    sWidget->setCurrentWidget(employeesDetailsPage);
}
