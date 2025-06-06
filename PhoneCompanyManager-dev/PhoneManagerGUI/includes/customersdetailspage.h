#ifndef CUSTOMERSDETAILSPAGE_H
#define CUSTOMERSDETAILSPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include "piechart.h"
#include "barchart.h"
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
    void SetRequestsHistory()const;
    void SetPaymentsHistory()const;
    void SetMessagesHistory()const;
    void DeleteCustomerFromDB()const;

    struct TableModels{
        QSqlTableModel* req_qmodel;
        QSqlTableModel* payments_qmodel;
        QSqlTableModel* messages_qmodel;
    };

private:
    Ui::CustomersDetailsPage *ui;
    PieChart* tariff_pie_chart;
    BarChart* tariff_bar_chart;
    QTableView* table_view;
    TableModels TABLE_MODELS;
    static uint curr_cust_id;
};

#endif // CUSTOMERSDETAILSPAGE_H
