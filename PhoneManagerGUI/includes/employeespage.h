#ifndef EMPLOYEESPAGE_H
#define EMPLOYEESPAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "insertemployeedialog.h"
#include <QPropertyAnimation>

namespace Ui {
class EmployeesPage;
}

class EmployeesPage : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesPage(QWidget *parent = nullptr);
    ~EmployeesPage();
    void SetEmployeesCards(QSqlQuery query = QSqlQuery(QSqlDatabase::database("remote")));

signals:
    void employee_selected(const uint);

public slots:
    void setCurrentUser()const;

private:/*Methods*/
    void FindEmployeesByName();
    void SetConnections();

private:
    Ui::EmployeesPage *ui;

    QSqlDatabase* db;
    InsertEmployeeDialog* insert_employee_dialog;
};

#endif // EMPLOYEESPAGE_H
