#include "./includes/requestspage.h"
#include "ui_requestspage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "includes/comboboxdelegate.h"
#include "includes/pushbuttondelegate.h"
#include "includes/currentuser.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMenu>

static void setActiveButton(QPushButton* button, bool status){
    button->setStyleSheet(
        "QPushButton{"
        "height:40px;"
        "color:black;"
        "font-family:Lato, Consolas;"
        "font-size:22px;"
        "background-color:" + QString(status ? "white;" : "rgb(200, 200, 200);") +
        "border-top-left-radius:5px;"
        "border-top-right-radius:5px;"
        "}"
        "QPushButton:hover{"
        "background-color:" + QString(status ? "rgb(180, 180, 180);" : "rgb(220, 220, 220);") +
        "}"
    );
}

void RequestsPage::showUnassignmentRequests(){
    ui->save_btn->setVisible(false);
    QSqlQuery query;
    query.prepare("SELECT id, cust_id, request_type, "
                  "status, date FROM requests WHERE assigned_to_id = -1;");
    if(!query.exec()){
        qDebug() << "showUnassignmentRequests()const query fault: " << query.lastError().text();
        qDebug() << "showUnassignmentRequests()const last query: " << query.lastQuery();
        ui->label_2->setVisible(true);
    }else{
        ui->label_2->setVisible(false);
        QStandardItemModel* model = new QStandardItemModel{this};

        int row = 0;

        while (query.next()) {
        QList<QStandardItem*> items;
        for (int col = 0; col < query.record().count(); ++col) {
            items.append(new QStandardItem{query.value(col).toString()});
        }
        items.append(new QStandardItem{"Assign to me"});
        model->appendRow(items);
        ++row;
        }

        QStringList headers{};
        for (int i = 0; i < query.record().count(); ++i) {
        headers << query.record().fieldName(i);
        }
        headers << "Action";
        model->setHorizontalHeaderLabels(headers);

        req_tableView->setModel(model);
        req_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        req_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

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
    setActiveButton(ui->unassigned_req_btn, true);
    setActiveButton(ui->in_progress_req_btn, false);
    setActiveButton(ui->complete_req_btn, false);
}

void RequestsPage::showInProgressRequests()const{
    ui->save_btn->setVisible(true);
    QSqlQuery query;
    query.prepare("SELECT id, cust_id, request_type, "
                  "status, date FROM requests WHERE status = 'In Progress' "
                  "AND assigned_to_id = :id;");

    query.bindValue(":id", CurrentUser::getCurrentUserID());
    if(!query.exec()){
        ui->label_2->setVisible(true);
        qDebug() << "showInProgressRequests()const query fault: " << query.lastError();
    }else{
        ui->label_2->setVisible(false);
        QStandardItemModel* model = new QStandardItemModel{ui->scrollAreaWidgetContents};
        int row = 0;
        while(query.next()){
            QList<QStandardItem*> items;
            for(int col = 0; col < query.record().count(); ++col){
                items.append(new QStandardItem{query.value(col).toString()});
            }
            items.append(new QStandardItem{"Action"});
            model->appendRow(items);
        }
        req_tableView->setModel(model);
        req_tableView->setItemDelegateForColumn(req_tableView->model()->columnCount()-1, new ComboBoxDelegate{});
        req_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        QStringList headers{};
        for (int i = 0; i < query.record().count(); ++i) {
            headers << query.record().fieldName(i);
        }
        headers << "Action";
        model->setHorizontalHeaderLabels(headers);
    }
    setActiveButton(ui->unassigned_req_btn, false);
    setActiveButton(ui->in_progress_req_btn, true);
    setActiveButton(ui->complete_req_btn, false);
}

void RequestsPage::showCompletedRequests(){
    ui->save_btn->setVisible(false);
    QSqlQuery query;
    query.prepare("SELECT * FROM requests "
                  "WHERE status = 'Confirmed' OR status = 'Rejected' "
                  "AND assigned_to_id = :id;");
    query.bindValue(":id", CurrentUser::getCurrentUserID());
    if(!query.exec())
        qDebug() << "showCompletedRequests()const query fault: " << query.lastError();
    int col = 0;

    ui->label_2->setVisible(!query.exec());
    qmodel->setQuery(std::move(query));

    req_tableView->setModel(qmodel);
    req_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    req_tableView->setItemDelegateForColumn(req_tableView->model()->columnCount()-1, nullptr);
    setActiveButton(ui->unassigned_req_btn, false);
    setActiveButton(ui->in_progress_req_btn, false);
    setActiveButton(ui->complete_req_btn, true);
}
