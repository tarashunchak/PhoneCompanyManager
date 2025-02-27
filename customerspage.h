#ifndef CUSTOMERSPAGE_H
#define CUSTOMERSPAGE_H

#include <QWidget>

namespace Ui {
class CustomersPage;
}

class CustomersPage : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersPage(QWidget *parent = nullptr);
    ~CustomersPage();

signals:
    void on_dashboard_btn_clicked();
    void on_employees_btn_clicked();

private:
    Ui::CustomersPage *ui;
};

#endif // CUSTOMERSPAGE_H
