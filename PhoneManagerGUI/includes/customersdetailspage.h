#ifndef CUSTOMERSDETAILSPAGE_H
#define CUSTOMERSDETAILSPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include "piechart.h"
#include "barchart.h"
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
    void on_open_chat_btn_clicked(const QString&);

private:
    void SetConnections();
    void SetTableViewStyle();
    void SetCharts(int);
    void SaveCommentToDB();

private:
    Ui::CustomersDetailsPage *ui;
    QSqlTableModel* qmodel;
    PieChart* tariff_pie_chart;
    BarChart* tariff_bar_chart;
    LineChart* usage_chart;
    static uint curr_cust_id;
};

#endif // CUSTOMERSDETAILSPAGE_H
