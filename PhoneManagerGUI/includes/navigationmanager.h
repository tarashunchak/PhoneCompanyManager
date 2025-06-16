#ifndef NAVIGATION_MANAGER_H
#define NAVIGATION_MANAGER_H

#include <QObject>
#include <QStackedWidget>

#include "loginpage.h"
#include "registrationpage.h"
#include "passwordrecoverypage.h"
#include "dashboard.h"
#include "customerspage.h"
#include "employeespage.h"
#include "tariffspage.h"
#include "requestspage.h"
#include "customersdetailspage.h"
#include "employeeschatpage.h"
#include "employeesdetailspage.h"

class NavigationManager: public QObject
{
    Q_OBJECT
public:
    NavigationManager(QStackedWidget*, QObject*, QWidget*);
    ~NavigationManager() = default;
    static bool is_chat_page;

public slots:
    void showLoginPage()const;
    void showRegistrationPage()const;
    void showPasswordRecoveryPage()const;
    void showDashboardPage()const;
    void showCustomersPage()const;
    void showEmployeesPage()const;
    void showTariffsPage()const;
    void showRequestsPage()const;
    void showCustomersDetailsPage(const uint)const;
    void showChatsPage()const;
    void showEmployeesDetailsPage(const uint)const;

private: /*Methods*/
    void setUpNavigation();

signals:
    void show_small_buttons()const;
    void hide_small_buttons()const;
    void open_chat(const QString&);
    void notify_employee()const;
    void hide_notifying_circle()const;

private:
    QStackedWidget* sWidget;

    LoginPage* loginPage;
    RegistrationPage* registrationPage;
    PasswordRecoveryPage* passwordRecoveryPage;
    Dashboard* dashboardPage;
    CustomersPage* customersPage;
    EmployeesPage* employeesPage;
    TariffsPage* tariffsPage;
    RequestsPage* requestsPage;
    CustomersDetailsPage* customersDetailsPage;
    EmployeesChatPage* employeesChatPage;
    EmployeesDetailsPage* employeesDetailsPage;
    QWidget* left_side_menu;
};

#endif //
