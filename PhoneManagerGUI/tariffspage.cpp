#include "includes/tariffspage.h"
#include "ui_tariffspage.h"
#include "includes/currentuser.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QScrollArea>
#include "includes/tariffcard.h"

TariffsPage::TariffsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffsPage)
    , tariff_edit_widget(new TariffEditWidget{})
{
    ui->setupUi(this);
    setConnections();
    setTariffsCards();
}

TariffsPage::~TariffsPage()
{
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
    QLayout* layout = ui->gridLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }

    if(!query.exec()){
        query.prepare("SELECT * FROM Tariffs;");
        if(!query.exec())
            qDebug() << "TariffsPage::setTariffsCards(QSqlQuery) query fault: " << query.lastError();
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
        card->setMinimumSize(300, 460);
        card->setTariffInfoFromQuery(query.record());

        innerGridLayout->addWidget(card, rows, cols);
        cols++;
        if(cols % 4 == 0){
            cols = 0;
            rows++;
        }
        connect(card, &TariffCard::on_edit_btn_clicked, tariff_edit_widget, &QWidget::show);
    }
    innerGridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    innerGridLayout->setHorizontalSpacing(100);
    innerGridLayout->setVerticalSpacing(50);
    innerGridLayout->setContentsMargins(84, 40, 0, 0);

    mainWidget->setLayout(innerGridLayout);

    scrollArea->setWidget(mainWidget);
    ui->gridLayout->addWidget(scrollArea);

}

void TariffsPage::FindTariffInDB(){
    QSqlQuery query;
    query.prepare("SELECT * FROM Tariffs "
                  "WHERE tariff_name LIKE :name OR id = :id;");
    QString text{ui->lineEdit->text()};
    query.bindValue(":name", text + "%");
    query.bindValue(":id", text);

    setTariffsCards(std::move(query));
}
