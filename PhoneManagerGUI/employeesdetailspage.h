#ifndef EMPLOYEESDETAILSPAGE_H
#define EMPLOYEESDETAILSPAGE_H

#include <QWidget>

namespace Ui {
class EmployeeDetailsPage;
}

class EmployeesDetailsPage : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesDetailsPage(QWidget *parent = nullptr);
    ~EmployeesDetailsPage();
    struct CurrentEmployee{
        static QString id;
        static QString first_name;
        static QString last_name;
        static QString department_id;
        static QString department_name;
        static QString position_id;
        static QString position_name;
        static QString hire_date;
        static QString salary;
        static QString phone;
        static QString email;
        //static QPixmap photo;
        static QString is_active;
        static QString date_of_B;
        static QString comment_text;
        static QString comment_id;
    };

public slots:
    void SetEmployeeInfo(const uint);

signals:
    void on_return_btn_clicked();

private:
    void SetConnections();

private:
    Ui::EmployeeDetailsPage *ui;
};

#endif // EMPLOYEESDETAILSPAGE_H
