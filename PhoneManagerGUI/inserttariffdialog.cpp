#include "inserttariffdialog.h"
#include "ui_inserttariffdialog.h"

#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>

InsertTariffDialog::InsertTariffDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InsertTariffDialog)
    , db(&DatabaseManager::instance().getDatabase())
{
    ui->setupUi(this);
    setModal(true);
    setMinimumSize(440, 320);
    setMaximumSize(440, 320);

    SetConnections();
}

InsertTariffDialog::~InsertTariffDialog()
{
    db = nullptr;
    delete ui;
}

void InsertTariffDialog::SetConnections()const{
    connect(ui->confirm_addition, &QPushButton::clicked, this, &InsertTariffDialog::InsertTariffToDB);
}

void InsertTariffDialog::InsertTariffToDB(){
    if(ui->tariff_name->text() != ""){
        QSqlQuery query;
        query.prepare("INSERT INTO Tariffs(tariff_name, monthly_price, daily_price, call_minutes, internet_GB) "
                      "VALUES(:name, :monthly, :daily, :minutes, :internet);");
        query.bindValue(":name", ui->tariff_name->text());
        query.bindValue(":monthly", ui->tariff_monthly_price->text());
        query.bindValue(":daily", ui->tariff_daily_price->text());
        query.bindValue(":minutes", ui->tariff_call_minutes->text());
        query.bindValue(":internet", ui->tariff_internet_GB->text());

        if(!query.exec()){
            qDebug() << "Insert tariff to DB fault!" << query.lastError();
        }else{
            ClearWidgets();
            this->close();
        }
    }
}

void InsertTariffDialog::ClearWidgets()const{
    ui->tariff_call_minutes->clear();
    ui->tariff_daily_price->clear();
    ui->tariff_monthly_price->clear();
    ui->tariff_name->clear();
    ui->tariff_internet_GB->clear();
}
