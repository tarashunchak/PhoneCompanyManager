#include "includes/dashboard.h"
#include "ui_dashboard.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/currentuser.h"
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

void Dashboard::setCustomersStatistics(){
    QSqlQuery query;
    QString interval{ui->cust_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days"};
    if (ui->cust_date_comboBox->currentIndex()) {
        query.prepare("SELECT COUNT(id) AS cust_count, date "
                      "FROM customers "
                      "WHERE DATE(date) >= DATE(CURRENT_DATE + INTERVAL '" + interval + "') "
                      "GROUP BY date ORDER BY date DESC;");
    }else {
        query.prepare("SELECT COUNT(*) AS cust_count, date "
                      "FROM customers "
                      "WHERE DATE(date) = DATE(CURRENT_DATE) "
                      "GROUP BY date ORDER BY date DESC;");
    }
    bool is_not_empty = cust_bar_chart->setQuery(query, "cust_count", "date");
    ui->empty_cust_stat->setVisible(!is_not_empty);
    ui->customers_statistic->setStyleSheet("background-color: transparent;");
}

void Dashboard::setRequestsStatistics(){
    QSqlQuery query;
    QString interval{ui->req_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days"};
    if(ui->req_date_comboBox->currentIndex()){
        query.prepare("SELECT COUNT(*) AS req_count FROM requests "
                          "WHERE date >= DATE(CURRENT_DATE + INTERVAL '" + interval + "') "
                          "GROUP BY date ORDER BY date;");
    }else{
        query.prepare("SELECT COUNT(*) AS req_count FROM requests "
                "WHERE date = CURRENT_DATE "
                "GROUP BY date ORDER BY date;");
    }

    ui->empty_req_stat->setVisible(!req_bar_chart->setQuery(query, "req_count"));

    req_bar_chart->resize(ui->requests_statistic->size());
}

void Dashboard::setTariffsStatistics(){
    QSqlQuery query;
    query.prepare("SELECT COUNT(c.id) AS count, t.tariff_name AS name "
                  "FROM tariffs t "
                  "JOIN customers c ON c.tariff_id = t.id "
                  "GROUP BY t.tariff_name;");
    if(!query.exec()){
        qDebug() << "SetTariffsStatistics() fault: " << query.lastError();
        return;
    }
    tariff_pie_chart->setVisible(true);
    tariff_pie_chart->setQuery(std::move(query), "name", "count");
}

void Dashboard::setRequestsHistory(){
    QString limit{std::to_string((ui->requests_period_comboBox->currentIndex() + 1) * 10).c_str()};
    QSqlQuery query;
    query.prepare("SELECT r.id AS \"ID\", "
                  "c.phone AS \"Phone\", "
                  "r.date AS \"Date\" "
                  "FROM requests r "
                  "JOIN customers c ON c.id = r.cust_id "
                  "ORDER BY r.id DESC LIMIT " + limit + ";");
    if(!query.exec()){
        qDebug() << "setRequestsHistory() fault: " << query.lastError();
        return;
    }
    req_qmodel->setQuery(std::move(query));
}
