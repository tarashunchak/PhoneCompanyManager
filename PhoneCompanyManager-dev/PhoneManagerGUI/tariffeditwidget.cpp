#include "includes/tariffeditwidget.h"
#include "ui_tariffeditwidget.h"

#include <QSqlQuery>
#include <QSqlError>

TariffEditWidget::TariffEditWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffEditWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Tariff data edit");
    connect(ui->calcel_btn, &QPushButton::clicked, this, &TariffEditWidget::discardChanges);
    connect(ui->save_btn, &QPushButton::clicked, this, &TariffEditWidget::saveChanges);
    ui->incorrect_data_label->setVisible(false);
}

TariffEditWidget::~TariffEditWidget()
{
    delete ui;
}

void TariffEditWidget::setTariffInformation(const uint tmptariff_id){
    this->tariff_id = tmptariff_id;
    QSqlQuery query;
    query.prepare("SELECT * FROM tariffs "
                  "WHERE id = :tariff_id;");
    query.bindValue(":tariff_id", tariff_id);

    if(!query.exec() || !query.next()){
        qDebug() << "setTariffInformation fault";
        return;
    }
    ui->tariff_name_label->setText(query.value("tariff_name").toString());
    ui->daily_price_lineEdit->setText(query.value("daily_price").toString());
    ui->monthly_price_lineEdit->setText(query.value("monthly_price").toString());
    ui->call_minutes_lineEdit->setText(query.value("call_minutes").toString());
    ui->internet_lineEdit->setText(query.value("internet_GB").toString());
    ui->messages_lineEdit->setText(query.value("messages").toString());
}

void TariffEditWidget::saveChanges(){
    static bool daily_p_ok;
    static bool monthly_p_ok;
    static bool call_minutes_ok;
    static bool internet_GB_ok;
    static bool messages_ok;

    float daily_p = ui->daily_price_lineEdit->text().toFloat(&daily_p_ok);
    float monthly_p = ui->monthly_price_lineEdit->text().toFloat(&monthly_p_ok);
    uint call_minutes = ui->call_minutes_lineEdit->text().toUInt(&call_minutes_ok);
    uint internet_GB = ui->internet_lineEdit->text().toUInt(&internet_GB_ok);
    uint messages = ui->messages_lineEdit->text().toUInt(&messages_ok);

    if(daily_p_ok && monthly_p_ok
        && call_minutes_ok && internet_GB_ok
        && messages_ok){

        ui->incorrect_data_label->setVisible(false);
        QSqlQuery query;
        query.prepare("UPDATE tariffs "
              "SET daily_price = :daily_p, "
              "monthly_price = :mth_p, "
              "call_minutes = :c_minutes, "
              "internet_GB = :gb, "
              "messages = :messages "
              "WHERE id = :tariff_id;");
        query.bindValue(":daily_p", daily_p);
        query.bindValue(":mth_p", monthly_p);
        query.bindValue(":c_minutes", call_minutes);
        query.bindValue(":gb", internet_GB);
        query.bindValue(":messages", messages);
        query.bindValue(":tariff_id", tariff_id);
        if(!query.exec())
            qDebug() << "update tariff data fault" << query.lastError();
        else
            discardChanges();
    }else
        ui->incorrect_data_label->setVisible(true);
}

void TariffEditWidget::discardChanges(){
    ui->tariff_name_label->clear();
    ui->daily_price_lineEdit->clear();
    ui->monthly_price_lineEdit->clear();
    ui->call_minutes_lineEdit->clear();
    ui->internet_lineEdit->clear();
    ui->messages_lineEdit->clear();
    this->close();
}
