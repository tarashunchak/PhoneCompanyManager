#include "includes/insertcustomerdialog.h"
#include "ui_insertcustomerdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/currentuser.h"
#include "includes/databasemanager.h"

InsertCustomerDialog::InsertCustomerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InsertCustomerDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Insert customer");
    ui->incorrect_data_label->setVisible(false);
    updateComboBoxData();
    connect(ui->confirm_addition, &QPushButton::clicked
            , this, &InsertCustomerDialog::InsertCustomerToDB);
}

InsertCustomerDialog::~InsertCustomerDialog()
{
    delete ui;
}

void InsertCustomerDialog::clearWidgets(){
    ui->email_lineEdit->clear();
    ui->first_name_lineEdit->clear();
    ui->last_name_lineEdit->clear();
    ui->phone_lineEdit->clear();
    ui->tariff_comboBox->setCurrentIndex(0);
}

void InsertCustomerDialog::updateComboBoxData(){
    QSqlQuery query;
    query.prepare("SELECT * FROM tariffs WHERE is_active = true;");
    query.exec();
    while(query.next())
        ui->tariff_comboBox->addItem(query.value("tariff_name").toString()
                                     , query.value("id").toUInt());
}

static bool is_correct_name(const QString& str){
    for(auto c : str)
        if(!c.isLetter())
            return false;
    return true;
}

void InsertCustomerDialog::InsertCustomerToDB(){
    static QSqlQuery query;
    QString fname = is_correct_name(ui->first_name_lineEdit->text())
                    ? ui->first_name_lineEdit->text() : "";
    QString lname = is_correct_name(ui->last_name_lineEdit->text())
                    ? ui->last_name_lineEdit->text() : "";
    QString phone = ui->phone_lineEdit->text();
    QString email = ui->email_lineEdit->text();
    QString bday = ui->bday_dateEdit->date().toString();
    const uint tariff_id = ui->tariff_comboBox->currentData().toUInt();
    if(!fname.isEmpty()
        && !lname.isEmpty()
        && !phone.isEmpty())
    {
        DatabaseManager::insertToDB(DatabaseManager::TABLE::CUSTOMERS
                                    , std::tie(fname, lname, phone, email, bday, tariff_id
                                                , CurrentUser::getCurrentUserID()));
    }else{
        ui->incorrect_data_label->setVisible(true);
    }
}
