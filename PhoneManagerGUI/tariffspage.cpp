#include "includes/tariffspage.h"
#include "ui_tariffspage.h"

#include "includes/buttonsstylemanager.h"
#include "includes/databasemanager.h"
#include "includes/currentuser.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QScrollArea>
#include "includes/tariffcard.h"

TariffsPage::TariffsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffsPage)
    , db(&DatabaseManager::instance().getDatabase())

{
    ui->setupUi(this);

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });
    setConnections();
    setTariffsCards(QSqlQuery());

}

TariffsPage::~TariffsPage()
{
    db = nullptr;
    delete ui;
}

void TariffsPage::setCurrentUser(){
    QSqlQuery query;
    query.prepare("SELECT Employees.full_name AS name, "
                  "Positions.position_name AS position "
                  "FROM Employees "
                  "JOIN Positions ON Positions.id = Employees.position_id "
                  "WHERE Employees.id = :empl_id;");
    const int empl_id = CurrentUser::getCurrentUserID();
    query.bindValue(":empl_id", empl_id);
    if(query.exec() && query.next()){
        ui->name_label->setText(query.value("name").toString());
        if(query.value("position").toString() == "Administrator"){
            ui->add_tariff_btn->setVisible(true);
        }else{
            ui->add_tariff_btn->setVisible(false);
        }
    }else{
        qDebug() << "setCurrentUser Dashboard Page fault!" << query.lastError();
        return;
    }

}

void TariffsPage::setConnections()const{
    connect(ui->lineEdit, &QLineEdit::textChanged
            , this, &TariffsPage::FindTariffInDB);

    connect(this, &TariffsPage::on_add_tariff_btn_clicked
            , &insertT_Dialog, &InsertTariffDialog::exec);
}

void TariffsPage::setTariffsCards(QSqlQuery query){
    if(!query.exec()){
        query.prepare("SELECT *FROM Tariffs;");
        if(!query.exec()){
            qDebug() << "SetTariffsCards query fault!" << query.lastError();
        }
    }

    QLayout* layout = ui->gridLayout;
    if(layout){
        if(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }

    int cols = 0;
    int rows = 0;

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("border:none;");

    QWidget* mainWidget = new QWidget();
    QGridLayout* innerGridLayout = new QGridLayout(mainWidget);
    while(query.next()){
        TariffCard* card = new TariffCard();
        card->setMinimumSize(296, 510);
        card->setTariffInfoFromQuery(query.record());

        innerGridLayout->addWidget(card, rows, cols);
        cols++;
        if(cols % 4 == 0){
            cols = 0;
            rows++;
        }
    }
    innerGridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    innerGridLayout->setHorizontalSpacing(100);
    innerGridLayout->setVerticalSpacing(50);
    innerGridLayout->setContentsMargins(84, 70, 0, 0);

    mainWidget->setLayout(innerGridLayout);

    scrollArea->setWidget(mainWidget);
    ui->gridLayout->addWidget(scrollArea);

}

void TariffsPage::FindTariffInDB(){
    QSqlQuery query;
    query.prepare("SELECT *FROM Tariffs WHERE tariff_name LIKE :name OR id LIKE :id;");
    query.bindValue(":name", ui->lineEdit->text() + "%");
    query.bindValue(":id", ui->lineEdit->text() + "%");
    setTariffsCards(std::move(query));
}
