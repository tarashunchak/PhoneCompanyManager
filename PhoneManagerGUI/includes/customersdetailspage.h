#ifndef CUSTOMERSDETAILSPAGE_H
#define CUSTOMERSDETAILSPAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "piechart.h"
#include "linechart.h"

namespace Ui {
class CustomersDetailsPage;
}

class CustomersDetailsPage : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersDetailsPage(QWidget *parent = nullptr);
    ~CustomersDetailsPage();
    void setCurrentUser();

public slots:
    void SetCustomerInfo(const int);

signals:
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
    LineChart* usage_chart;
};

#endif // CUSTOMERSDETAILSPAGE_H
