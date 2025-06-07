#ifndef CUSTOMERSDETAILSPAGE_H
#define CUSTOMERSDETAILSPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include "piechart.h"
#include "barchart.h"
#include <QTableView>
#include <QDate>

namespace Ui {
class CustomersDetailsPage;
}

class CustomersDetailsPage : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersDetailsPage(QWidget *parent = nullptr);
    ~CustomersDetailsPage();
    struct CurrentCustomer{
        static QString id;
        static QString first_name;
        static QString last_name;
        static QString phone;
        static QString email;
        static QString reg_date;
        static QString date_of_B;
        static QString tariff_name;
        static QString tariff_id;
        static QString comment_text;
        static QString comment_id;
        static QString balance;
        static QString employee_id;
        static QString is_active;
    };

public slots:
    void SetCustomerInfo(const uint);

signals:
    void on_return_btn_clicked();
    void on_open_chat_btn_clicked(const QString&);

private:
    void SetConnections();
    void SetTableViewStyle();
    void SetCharts();
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
    QTableView* table_view;
    TableModels TABLE_MODELS;
};

#endif // CUSTOMERSDETAILSPAGE_H
