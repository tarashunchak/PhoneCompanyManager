#ifndef EMPLOYEESDETAILSPAGE_H
#define EMPLOYEESDETAILSPAGE_H

#include <QWidget>

namespace Ui {
class EmployeeDetailsPage;
}

class EmployeeDetailsPage : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeDetailsPage(QWidget *parent = nullptr);
    ~EmployeeDetailsPage();

private:
    Ui::EmployeeDetailsPage *ui;
};

#endif // EMPLOYEESDETAILSPAGE_H
