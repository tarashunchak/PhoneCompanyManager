#ifndef CUSTOMERSDETAILSPAGE_H
#define CUSTOMERSDETAILSPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include "piechart.h"
#include "barchart.h"
#include "linechart.h"
#include <QTableView>

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
    void SetCustomerInfo(const uint);

signals:
    void on_return_btn_clicked();
    void on_open_chat_btn_clicked(const QString&);

private:
    void SetConnections();
    void SetTableViewStyle();
    void SetCharts();
    void SaveCommentToDB();
    void SetTariffsChart()const;
    void SetUsageChart()const;
    void DeleteCustomerFromDB()const;

private:
    Ui::CustomersDetailsPage *ui;
    QSqlTableModel* qmodel;
    PieChart* tariff_pie_chart;
    BarChart* tariff_bar_chart;
    LineChart* usage_chart;
    QTableView* table_view;
    static uint curr_cust_id;
};

#endif // CUSTOMERSDETAILSPAGE_H
