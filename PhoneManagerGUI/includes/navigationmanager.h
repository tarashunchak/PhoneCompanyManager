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

class NavigationManager: public QObject
{
    Q_OBJECT
public:
    NavigationManager(QStackedWidget*, QObject*, QWidget*);
    ~NavigationManager();

public slots:
    void showLoginPage()const;
    void showRegistrationPage()const;
    void showPasswordRecoveryPage()const;
    void showDashboardPage()const;
    void showCustomersPage()const;
    void showEmployeesPage()const;
    void showTariffsPage()const;
    void showRequestsPage()const;
    void showCustomersDetailsPage(const int)const;

private: /*Methods*/
    void setUpNavigation();

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
    QWidget* left_side_menu;
};

#endif //
