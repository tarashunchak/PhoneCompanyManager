#ifndef EMPLOYEESPAGE_H
#define EMPLOYEESPAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class EmployeesPage;
}

class EmployeesPage : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesPage(QWidget *parent = nullptr);
    ~EmployeesPage();
    void SetEmployeesCards(QSqlQuery query = QSqlQuery());

signals:

private:/*Methods*/
    void FindEmployeesByName();
    void SetConnections();

private:
    Ui::EmployeesPage *ui;

    QSqlDatabase* db;

};

#endif // EMPLOYEESPAGE_H
