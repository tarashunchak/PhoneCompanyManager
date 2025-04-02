#include "includes/tariffcard.h"
#include "ui_tariffcard.h"

TariffCard::TariffCard(QFrame *parent)
    : QFrame(parent)
    , ui(new Ui::TariffCard)
{
    ui->setupUi(this);
    setConnections();
    ui->money_pic->setPixmap(QPixmap("./img/money@2x.png"));
    ui->money_pic->setStyleSheet("background-color:white;");
}

TariffCard::~TariffCard()
{
    delete ui;
}

void TariffCard::setConnections()const{
    connect(ui->monthly_btn, &QPushButton::clicked, this, [this](){
        ui->daily_price->setText("Monthly price");
        ui->monthly_btn->setStyleSheet(
            "QPushButton{"
            "border-top-right-radius:0px;"
            "border-bottom-right-radius:0px;"
            "background-color:transparent;"
            "border:1px solid rgb(255, 255, 255);"
            "color:white;"
            "}"
            );
        ui->daily_btn->setStyleSheet(
            "QPushButton{"
            "border-top-left-radius:0px;"
            "border-bottom-left-radius:0px;"
            "background-color:white;"
            "border:1px solid rgb(255, 255, 255);"
            "color:black;"
            "}"
            );
    });
    connect(ui->daily_btn, &QPushButton::clicked, this, [this](){
        ui->daily_price->setText("Daily price");
        ui->daily_btn->setStyleSheet(
            "QPushButton{"
            "border-top-left-radius:0px;"
            "border-bottom-left-radius:0px;"
            "background-color:transparent;"
            "border:1px solid rgb(255, 255, 255);"
            "color:white;"
            "}"
            );
        ui->monthly_btn->setStyleSheet(
            "QPushButton{"
            "border-top-right-radius:0px;"
            "border-bottom-right-radius:0px;"
            "background-color:white;"
            "border:1px solid rgb(255, 255, 255);"
            "color:black;"
            "}"
            );
    });
}

void TariffCard::setTariffInfoFromQuery(QSqlRecord record){
    ui->tariff_name->setText(record.value("tariff_name").toString());
    ui->id_label->setText("ID:" + record.value("id").toString());
    ui->id_label->setAlignment(Qt::AlignRight);
    ui->price_label->setText(record.value("monthly_price").toString() + "$");
    connect(ui->daily_btn, &QPushButton::clicked, this, [this, record](){
        ui->price_label->setText(record.value("daily_price").toString() + "$");
    });
    connect(ui->monthly_btn, &QPushButton::clicked, this, [this, record](){
        ui->price_label->setText(record.value("monthly_price").toString() + "$");
    });
    ui->price_label->setAlignment(Qt::AlignRight);
}
