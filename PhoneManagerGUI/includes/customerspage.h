#ifndef CUSTOMERSPAGE_H
#define CUSTOMERSPAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class CustomersPage;
}

class CustomersPage : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersPage(QWidget *parent = nullptr);
    ~CustomersPage();
    void SetCustomersCards(QSqlQuery query = QSqlQuery());

signals:
    /*void on_dashboard_btn_clicked();
    void on_customers_btn_clicked();
    void on_employees_btn_clicked();
    void on_tariffs_btn_clicked();
    void on_requests_btn_clicked();
    void on_log_out_btn_clicked();*/
    void customer_selected(const int);

private: /*Methods*/
    void FindCustomersByName();
    void SetConnections();

private:
    Ui::CustomersPage *ui;
    QSqlDatabase* db;
};

#endif // CUSTOMERSPAGE_H
