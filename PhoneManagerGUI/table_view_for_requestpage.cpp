#include "./includes/requestspage.h"
#include "ui_requestspage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "includes/comboboxdelegate.h"
#include "includes/currentuser.h"
#include <QStandardItemModel>
#include <QMenu>

void RequestsPage::setTableView() {
    QSqlQuery query;
    query.prepare("SELECT * FROM Requests");
    ui->label_2->setVisible(!query.exec());
    QStandardItemModel* model = new QStandardItemModel{this};

    int row = 0;

    while (query.next()) {
        QList<QStandardItem*> items;
        for (int col = 0; col < query.record().count(); ++col) {
            items.append(new QStandardItem(query.value(col).toString()));
            items[col]->setFlags(items[col]->flags() & ~Qt::ItemIsEditable);
        }
        items.append(new QStandardItem{"Action"});
        model->appendRow(items);
        ++row;
    }

    QStringList headers{};
    for (int i = 0; i < query.record().count(); ++i) {
        headers << query.record().fieldName(i);
    }
    headers << "Action";
    model->setHorizontalHeaderLabels(headers);

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setStyleSheet(
        "font-family:Consolas;"
        "font-size:16px;"
        "background-color:white;"
        "color:black;"
        );
    ui->tableView->horizontalHeader()->setStyleSheet("background-color:rgb(120, 120, 120);");
    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->setItemDelegateForColumn(model->columnCount() - 1, new ComboBoxDelegate{this});
}


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

void RequestsPage::showUnassignmentRequests()const{
    QSqlQuery query;
    query.prepare("SELECT * FROM Requests WHERE assigned_to_id = -1;");
    qmodel->setQuery(std::move(query));
    ui->label_2->setVisible(!qmodel->isDirty());
    ui->tableView->setModel(qmodel);
    setActiveButton(ui->unassigned_req_btn, true);
    setActiveButton(ui->in_progress_req_btn, false);
    setActiveButton(ui->complete_req_btn, false);
}

void RequestsPage::showInProgressRequests()const{
    QSqlQuery query;
    query.prepare("SELECT * FROM Requests WHERE status = 'In Progress' AND assigned_to_id = :id;");
    query.bindValue(":id", CurrentUser::getCurrentUserID());
    qmodel->setQuery(std::move(query));
    ui->label_2->setVisible(!qmodel->isDirty());
    ui->tableView->setModel(qmodel);
    setActiveButton(ui->unassigned_req_btn, false);
    setActiveButton(ui->in_progress_req_btn, true);
    setActiveButton(ui->complete_req_btn, false);
}

void RequestsPage::showCompletedRequests()const{
    QSqlQuery query;
    query.prepare("SELECT * FROM requests WHERE status = 'Completed' AND assigned_to_id = :id");
    query.bindValue(":id", CurrentUser::getCurrentUserID());
    qmodel->setQuery(std::move(query));
    ui->label_2->setVisible(!qmodel->isDirty());
    ui->tableView->setModel(qmodel);
    setActiveButton(ui->unassigned_req_btn, false);
    setActiveButton(ui->in_progress_req_btn, false);
    setActiveButton(ui->complete_req_btn, true);
}
