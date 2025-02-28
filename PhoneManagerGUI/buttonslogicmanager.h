#ifndef BUTTONSLOGICMANAGER_H
#define BUTTONSLOGICMANAGER_H

#include <QObject>
#include <QStackedWidget>

#include "dashboard.h"
#include "customerspage.h"
#include "employeespage.h"
#include "tariffspage.h"

class ButtonsLogicManager : public QObject
{
    Q_OBJECT
public:
    ButtonsLogicManager(QStackedWidget*, QObject*);

public slots:
    void showDashboardPage()const;
    void showCustomersPage()const;
    void showEmployeesPage()const;
    void showTariffsPage()const;

private: /*Methods*/
    void setUpNavigation();

private:
    QStackedWidget* sWidget;

    Dashboard* dashboard;
    CustomersPage* customersP;
    EmployeesPage* employeesP;
    TariffsPage* tariffsP;

};

#endif // BUTTONSLOGICMANAGER_H
