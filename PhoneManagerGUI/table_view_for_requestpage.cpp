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
    query.prepare("SELECT id AS \"ID\", cust_id AS \"Cust. ID\", "
                  "request_type AS \"Req. type\", "
                  "status AS \"Status\", date AS \"Date\" "
                  "FROM requests WHERE assigned_to_id = -1;");
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
    setActiveButton(ui->unassigned_req_btn, true);
    setActiveButton(ui->in_progress_req_btn, false);
    setActiveButton(ui->complete_req_btn, false);
    setActiveButton(ui->history_btn, false);
}

void RequestsPage::showInProgressRequests()const{
    ui->save_btn->setVisible(true);
    QSqlQuery query;
    query.prepare("SELECT id AS \"ID\", cust_id AS \"Cust. ID\", "
                  "request_type AS \"Req. type\", "
                  "status AS \"Status\", date AS \"Date\" "
                  "FROM requests "
                  "WHERE status = 'In Progress' "
                  "AND assigned_to_id = -1;");

    query.bindValue(":id", CurrentUser::getCurrentUserID());
    if(!query.exec()){
        ui->no_requests_label->setVisible(true);
        qDebug() << "showInProgressRequests()const query fault: " << query.lastError();
    }else{
        ui->no_requests_label->setVisible(false);
        QStandardItemModel* model = new QStandardItemModel{ui->scrollAreaWidgetContents};
        while(query.next()){
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
        req_tableView->setItemDelegateForColumn(req_tableView->model()->columnCount()-1, new ComboBoxDelegate{});

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
    setActiveButton(ui->history_btn, false);
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

    ui->no_requests_label->setVisible(!query.exec());
    qmodel->setQuery(std::move(query));

    ui->no_requests_label->setVisible(qmodel->rowCount() == 0);
    req_tableView->setModel(qmodel);
    req_tableView->setItemDelegateForColumn(req_tableView->model()->columnCount()-1, nullptr);
    setActiveButton(ui->unassigned_req_btn, false);
    setActiveButton(ui->in_progress_req_btn, false);
    setActiveButton(ui->complete_req_btn, true);
    setActiveButton(ui->history_btn, false);
}


void RequestsPage::showRequestsHistory(){
    QSqlQuery query;
    query.prepare("SELECT r.id AS \"ID\", "
                  "(COALESCE(c.first_name, '') || ' ' || COALESCE(c.last_name, '') "
                  "|| ' ID(' || c.id || ')') AS \"Customer\", "
                  "r.request_type AS \"Req. type\", "
                  "r.status AS \"Status\", r.date AS \"Date\", "
                  "(COALESCE(e.first_name, '') || ' ' || COALESCE(e.last_name, '') "
                  "|| ' ID(' || e.id  || ')') AS \"Handled by\" "
                  "FROM requests r "
                  "LEFT JOIN employees e ON e.id = r.assigned_to_id "
                  "LEFT JOIN customers c ON c.id = r.cust_id;");
    if(!query.exec())
        qDebug() << "requests history query fault: " << query.lastError();

    qmodel->setQuery(std::move(query));

    ui->no_requests_label->setVisible(qmodel->rowCount() == 0);
    req_tableView->setItemDelegateForColumn(req_tableView->model()->columnCount()-1, nullptr);

    req_tableView->setModel(qmodel);
    setActiveButton(ui->unassigned_req_btn, false);
    setActiveButton(ui->in_progress_req_btn, false);
    setActiveButton(ui->complete_req_btn, false);
    setActiveButton(ui->history_btn, true);
}
