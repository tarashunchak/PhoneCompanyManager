#include "includes/dashboard.h"
#include "ui_dashboard.h"

#include <QSqlQuery>
#include <QSqlError>

void Dashboard::setCustomersStatistics(){

    QSqlQuery query;
    if(ui->cust_date_comboBox->currentIndex()){
        query.prepare("SELECT COUNT(*) AS cust_count FROM Customers "
            "WHERE registration_Date >= DATE(CURRENT_DATE, :date) "
            "GROUP BY registration_Date ORDER BY registration_Date;");
        query.bindValue(":date", ui->cust_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days");
    }else{
        query.prepare("SELECT COUNT(*) AS cust_count FROM Customers "
                "WHERE registration_Date = DATE(CURRENT_DATE) "
                "GROUP BY registration_Date ORDER BY registration_Date;");
    }

    cust_bar_chart->setQuery(std::move(query), "cust_count");
    cust_bar_chart->resize(ui->customers_statistic->size());
}

void Dashboard::setRequestsStatistics(){

    QSqlQuery query;
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
