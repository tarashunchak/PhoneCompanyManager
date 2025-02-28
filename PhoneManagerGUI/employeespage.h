#ifndef EMPLOYEESPAGE_H
#define EMPLOYEESPAGE_H

#include <QWidget>

namespace Ui {
class EmployeesPage;
}

class EmployeesPage : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesPage(QWidget *parent = nullptr);
    ~EmployeesPage();

signals:
    void on_dashboard_btn_clicked();
    void on_customers_btn_clicked();

private:/*Methods*/
    void SetEmployeesCards();
    void FindEmployeesByName();

private:
    Ui::EmployeesPage *ui;
};

#endif // EMPLOYEESPAGE_H
