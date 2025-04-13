#ifndef CUSTOMERSDETAILSPAGE_H
#define CUSTOMERSDETAILSPAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "piechart.h"

namespace Ui {
class CustomersDetailsPage;
}

class CustomersDetailsPage : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersDetailsPage(QWidget *parent = nullptr);
    ~CustomersDetailsPage();

public slots:
    void SetCustomerInfo(const int);

signals:
    void on_dashboard_btn_clicked();
    void on_customers_btn_clicked();
    void on_employees_btn_clicked();
    void on_tariffs_btn_clicked();
    void on_requests_btn_clicked();
    void on_log_out_btn_clicked();
    void on_return_btn_clicked();

private:
    void SetConnections();
    void SetTableViewStyle();
    void SetCharts(const int);

private:
    Ui::CustomersDetailsPage *ui;
    QSqlDatabase* db;
    QSqlTableModel* qmodel;
    PieChart* tariff_chart;
};

#endif // CUSTOMERSDETAILSPAGE_H
