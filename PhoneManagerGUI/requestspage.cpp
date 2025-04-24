#include "includes/requestspage.h"
#include "ui_requestspage.h"
#include "includes/databasemanager.h"
#include "includes/buttonsstylemanager.h"
#include "includes/currentuser.h"
#include <QSqlQuery>
#include <QSqlError>

RequestsPage::RequestsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RequestsPage)
    , db(&DatabaseManager::instance().getDatabase())
    , qmodel(new QSqlTableModel{})
{
    ui->setupUi(this);

    ui->scrollArea->setWidgetResizable(true);
    ui->profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });

    setTableView();
}

RequestsPage::~RequestsPage()
{
    db = nullptr;
    delete ui;
}

void RequestsPage::setCurrentUser(){
    QSqlQuery query;
    query.prepare("SELECT *FROM Employees WHERE id = :empl_id;");
    const int empl_id = CurrentUser::getCurrentUserID();
    query.bindValue(":empl_id", empl_id);
    if(query.exec() && query.next()){
        ui->name_label->setText(query.value("full_name").toString());
    }else{
        qDebug() << "setCurrentUser Dashboard Page fault!" << query.lastError();
        return;
    }
}
