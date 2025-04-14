#include "includes/dashboard.h"
#include "ui_dashboard.h"

#include <QSqlQuery>
#include <QSqlError>

void Dashboard::setCustomersStatistics(){
    QSqlQuery query{};
    if(ui->cust_date_comboBox->currentIndex()){
        query.prepare("SELECT COUNT(*) AS cust_count FROM Customers "
            "WHERE date >= DATE(CURRENT_DATE, :date) "
            "GROUP BY date ORDER BY date;");
        query.bindValue(":date", ui->cust_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days");
    }else{
        query.prepare("SELECT COUNT(*) AS cust_count FROM Customers "
                "WHERE date = DATE(CURRENT_DATE) "
                "GROUP BY date ORDER BY date;");
    }

    cust_bar_chart->setQuery(std::move(query), "cust_count");
    cust_bar_chart->resize(ui->customers_statistic->size());
}

void Dashboard::setRequestsStatistics(){
    QSqlQuery query{};
    if(ui->req_date_comboBox->currentIndex()){
        query.prepare("SELECT COUNT(*) AS req_count FROM Requests "
            "WHERE date >= DATE(CURRENT_DATE, :date) "
            "GROUP BY date ORDER BY date;");
        query.bindValue(":date", ui->req_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days");
    }else{
        query.prepare("SELECT COUNT(*) AS req_count FROM Requests "
                "WHERE date = DATE(CURRENT_DATE) "
                "GROUP BY date ORDER BY date;");
    }

    req_bar_chart->setQuery(std::move(query), "req_count");
    req_bar_chart->resize(ui->requests_statistic->size());
}

void Dashboard::setTariffsStatistics(){
    QSqlQuery query{"SELECT COUNT(Customers.id) AS count, Tariffs.tariff_name AS name "
                    "FROM Tariffs "
                    "JOIN Customers ON Customers.tariff_id = Tariffs.id "
                    "GROUP BY Tariffs.tariff_name;"};
    if(!query.exec()){
        qDebug() << "SetTariffsStatistics() fault: " << query.lastError();
        return;
    }
    tariff_pie_chart->setQuery(std::move(query), "name", "count");
    tariff_pie_chart->resize(ui->tariff_statistics->size());
}
