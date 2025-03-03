#include "tariffcard.h"
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

void TariffCard::setTariffNameLabelText(const QString& text){
    ui->tariff_name->setText(text);
}
