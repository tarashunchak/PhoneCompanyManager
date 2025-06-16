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

bool TariffCard::is_editable = false;

void TariffCard::setEditable(const bool statement){
    is_editable = statement;
}

bool TariffCard::isEditable(){
    return is_editable;
}

void TariffCard::SetActiveButtonStatement(bool is_active){
    if(is_active){
        ui->active_inactive_swithc_btn->setText("active");
        ui->active_indicator->setStyleSheet("background-color:green; "
                                            "border-radius:8px; "
                                            "border: 1px solid white;");
    }else{
        ui->active_inactive_swithc_btn->setText("inactive");
        ui->active_indicator->setStyleSheet("background-color:red; "
                                            "border-radius:8px; "
                                            "border: 1px solid black;");
    }
}

void TariffCard::setConnections()const{
    static const QString left{
        "QPushButton{"
            "border-top-right-radius:0px;"
            "border-bottom-right-radius:0px;"
    };
    static const QString right{
        "QPushButton{"
            "border-top-left-radius:0px;"
            "border-bottom-left-radius:0px;"
    };
    static const QString both{
            "border:1px solid rgb(255, 255, 255);"
        "}"
    };
    static const QString inactive{
        "QPushButton:hover{"
            "background-color:rgba(200, 200, 200, 0.3);"
        "}"
    };
    static const QString active_right{right + "background-color:white;color:black;" + both};
    static const QString inactive_right{right + "background-color:transparent;color:white;" + both + inactive};
    static const QString active_left{left + "background-color:white;color:black;" + both};
    static const QString inactive_left{left + "background-color:transparent;color:white;" + both + inactive};

    connect(ui->monthly_btn, &QPushButton::clicked, this, [&, this](){
        ui->daily_price->setText("Monthly price");
        ui->monthly_btn->setStyleSheet(active_left);
        ui->daily_btn->setStyleSheet(inactive_right);
    });
    connect(ui->daily_btn, &QPushButton::clicked, this, [&, this](){
        ui->daily_price->setText("Daily price");
        ui->daily_btn->setStyleSheet(active_right);
        ui->monthly_btn->setStyleSheet(inactive_left);
    });
}

void TariffCard::setTariffInfoFromQuery(QSqlRecord record){
    ui->edit_btn->setVisible(is_editable);
    QString tariff_id = record.value("id").toString();
    ui->tariff_name->setText(record.value("tariff_name").toString());
    ui->id_label->setText("ID:" + tariff_id);
    ui->price_label->setText(record.value("monthly_price").toString() + "$");
    ui->internet_label->setText(record.value("internet_GB").toString() + " GB");
    ui->calls_label->setText(record.value("call_minutes").toString() + " min");
    ui->SMS_label->setText(record.value("messages").toString());

    SetActiveButtonStatement(record.value("is_active").toBool());

    connect(ui->active_inactive_swithc_btn, &QPushButton::clicked, this, [this, tariff_id]{
        QSqlQuery query(QSqlDatabase::database("remote"));
        query.prepare("UPDATE tariffs "
                      "SET is_active = :status "
                      "WHERE id = :tariff_id;");
        query.bindValue(":status", !(ui->active_inactive_swithc_btn->text() == "active"));
        query.bindValue(":tariff_id", tariff_id);

        if(!query.exec())
            qDebug() << "update tariff status fault";

        SetActiveButtonStatement((ui->active_inactive_swithc_btn->text() == "inactive"));
    });
    connect(ui->daily_btn, &QPushButton::clicked, this, [this, record](){
        ui->price_label->setText(record.value("daily_price").toString() + "$");
    });
    connect(ui->monthly_btn, &QPushButton::clicked, this, [this, record](){
        ui->price_label->setText(record.value("monthly_price").toString() + "$");
    });
}
