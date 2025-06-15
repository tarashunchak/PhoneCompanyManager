#include "includes/dashboard.h"
#include "ui_dashboard.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/databasemanager.h"

void Dashboard::setCustomersStatistics(){
    QString period{ui->cust_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days"};
    bool is_today =  !ui->cust_date_comboBox->currentIndex();
    auto query = DatabaseManager::newCustomersByPeriod(is_today, period);
    bool is_empty = !cust_bar_chart->setQuery(std::move(query), "cust_count", "date");
    ui->empty_cust_stat->setVisible(is_empty);
    ui->customers_statistic->setStyleSheet("background-color: transparent;");
}

void Dashboard::setRequestsStatistics(){
    QString period{ui->req_date_comboBox->currentIndex() > 1 ? "-7 days" : "-3 days"};
    bool is_today = !ui->requests_period_comboBox->currentIndex();
    auto query = DatabaseManager::newRequestsByPeriod(is_today, period);
    ui->empty_req_stat->setVisible(!req_bar_chart->setQuery(std::move(query), "req_count"));
    req_bar_chart->resize(ui->requests_statistic->size());
}

void Dashboard::setTariffsStatistics(){
    QSqlQuery query(QSqlDatabase::database("local"));
    query.prepare("SELECT COUNT(c.id) AS count, t.tariff_name AS name "
                  "FROM tariffs t "
                  "JOIN customers c ON c.tariff_id = t.id "
                  "GROUP BY t.tariff_name LIMIT :limit;");
    QString text = ui->tariff_comboBox->currentText();
    query.bindValue(":limit", text.right(text.length()-4));
    if(!query.exec()){
        qDebug() << "SetTariffsStatistics() fault: " << query.lastError();
        return;
    }
    tariff_pie_chart->setVisible(true);
    tariff_pie_chart->setQuery(std::move(query), "name", "count");
}

void Dashboard::setRequestsHistory(){
    QString period{QString::number((ui->requests_period_comboBox->currentIndex() + 1) * 10)};
    auto query = DatabaseManager::requestsHistory(DatabaseManager::PAGE::DASHBOARD_PAGE, period);
    if(!query.exec()){
        qDebug() << "setRequestsHistory() fault: " << query.lastError();
        return;
    }
    req_qmodel->setQuery(std::move(query));
}
