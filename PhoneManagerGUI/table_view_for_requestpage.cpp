#include "./includes/requestspage.h"
#include "ui_requestspage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "includes/comboboxdelegate.h"
#include <QStandardItemModel>
#include <QMenu>

void RequestsPage::setTableView() {
    QSqlQuery query("SELECT * FROM Requests;");
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
