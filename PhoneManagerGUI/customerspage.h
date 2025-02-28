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

signals:
    void on_dashboard_btn_clicked();
    void on_employees_btn_clicked();
    void on_tariffs_btn_clicked();
    void on_requests_btn_clicked();

private: /*Methods*/
    void SetCustomersCards(QSqlQuery query);
    void FindCustomersByName();
    void SetConnections();

private:
    Ui::CustomersPage *ui;
    QSqlDatabase* db;
};

#endif // CUSTOMERSPAGE_H
