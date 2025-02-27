#ifndef BUTTONSLOGICMANAGER_H
#define BUTTONSLOGICMANAGER_H

#include <QObject>
#include <QStackedWidget>

#include "dashboard.h"
#include "customerspage.h"
#include "employeespage.h"

class ButtonsLogicManager : public QObject
{
    Q_OBJECT
public:
    ButtonsLogicManager(QStackedWidget*, QObject*);

public slots:
    void showDashboardPage()const;
    void showCustomersPage()const;
    void showEmployeesPage()const;

private: /*Functions*/
    void setUpNavigation();

private:
    QStackedWidget* sWidget;

    Dashboard* dashboard;
    CustomersPage* customersP;
    EmployeesPage* employeesP;

};

#endif // BUTTONSLOGICMANAGER_H
