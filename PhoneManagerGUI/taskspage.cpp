#include "includes/taskspage.h"
#include "ui_taskspage.h"
#include <QSqlQuery>
#include "includes/currentuser.h"

TasksPage::TasksPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TasksPage)
    , qmodel(new QSqlQueryModel{})
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setModel(qmodel);
}

TasksPage::~TasksPage()
{
    delete ui;
}

void TasksPage::showAssignedToMe(){
    QSqlQuery query;
    query.prepare("SELECT * FROM tasks "
                  "WHERE assignee_id = :id;");
    query.bindValue(":id", CurrentUser::getCurrentUserID());
    if(!query.exec())
        qDebug() << "showAssignedToMe fault";
    qmodel->setQuery(std::move(query));
}

void TasksPage::showCreatedByMe(){
    QSqlQuery query;
    query.prepare("SELECT * FROM tasks "
                  "WHERE creator_id = :id;");
    query.bindValue(":id", CurrentUser::getCurrentUserID());
    if(!query.exec())
        qDebug() << "showCreatedByMe fault";
    qmodel->setQuery(std::move(query));
}
