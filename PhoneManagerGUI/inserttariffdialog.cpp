#include "includes/inserttariffdialog.h"
#include "ui_inserttariffdialog.h"
#include <QSqlQuery>
#include <QSqlError>

InsertTariffDialog::InsertTariffDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InsertTariffDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Insert tariff");
    setModal(true);
    setMinimumSize(440, 320);
    setMaximumSize(440, 320);
    setConnections();
}

InsertTariffDialog::~InsertTariffDialog()
{
    delete ui;
}

void InsertTariffDialog::setConnections()const{
    connect(ui->confirm_addition_btn, &QPushButton::clicked, this, &InsertTariffDialog::InsertTariffToDB);
}

void InsertTariffDialog::InsertTariffToDB(){
    static bool daily_p_ok;
    static bool monthly_p_ok;
    static bool call_minutes_ok;
    static bool internet_GB_ok;

    float daily_p = ui->daily_p_lineEdit->text().toFloat(&daily_p_ok);
    float monthly_p = ui->monthly_p_lineEdit->text().toFloat(&monthly_p_ok);
    uint call_minutes = ui->call_minutes_lineEdit->text().toUInt(&call_minutes_ok);
    uint internet_GB = ui->internet_GB_lineEdit->text().toUInt(&internet_GB_ok);
    QString name = ui->tariff_name_lineEdit->text();

    if(daily_p_ok && monthly_p_ok
        && call_minutes_ok && internet_GB_ok
        && !name.isEmpty()){

        QSqlQuery query;
        query.prepare("INSERT INTO tariffs(tariff_name, monthly_price, daily_price, call_minutes, internet_GB) "
                      "VALUES(:name, :monthly, :daily, :minutes, :internet);");
        query.bindValue(":name", name);
        query.bindValue(":monthly", monthly_p);
        query.bindValue(":daily", daily_p);
        query.bindValue(":minutes", call_minutes);
        query.bindValue(":internet", internet_GB);

        if(!query.exec()){
            qDebug() << "Insert tariff to DB fault!" << query.lastError();
        }else{
            clearWidgets();
        }
    }
}

void InsertTariffDialog::clearWidgets()const{
    ui->call_minutes_lineEdit->clear();
    ui->daily_p_lineEdit->clear();
    ui->monthly_p_lineEdit->clear();
    ui->tariff_name_lineEdit->clear();
    ui->internet_GB_lineEdit->clear();
}
