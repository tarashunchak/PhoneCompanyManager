#include "includes/dashboard.h"
#include "ui_dashboard.h"
#include <QSqlQuery>
#include <QSqlError>

void Dashboard::setCustomersStatistics(){
    QSqlQuery query;
    QString interval{ui->cust_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days"};
    if (ui->cust_date_comboBox->currentIndex()) {
        query.prepare("SELECT COUNT(*) AS cust_count FROM customers "
                      "WHERE DATE(date) >= DATE(CURRENT_DATE + INTERVAL '" + interval + "') "
                      "GROUP BY date ORDER BY date DESC;");
    }else {
        query.prepare("SELECT COUNT(*) AS cust_count FROM customers "
                      "WHERE DATE(date) = DATE(CURRENT_DATE) "
                      "GROUP BY date ORDER BY date DESC;");
    }
    ui->empty_cust_stat->setVisible(!cust_bar_chart->setQuery(query, "cust_count"));
    ui->customers_statistic->setStyleSheet("background-color: transparent;");
    cust_bar_chart->setParent(ui->customers_statistic);
    cust_bar_chart->resize(ui->customers_statistic->size());
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
    query.prepare("SELECT COUNT(c.id) AS count, tariffs.tariff_name AS name "
                  "FROM tariffs "
                  "JOIN customers c ON c.tariff_id = tariffs.id "
                  "GROUP BY tariffs.tariff_name;");
    if(!query.exec()){
        qDebug() << "SetTariffsStatistics() fault: " << query.lastError();
        return;
    }
    if(ui->charts_comboBox->currentIndex()){
        tariff_bar_chart->setVisible(false);
        tariff_pie_chart->setVisible(true);
        tariff_pie_chart->setQuery(std::move(query), "name", "count");
    }else{
        tariff_pie_chart->setVisible(false);
        tariff_bar_chart->setVisible(true);
        tariff_bar_chart->setQuery(query, "count", "name");
    }
}

void Dashboard::setRequestsHistory(){
    QString limit{std::to_string((ui->requests_period_comboBox->currentIndex() + 1) * 10).c_str()};
    QSqlQuery query;
    query.prepare("SELECT requests.id AS ID, c.phone AS Phone,"
                  "requests.date AS Date FROM requests "
                  "JOIN customers c ON c.id = requests.cust_id "
                  "ORDER BY requests.id DESC LIMIT " + limit + ";");
    if(!query.exec()){
        qDebug() << "setRequestsHistory() fault: " << query.lastError();
        return;
    }
    req_qmodel->setQuery(std::move(query));
    ui->requests_statistic_tableView->setModel(req_qmodel);
    ui->requests_statistic_tableView->verticalHeader()->setVisible(false);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
