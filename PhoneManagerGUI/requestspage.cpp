#include "includes/requestspage.h"
#include "ui_requestspage.h"
#include "includes/currentuser.h"
#include <QSqlQuery>
#include <QSqlError>

RequestsPage::RequestsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RequestsPage)
    , qmodel(new QSqlTableModel{})
    , req_tableView(new RequestsTabelView{})
{
    ui->setupUi(this);
    req_tableView->setParent(ui->scrollAreaWidgetContents);
    req_tableView->setGeometry(0, 0, 1670, 970);
    req_tableView->setModel(qmodel);
    req_tableView->setMouseTracking(true);
    req_tableView->viewport()->setMouseTracking(true);
    ui->save_btn->raise();
    ui->save_btn->raise();
    ui->scrollArea->setWidgetResizable(true);
    //ui->tableView->setModel(qmodel);
    //setTableView();
    SetConnections();
}

RequestsPage::~RequestsPage()
{
    delete ui;
}

void RequestsPage::SetConnections()const{
    connect(ui->unassigned_req_btn, &QPushButton::clicked, this, &RequestsPage::showUnassignmentRequests);
    connect(ui->in_progress_req_btn, &QPushButton::clicked, this, &RequestsPage::showInProgressRequests);
    connect(ui->complete_req_btn, &QPushButton::clicked, this, &RequestsPage::showCompletedRequests);
    connect(ui->save_btn, &QPushButton::clicked, this, [this](){
        QSqlQuery query;
        QAbstractItemModel* model = req_tableView->model();
        QModelIndex index{};
        for(int i = 0; i < model->rowCount(); ++i){
            index = model->index(i, model->columnCount()-1);
            QString value = model->data(index).toString();
            if(value != "Action" && value != "Do nothing"){
                query.prepare("UPDATE requests SET status = :status "
                      "WHERE id = :req_id;");
                query.bindValue(":status", model->data(index).toString()+"ed");
                index = model->index(i, 0);
                query.bindValue(":req_id", model->data(index).toInt());

                qDebug() << model->data(index).toString();
                if(!query.exec())
                    qDebug() << "Update status fail!";
            }
        }
        showInProgressRequests();
    });
}

void RequestsPage::setCurrentUser(){
    QSqlQuery query;
    query.prepare("SELECT *FROM Employees WHERE id = :empl_id;");
    const int empl_id = CurrentUser::getCurrentUserID();
    query.bindValue(":empl_id", empl_id);
    if(query.exec() && query.next()){
        qDebug() << "setCurrentUser Dashboard Page fault!" << query.lastError();
        return;
    }
}
