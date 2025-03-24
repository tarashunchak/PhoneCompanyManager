#include "dashboard.h"
#include "ui_dashboard.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QDateTimeAxis>
#include <QDateTime>
#include <QBarSeries>

void Dashboard::setCustomersStatictics(){
    if(bar_set_arr){
        delete bar_set_arr;
    }
    bar_set_arr = new QList<std::pair<QBarSet*, bool>>;
    QSqlQuery query("SELECT registration_Date AS date, COUNT(*) AS cust_count FROM Customers "
                  "GROUP BY registration_Date ORDER BY registration_Date DESC;");
    if(!query.exec() || !query.next()){
        qDebug() << "Sql query error in setCustomersStatictics(): " << query.lastError();
        return;
    }
    //QBarSet* bar_set = new QBarSet("Customers");
    //QDateTimeAxis* x = new QDateTimeAxis{};
    QBarSeries* bar_series = new QBarSeries{};
    bar_series->setBarWidth(1);
    QDateTime max{};

    short i = 0;
    while(query.next()){
        bar_set_arr->push_back({new QBarSet{""}, false});
        connect(bar_set_arr->at(i).first, &QBarSet::hovered, this, [this, i](){
            bar_set_arr->at(i).first->setColor(bar_set_arr->at(i).second ? QColor(0, 40 ,220) : QColor(100, 100, 100));
            bar_set_arr->at(i).first->setBorderColor(QColor(255, 255, 255));
            (*bar_set_arr)[i].second = !bar_set_arr->at(i).second;
        });
        *bar_set_arr->at(i).first << query.value("cust_count").toInt();
        bar_series->append(bar_set_arr->at(i).first);
        i++;
    }

    QChart* chart  = new QChart{};
    chart->addSeries(bar_series);
    //chart->addAxis(x, Qt::AlignBottom);

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
