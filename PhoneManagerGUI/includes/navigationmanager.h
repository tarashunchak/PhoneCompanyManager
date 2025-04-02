#ifndef NAVIGATION_MANAGER_H
#define NAVIGATION_MANAGER_H

#include <QObject>
#include <QStackedWidget>

#include "loginpage.h"
#include "dashboard.h"
#include "customerspage.h"
#include "employeespage.h"
#include "tariffspage.h"
#include "requestspage.h"
#include "registrationpage.h"
#include "customersdetailspage.h"

class NavigationManager: public QObject
{
    Q_OBJECT
public:
    NavigationManager(QStackedWidget*, QObject*);

private slots:
    void showLoginPage()const;
    void showDashboardPage()const;
    void showCustomersPage()const;
    void showEmployeesPage()const;
    void showTariffsPage()const;
    void showRequestsPage()const;
    void showRegistrationPage()const;
    void showCustomersDetailsPage(const int)const;

private: /*Methods*/
    void setUpNavigation();

private:
    QStackedWidget* sWidget;

    LoginPage* loginPage;
    Dashboard* dashboardPage;
    CustomersPage* customersPage;
    EmployeesPage* employeesPage;
    TariffsPage* tariffsPage;
    RequestsPage* requestsPage;
    RegistrationPage* registrationPage;
    CustomersDetailsPage* customersDetailsPage;

};

#endif //
