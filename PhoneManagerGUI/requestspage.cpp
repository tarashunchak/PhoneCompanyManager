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
    req_tableView->setParent(this);
    req_tableView->setGeometry(0, 110, 1670, 970);
    req_tableView->setModel(qmodel);
    req_tableView->setMouseTracking(true);
    req_tableView->viewport()->setMouseTracking(true);
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
