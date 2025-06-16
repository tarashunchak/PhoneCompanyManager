#include "includes/tariffeditwidget.h"
#include "ui_tariffeditwidget.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/databasemanager.h"
#include <QtConcurrent/QtConcurrent>

TariffEditWidget::TariffEditWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffEditWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Tariff data edit");
    connect(ui->calcel_btn, &QPushButton::clicked, this, &TariffEditWidget::discardChanges);
    connect(ui->save_btn, &QPushButton::clicked, this, &TariffEditWidget::saveChanges);
    connect(ui->delete_tariff_btn, &QPushButton::clicked, ui->delete_tariff_widget, &QWidget::show);
    connect(ui->confirm_btn, &QPushButton::clicked, this, [this](){
        DatabaseManager::deleteRecord<TABLE::TARIFFS>("id", tariff_id);
        ui->delete_tariff_widget->close();
    });
    connect(ui->cancel_btn, &QPushButton::clicked, ui->delete_tariff_widget, &QWidget::close);
    ui->delete_tariff_widget->close();
    ui->incorrect_data_label->setVisible(false);
    ui->delete_tariff_btn->setIcon(QIcon{"./img/delete_can.png"});
}

TariffEditWidget::~TariffEditWidget()
{
    delete ui;
}

void TariffEditWidget::setTariffInformation(const uint tmptariff_id){
    this->tariff_id = tmptariff_id;
    /*QSqlQuery records;
    records.prepare("SELECT * FROM tariffs "
                  "WHERE id = :tariff_id;");
    records.bindValue(":tariff_id", tariff_id);*/
    auto records = DatabaseManager::selectRecord<TABLE::TARIFFS>("id", tariff_id);
    if(!records.exec() || !records.next()){
        qDebug() << "setTariffInformation fault";
        return;
    }
    ui->tariff_name_label->setText(records.value("tariff_name").toString());
    ui->daily_price_lineEdit->setText(records.value("daily_price").toString());
    ui->monthly_price_lineEdit->setText(records.value("monthly_price").toString());
    ui->call_minutes_lineEdit->setText(records.value("call_minutes").toString());
    ui->internet_lineEdit->setText(records.value("internet_gb").toString());
    ui->messages_lineEdit->setText(records.value("messages").toString());
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
        QSqlQuery records(QSqlDatabase::database("remote"));
        records.prepare("UPDATE tariffs "
              "SET daily_price = :daily_p, "
              "monthly_price = :mth_p, "
              "call_minutes = :c_minutes, "
              "internet_gb = :gb, "
              "messages = :messages "
              "WHERE id = :tariff_id;");
        records.bindValue(":daily_p", daily_p);
        records.bindValue(":mth_p", monthly_p);
        records.bindValue(":c_minutes", call_minutes);
        records.bindValue(":gb", internet_GB);
        records.bindValue(":messages", messages);
        records.bindValue(":tariff_id", tariff_id);
        if(!records.exec())
            qDebug() << "update tariff data fault" << records.lastError();
        else{
            QtConcurrent::run([this](){
                discardChanges();
            });
            DatabaseManager::startSyncTables();
        };
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
