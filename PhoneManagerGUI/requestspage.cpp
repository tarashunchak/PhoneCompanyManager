#include "includes/requestspage.h"
#include "ui_requestspage.h"
#include "includes/currentuser.h"
#include <QSqlQuery>
#include <QSqlError>

RequestsPage::RequestsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RequestsPage)
    , qmodel(new QSqlTableModel{})
{
    ui->setupUi(this);

    ui->scrollArea->setWidgetResizable(true);

    setTableView();
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
