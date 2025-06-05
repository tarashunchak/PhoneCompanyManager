#include "includes/insertcustomerdialog.h"
#include "ui_insertcustomerdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/currentuser.h"

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
    QDate bday = ui->bday_dateEdit->date();
    const uint tariff_id = ui->tariff_comboBox->currentData().toUInt();
    if(!fname.isEmpty()
        && !lname.isEmpty()
        && !phone.isEmpty())
    {
        query.prepare("INSERT INTO customers(first_name, last_name, phone, date_of_B, tariff_id, email, employee_id) "
                      "VALUES(:fname, :lname, :phone, :bday, :tariff_id, :email, :empl_id)");

        query.bindValue(":fname", fname);
        query.bindValue(":lname", lname);
        query.bindValue(":phone", phone);
        query.bindValue(":bday", bday);
        query.bindValue(":tariff_id", tariff_id);
        query.bindValue(":email", email.isEmpty() ? "NULL" : email);
        query.bindValue(":empl_id", CurrentUser::getCurrentUserID());

        if(!query.exec()){
            qDebug() << "InsertCustomerToDB() query fault: " << query.lastError();
            ui->incorrect_data_label->setVisible(true);
        }else{
            ui->incorrect_data_label->setVisible(false);
            clearWidgets();
        }
    }else{
        ui->incorrect_data_label->setVisible(true);
    }
}
