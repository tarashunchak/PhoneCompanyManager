#include "./includes/requestspage.h"
#include "ui_requestspage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "includes/comboboxdelegate.h"
#include "includes/pushbuttondelegate.h"
#include "includes/databasemanager.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMenu>

enum ACTIVE_BTN : unsigned char{
    UNASSIGNED = 0,
    IN_PROGRESS,
    COMPLETED,
    HISTORY
};

namespace{
    const QString both{
        "QPushButton{"
        "height:40px;"
        "color:black;"
        "font-family:Lato, Arial, Consolas;"
        "font-size:22px;"
        "border-top-left-radius:5px;"
        "border-top-right-radius:5px;"};
    const QString active(both +
        "background-color:white;"
        "}"
        "QPushButton:hover{"
        "background-color:rgb(180, 180, 180);"
        "}");
    const QString inactive(both +
        "background-color:rgb(200, 200, 200);"
        "}"
        "QPushButton:hover{"
        "background-color:rgb(220, 220, 220);"
        "}");
}

void RequestsPage::setActiveButton(const uchar button){
    ui->unassigned_req_btn->setStyleSheet(button == 0 ? active : inactive);
    ui->in_progress_req_btn->setStyleSheet(button == 1 ? active : inactive);
    ui->complete_req_btn->setStyleSheet(button == 2 ? active : inactive);
    ui->history_btn->setStyleSheet(button == 3 ? active : inactive);
}

void RequestsPage::showUnassignmentRequests(){
    ui->save_btn->setVisible(false);
    auto query = DatabaseManager::unassignedRequests();
    if(!query.exec()){
        qDebug() << "showUnassignmentRequests()const query fault: " << query.lastError().text();
        qDebug() << "showUnassignmentRequests()const last query: " << query.lastQuery();
        ui->no_requests_label->setVisible(true);
    }else{
        ui->no_requests_label->setVisible(false);
        QStandardItemModel* model = new QStandardItemModel{this};

        while (query.next()) {
            QList<QStandardItem*> items;
            for (int col = 0; col < query.record().count(); ++col) {
                items.append(new QStandardItem{query.value(col).toString()});
                items[col]->setFlags(Qt::ItemIsEnabled);
            }
            items.append(new QStandardItem{"Assign to me"});
            model->appendRow(items);
        }

        QStringList headers{};
        for (int i = 0; i < query.record().count(); ++i) {
            headers << query.record().fieldName(i);
        }
        headers << "Action";
        model->setHorizontalHeaderLabels(headers);
        ui->no_requests_label->setVisible(model->rowCount() == 0);
        req_tableView->setModel(model);
        req_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        req_tableView->setStyleSheet(
            "font-family:Consolas;"
            "font-size:16px;"
            "background-color:white;"
            "color:black;"
        );

        req_tableView->horizontalHeader()->setStyleSheet("background-color:rgb(120, 120, 120);");
        req_tableView->verticalHeader()->setVisible(false);

        PushButtonDelegate* button_delegate = new PushButtonDelegate{this};
        connect(button_delegate, &PushButtonDelegate::successfully_updated, this, &RequestsPage::showUnassignmentRequests);
        req_tableView->setItemDelegateForColumn(model->columnCount() - 1, button_delegate);
    }
    setActiveButton(UNASSIGNED);
}

void RequestsPage::showInProgressRequests(){
    ui->save_btn->setVisible(true);
    auto query = DatabaseManager::inProgressRequests();
    int counter = -1;
    if(!query.exec()){
        ui->no_requests_label->setVisible(true);
        ui->save_btn->setVisible(false);
        qDebug() << "showInProgressRequests()const query fault: " << query.lastError();
    }else{
        ui->no_requests_label->setVisible(false);
        QStandardItemModel* model = new QStandardItemModel{ui->scrollAreaWidgetContents};
        while(query.next()){
            counter++;
            QList<QStandardItem*> items;
            for(int col = 0; col < query.record().count(); ++col){
                items.append(new QStandardItem{query.value(col).toString()});
                items[col]->setFlags(Qt::ItemIsEnabled);
            }
            items.append(new QStandardItem{"Action"});
            model->appendRow(items);
        }
        ui->no_requests_label->setVisible(model->rowCount() == 0);
        req_tableView->setModel(model);
        req_tableView->setItemDelegateForColumn(req_tableView->model()->columnCount()-1
                                , new ComboBoxDelegate{{"Do nothing", "Confirm", "Reject"}});

        QStringList headers{};
        for (int i = 0; i < query.record().count(); ++i) {
            headers << query.record().fieldName(i);
        }
        headers << "Action";
        model->setHorizontalHeaderLabels(headers);
        ui->save_btn->setVisible(counter > 0);
    }
    req_tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
    setActiveButton(IN_PROGRESS);
}

void RequestsPage::showCompletedRequests(){
    ui->save_btn->setVisible(false);
    auto query = DatabaseManager::completedRequests();
    if(!query.exec())
        qDebug() << "showCompletedRequests()const query fault: " << query.lastError();

    ui->no_requests_label->setVisible(!query.exec());
    qmodel->setQuery(std::move(query));

    ui->no_requests_label->setVisible(qmodel->rowCount() == 0);
    req_tableView->setItemDelegateForColumn(req_tableView->model()->columnCount()-1, nullptr);
    req_tableView->setModel(qmodel);
    req_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setActiveButton(COMPLETED);
}


void RequestsPage::showRequestsHistory(){
    ui->save_btn->setVisible(false);
    auto query = DatabaseManager::requestsHistory(DatabaseManager::PAGE::REQUESTS_PAGE);
    if(!query.exec())
        qDebug() << "requests history query fault: " << query.lastError();

    qmodel->setQuery(std::move(query));

    ui->no_requests_label->setVisible(qmodel->rowCount() == 0);
    req_tableView->setItemDelegateForColumn(req_tableView->model()->columnCount()-1, nullptr);
    req_tableView->setModel(qmodel);
    req_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setActiveButton(HISTORY);
}
