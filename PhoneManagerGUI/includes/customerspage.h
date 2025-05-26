#ifndef CUSTOMERSPAGE_H
#define CUSTOMERSPAGE_H

#include <QWidget>
#include <QSqlQuery>
#include "insertcustomerdialog.h"
#include <QPropertyAnimation>

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
    void updateFilterWidgets();
    void open_filter_widget();
    void close_filter_widget();

signals:
    void customer_selected(const int);

private: /*Methods*/
    void FindCustomersByName();
    void SetConnections();
    void fillTariffsComboBox();
    void fillEmployeesComboBox();
    void open_close_filter_widget();
    void apply_filters();

private:
    Ui::CustomersPage *ui;
    InsertCustomerDialog* insert_customer_dialog;
    QPropertyAnimation* filter_animation;
};

#endif // CUSTOMERSPAGE_H
