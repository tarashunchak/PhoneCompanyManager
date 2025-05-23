#include "includes/tariffcard.h"
#include "ui_tariffcard.h"
#include <QSqlQuery>

TariffCard::TariffCard(QFrame *parent)
    : QFrame(parent)
    , ui(new Ui::TariffCard)
{
    ui->setupUi(this);
    setConnections();
    ui->money_pic->setPixmap(QPixmap{"./img/money.svg"});
    ui->internet_per_day->setPixmap(QPixmap{"./img/internet.svg"});
    ui->SMS->setPixmap(QPixmap{"./img/SMS.svg"});
    ui->calls_per_day->setPixmap(QPixmap{"./img/call.svg"});
    ui->edit_btn->setIcon(QIcon{"./img/edit.svg"});
    ui->edit_btn->setIconSize(QSize{24, 24});

    ui->id_label->setAlignment(Qt::AlignRight);
    ui->price_label->setAlignment(Qt::AlignRight);
    ui->internet_label->setAlignment(Qt::AlignRight);
    ui->calls_label->setAlignment(Qt::AlignRight);
    ui->SMS_label->setAlignment(Qt::AlignRight);
}

TariffCard::~TariffCard()
{
    delete ui;
}

void TariffCard::setConnections()const{
    QString active_left{
        "QPushButton{"
            "border-top-right-radius:0px;"
            "border-bottom-right-radius:0px;"
            "background-color:transparent;"
            "border:1px solid rgb(255, 255, 255);"
            "color:white;"
        "}"
        "QPushButton:hover{"
            "background-color:rgba(200, 200, 200, 0.3);"
        "}"
    };
    QString inactive_left{
        "QPushButton{"
            "border-top-right-radius:0px;"
            "border-bottom-right-radius:0px;"
            "background-color:white;"
            "border:1px solid rgb(255, 255, 255);"
            "color:black;"
        "}"
    };
    QString active_right{
        "QPushButton{"
            "border-top-left-radius:0px;"
            "border-bottom-left-radius:0px;"
            "background-color:transparent;"
            "border:1px solid rgb(255, 255, 255);"
            "color:white;"
        "}"
        "QPushButton:hover{"
            "background-color:rgba(200, 200, 200, 0.3);"
        "}"
    };
    QString inactive_right{
        "QPushButton{"
            "border-top-left-radius:0px;"
            "border-bottom-left-radius:0px;"
            "background-color:white;"
            "border:1px solid rgb(255, 255, 255);"
            "color:black;"
        "}"
    };
    connect(ui->monthly_btn, &QPushButton::clicked, this, [=, this](){
        ui->daily_price->setText("Monthly price");
        ui->monthly_btn->setStyleSheet(active_left);
        ui->daily_btn->setStyleSheet(inactive_right);
    });
    connect(ui->daily_btn, &QPushButton::clicked, this, [=, this](){
        ui->daily_price->setText("Daily price");
        ui->daily_btn->setStyleSheet(active_right);
        ui->monthly_btn->setStyleSheet(inactive_left);
    });
}

void TariffCard::setTariffInfoFromQuery(QSqlRecord record){
    QString tariff_id = record.value("id").toString();
    ui->tariff_name->setText(record.value("tariff_name").toString());
    ui->id_label->setText("ID:" + tariff_id);
    ui->price_label->setText(record.value("monthly_price").toString() + "$");
    ui->internet_label->setText(record.value("internet_GB").toString() + " GB");
    ui->calls_label->setText(record.value("call_minutes").toString() + " min");
    ui->SMS_label->setText(record.value("messages").toString());

    bool is_active = record.value("is_active").toBool();
    if(is_active){
        ui->active_inactive_swithc_btn->setText("active");
        ui->active_indicator->setStyleSheet("background-color:green; border-radius:8px;");
    }else{
        ui->active_inactive_swithc_btn->setText("inactive");
        ui->active_indicator->setStyleSheet("background-color:red; border-radius:8px;");
    }

    connect(ui->active_inactive_swithc_btn, &QPushButton::clicked, this, [this, tariff_id]{
        QSqlQuery query;
        query.prepare("UPDATE tariffs "
                      "SET is_active = :status "
                      "WHERE id = :tariff_id;");
        query.bindValue(":status", !(ui->active_inactive_swithc_btn->text() == "active"));
        query.bindValue(":tariff_id", tariff_id);

        if(!query.exec())
            qDebug() << "update tariff status fault";

        if(ui->active_inactive_swithc_btn->text() == "inactive"){
            ui->active_inactive_swithc_btn->setText("active");
            ui->active_indicator->setStyleSheet("background-color:green; border-radius:8px;");
        }else{
            ui->active_inactive_swithc_btn->setText("inactive");
            ui->active_indicator->setStyleSheet("background-color:red; border-radius:8px;");
        }
    });
    connect(ui->daily_btn, &QPushButton::clicked, this, [this, record](){
        ui->price_label->setText(record.value("daily_price").toString() + "$");
    });
    connect(ui->monthly_btn, &QPushButton::clicked, this, [this, record](){
        ui->price_label->setText(record.value("monthly_price").toString() + "$");
    });
}
