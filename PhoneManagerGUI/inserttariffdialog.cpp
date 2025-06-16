#include "includes/inserttariffdialog.h"
#include "ui_inserttariffdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/databasemanager.h"

InsertTariffDialog::InsertTariffDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InsertTariffDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Insert tariff");
    this->setWindowFlag(Qt::FramelessWindowHint);
    setModal(true);
    setMinimumSize(440, 330);
    setMaximumSize(440, 330);
    setConnections();
    ui->return_btn->setIcon(QIcon{"./img/exit.png"});
    ui->incorrect_data_label->setVisible(false);
}

InsertTariffDialog::~InsertTariffDialog()
{
    delete ui;
}

void InsertTariffDialog::setConnections(){
    connect(ui->confirm_addition_btn, &QPushButton::clicked, this, &InsertTariffDialog::InsertTariffToDB);
    connect(ui->return_btn, &QPushButton::clicked, this, [this](){
        clearWidgets();
        this->close();
    });
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
        && !name.isEmpty())
    {
        ui->incorrect_data_label->setVisible(false);
        bool is_inserted = DatabaseManager::insertToDB(TABLE::TARIFFS,
                                                       std::tie(name, monthly_p, daily_p
                                                       , call_minutes, internet_GB));
        if(is_inserted){
            clearWidgets();
        }
    }else{
        ui->incorrect_data_label->setVisible(true);
    }
}

void InsertTariffDialog::clearWidgets()const{
    ui->call_minutes_lineEdit->clear();
    ui->daily_p_lineEdit->clear();
    ui->monthly_p_lineEdit->clear();
    ui->tariff_name_lineEdit->clear();
    ui->internet_GB_lineEdit->clear();
}
