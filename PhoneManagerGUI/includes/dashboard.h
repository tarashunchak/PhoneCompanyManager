#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QLabel>
#include "includes/barchart.h"
#include "includes/piechart.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();
    void setCustomersStatistics();
    void setRequestsStatistics();
    void setTariffsStatistics();
    void setRequestsHistory();

signals:

private:/*Methods*/
    void setTableViewConnection();
    void setTableViewStyles();

private:
    Ui::Dashboard *ui;
    QSqlTableModel* cust_qmodel;
    QSqlTableModel* req_qmodel;
    BarChart* cust_bar_chart;
    BarChart* req_bar_chart;
    PieChart* tariff_pie_chart;
};

#endif // DASHBOARD_H
