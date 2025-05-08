#include "includes/dashboard.h"
#include "ui_dashboard.h"

#include <QSqlQuery>
#include <QSqlError>

void Dashboard::setCustomersStatistics(){
    QSqlQuery query{};
    if (ui->cust_date_comboBox->currentIndex()) {
        query.prepare("SELECT COUNT(*) AS cust_count FROM Customers "
                      "WHERE date >= CURRENT_DATE + INTERVAL :interval "
                      "GROUP BY date ORDER BY date DESC;");
        query.bindValue(":interval", ui->cust_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days");
    } else {
        query.prepare("SELECT COUNT(*) AS cust_count FROM Customers "
                      "WHERE date = CURRENT_DATE "
                      "GROUP BY date ORDER BY date DESC;");
    }
    bool is_not_empty = cust_bar_chart->setQuery(query, "cust_count");

    if(is_not_empty == false){
        cust_bar_chart->setParent(nullptr);
        is_empty_label->setParent(ui->customers_statistic);
        ui->customers_statistic->setGeometry(10, 60, 490, 390);
        is_empty_label->resize(ui->customers_statistic->size());
        ui->customers_statistic->setStyleSheet("background-color: white;");
    }else{
        is_empty_label->setParent(nullptr);
        ui->customers_statistic->setGeometry(0, 0, 510, 410);
        ui->customers_statistic->setStyleSheet("background-color: transparent;");
        cust_bar_chart->setParent(ui->customers_statistic);
        cust_bar_chart->resize(ui->customers_statistic->size());
    }
}

void Dashboard::setRequestsStatistics(){
    QSqlQuery query{};
    if(ui->req_date_comboBox->currentIndex()){
        query.prepare("SELECT COUNT(*) AS req_count FROM Requests "
            "WHERE date >= CURRENT_DATE + INTERVAL :interval"
            "GROUP BY date ORDER BY date;");
        query.bindValue(":interval", ui->req_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days");
    }else{
        query.prepare("SELECT COUNT(*) AS req_count FROM Requests "
                "WHERE date = CURRENT_DATE "
                "GROUP BY date ORDER BY date;");
    }

    req_bar_chart->setQuery(query, "req_count");
    req_bar_chart->resize(ui->requests_statistic->size());
}

void Dashboard::setTariffsStatistics(){
    QSqlQuery query{};
    query.prepare("SELECT COUNT(Customers.id) AS count, Tariffs.tariff_name AS name "
                  "FROM Tariffs "
                  "JOIN Customers ON Customers.tariff_id = Tariffs.id "
                  "GROUP BY Tariffs.tariff_name;");
    if(!query.exec()){
        qDebug() << "SetTariffsStatistics() fault: " << query.lastError();
        return;
    }
    tariff_pie_chart->setQuery(std::move(query), "name", "count");
    tariff_pie_chart->resize(ui->tariff_statistics->size());
}

void Dashboard::setRequestsHistory(){
    QSqlQuery query{};
    query.prepare("SELECT Requests.id AS ID, Customers.phone AS Phone,"
                    "Requests.date AS Date FROM Requests "
                    "JOIN Customers ON Customers.id = Requests.cust_id "
                  "ORDER BY Requests.id DESC LIMIT 15;");
    if(!query.exec()){
        qDebug() << "setRequestsHistory() fault: " << query.lastError();
        return;
    }
    req_qmodel->setQuery(std::move(query));
    ui->requests_statistic_tableView->setModel(req_qmodel);
    ui->requests_statistic_tableView->verticalHeader()->setVisible(false);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
