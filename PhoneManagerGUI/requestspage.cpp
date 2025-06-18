#include "includes/requestspage.h"
#include "ui_requestspage.h"
#include <QSqlQuery>
#include <QSqlError>

RequestsPage::RequestsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RequestsPage)
    , qmodel(new QSqlTableModel{})
    , req_tableView(new QTableView{this})
{
    ui->setupUi(this);
    ui->req_tableView->setParent(ui->scrollAreaWidgetContents);
    ui->req_tableView->setGeometry(0, 0, 1670, 970);
    ui->req_tableView->setModel(qmodel);
    ui->req_tableView->setMouseTracking(true);
    ui->req_tableView->viewport()->setMouseTracking(true);
    ui->save_btn->raise();
    ui->save_btn->raise();
    ui->scrollArea->setWidgetResizable(true);
    SetConnections();
}

RequestsPage::~RequestsPage()
{
    delete ui;
}

void RequestsPage::SetConnections(){
    connect(ui->unassigned_req_btn, &QPushButton::clicked, this, &RequestsPage::showUnassignmentRequests);
    connect(ui->in_progress_req_btn, &QPushButton::clicked, this, &RequestsPage::showInProgressRequests);
    connect(ui->complete_req_btn, &QPushButton::clicked, this, &RequestsPage::showCompletedRequests);
    connect(ui->history_btn, &QPushButton::clicked, this, &RequestsPage::showRequestsHistory);
    connect(ui->save_btn, &QPushButton::clicked, this, [this](){
        QSqlQuery query(QSqlDatabase::database("remote"));
        QAbstractItemModel* model = ui->req_tableView->model();
        QModelIndex index{};
        for(int i = 0; i < model->rowCount(); ++i){
            index = model->index(i, model->columnCount()-1);
            QString value = model->data(index).toString();
            if(value != "Action" && value != "Do nothing"){
                query.prepare("UPDATE requests SET status = :status, "
                              "processing_date = CURRENT_TIMESTAMP "
                      "WHERE id = :req_id;");
                query.bindValue(":status", model->data(index).toString()+"ed");
                index = model->index(i, 0);
                query.bindValue(":req_id", model->data(index).toInt());

                qDebug() << model->data(index).toString();
                if(!query.exec())
                    qDebug() << "Update status fail!";
                if(value == "Confirm"){
                    uint tariff_id = model->index(i, 0).data().toUInt();
                    uint cust_id = model->index(i, 1).data().toUInt();
                    if(tariff_id){
                        query.prepare("UPDATE customers "
                                      "SET tariff_id = :tariff_id "
                                      "WHERE id = :cust_id;");
                        query.bindValue(":tariff_id", tariff_id);
                        query.bindValue(":cust_id", cust_id);
                        query.exec();
                    }
                }
            }
        }
        showInProgressRequests();
    });
}
