#include "includes/taskspage.h"
#include "ui_taskspage.h"
#include <QSqlQuery>
#include "includes/currentuser.h"
#include <QSqlRecord>
#include <QStandardItemModel>
#include "includes/comboboxdelegate.h"

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
    if(!query.exec()){
        qDebug() << "showAssignedToMe fault";
    }else{
        QStandardItemModel* model = new QStandardItemModel{this};

        while (query.next()) {
            QList<QStandardItem*> items;
            for (int col = 0; col < query.record().count(); ++col) {
                items.append(new QStandardItem{query.value(col).toString()});
            }
            items.append(new QStandardItem{"Assign to me"});
            model->appendRow(items);
        }
        ui->tableView->setItemDelegateForColumn(5, new ComboBoxDelegate{{"New", "Completed"}, ui->tableView});
        QStringList headers{};
        for (int i = 0; i < query.record().count(); ++i) {
            headers << query.record().fieldName(i);
        }
        headers << "Action";
    }
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
