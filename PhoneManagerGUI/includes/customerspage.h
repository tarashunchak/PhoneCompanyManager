#ifndef CUSTOMERSPAGE_H
#define CUSTOMERSPAGE_H

#include <QWidget>
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
    void customer_selected(const int);

private: /*Methods*/
    void FindCustomersByName();
    void SetConnections();

private:
    Ui::CustomersPage *ui;
};

#endif // CUSTOMERSPAGE_H
