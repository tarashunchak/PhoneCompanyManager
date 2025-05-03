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
}

RequestsPage::~RequestsPage()
{
    delete ui;
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
