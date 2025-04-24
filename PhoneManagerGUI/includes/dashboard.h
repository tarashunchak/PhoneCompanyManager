#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "includes/barchart.h"
#include "piechart.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();
    void setCurrentUser();
    void setCustomersStatistics();
    void setRequestsStatistics();
    void setTariffsStatistics();
    void setRequestsHistory();

signals:
    void on_dashboard_btn_clicked();
    void on_customers_btn_clicked();
    void on_employees_btn_clicked();
    void on_tariffs_btn_clicked();
    void on_requests_btn_clicked();
    void on_log_out_btn_clicked();

private:/*Methods*/
    void setTableViewConnection();

private:
    Ui::Dashboard *ui;
    QSqlDatabase* db;
    QSqlTableModel* cust_qmodel;
    QSqlTableModel* req_qmodel;
    BarChart* cust_bar_chart;
    BarChart* req_bar_chart;
    PieChart* tariff_pie_chart;
};

#endif // DASHBOARD_H
