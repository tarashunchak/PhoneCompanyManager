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
    void on_dashboard_btn_clicked();
    void on_customers_btn_clicked();
    void on_employees_btn_clicked();
    void on_tariffs_btn_clicked();
    void on_requests_btn_clicked();
    void on_log_out_btn_clicked();

private:/*Methods*/
    void FindEmployeesByName();

private:
    Ui::EmployeesPage *ui;

    QSqlDatabase* db;

};

#endif // EMPLOYEESPAGE_H
