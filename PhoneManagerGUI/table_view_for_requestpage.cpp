#include "./includes/requestspage.h"
#include "ui_requestspage.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/comboboxdelegate.h"
#include <QStandardItemModel>

void RequestsPage::setTableView(){
    qmodel->setQuery("SELECT * FROM Requests;");

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setVisible(false);

    //ui->tableView->setItemDelegateForColumn(ui->tableView->model()->columnCount(),
    //                                        new ComboBoxDelegate{ui->tableView});
    ui->tableView->setModel(qmodel);
}
