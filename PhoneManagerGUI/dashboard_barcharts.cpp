#include "includes/dashboard.h"
#include "ui_dashboard.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>

void Dashboard::setCustomersStatictics(){
    if(bar_sets_list){
        delete bar_sets_list;
    }
    bar_sets_list = new QList<std::pair<QBarSet*, bool>>;
    QSqlQuery query("SELECT registration_Date AS date, COUNT(*) AS cust_count FROM Customers "
                  "GROUP BY registration_Date ORDER BY registration_Date DESC LIMIT 7;");
    if(!query.exec() || !query.next()){
        qDebug() << "Sql query error in setCustomersStatictics(): " << query.lastError();
        return;
    }

    QBarSeries* bar_series = new QBarSeries{};
    bar_series->setBarWidth(1);

    short i = 0;
    while(query.next()){
        bar_sets_list->push_back({new QBarSet{""}, false});

        //A pointer indicating that the first element of a std::pair<QBarSet*, bool>  -->
        QBarSet* bar_set = bar_sets_list->at(i).first;

        connect(bar_set, &QBarSet::hovered, this, [this, i, bar_set](){
            QColor color = bar_set->color();
            bool is_hovered = bar_sets_list->at(i).second;
            bar_set->setColor(is_hovered ? QColor(color.red() + 30, color.green() + 30, color.blue() + 30)
                                         : QColor(color.red() - 30, color.green() - 30, color.blue() - 30));
            (*bar_sets_list)[i].second = !bar_sets_list->at(i).second;
        });
        *bar_sets_list->at(i).first << query.value("cust_count").toInt();

        bar_series->append(bar_sets_list->at(i).first);
        bar_set = nullptr;
        i++;
    }

    QChart* chart  = new QChart{};
    chart->addSeries(bar_series);

    cust_chart_view->setParent(ui->customers_statistic);
    cust_chart_view->setChart(chart);
    cust_chart_view->resize(ui->customers_statistic->size());
}

void Dashboard::setRequestsStatictics()const{
    QSqlQuery query("SELECT COUNT(*) AS req_count FROM Requests "
                  "GROUP BY date ORDER BY date;");
    if(!query.exec() || !query.next()){
        qDebug() << "Sql query error in setRequestsStatictics(): " << query.lastError();
        return;
    }
     QBarSet* bar_set = new QBarSet("Requests");
    while(query.next()){
        *bar_set << query.value("req_count").toInt();
    }
    QBarSeries* bar_series = new QBarSeries{};
    bar_series->append(bar_set);
    QChart* chart  = new QChart{};
    chart->addSeries(bar_series);

    req_chart_view->setParent(ui->requests_statistic);
    req_chart_view->setChart(chart);
    req_chart_view->resize(ui->requests_statistic->size());

}
