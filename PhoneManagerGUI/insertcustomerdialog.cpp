#include "insertcustomerdialog.h"
#include "ui_insertcustomerdialog.h"
#include <QSqlQuery>
#include <QSqlError>

InsertCustomerDialog::InsertCustomerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InsertCustomerDialog)
{
    ui->setupUi(this);
    ui->incorrect_data_label->setVisible(false);
    updateComboBoxData();
    connect(ui->confirm_addition, &QPushButton::clicked
            , this, &InsertCustomerDialog::InsertCustomerToDB);
}

InsertCustomerDialog::~InsertCustomerDialog()
{
    delete ui;
}

void InsertCustomerDialog::updateComboBoxData(){
    QSqlQuery query;
    query.prepare("SELECT * FROM Tariffs;");
    query.exec();
    while(query.next())
        ui->tariff_comboBox->addItem(query.value("tariff_name").toString()
                                     , query.value("id").toInt());
}

void InsertCustomerDialog::InsertCustomerToDB(){
    QString fname = ui->first_name_lineEdit->text();
    QString lname = ui->last_name_lineEdit->text();
    QString phone = ui->phone_lineEdit->text();
    QString email = ui->email_lineEdit->text();
    QDate bday = ui->bday_dateEdit->date();
    const int tariff_id = ui->tariff_comboBox->currentData().toInt();
    if(!fname.isEmpty()
        && !lname.isEmpty()
        && !phone.isEmpty()
        && !email.isEmpty())
    {
        QSqlQuery query;
        bool no_email = ui->email_lineEdit->text().isEmpty();
        query.prepare("INSERT INTO Customers (first_name, last_name, phone, date_of_B, tariff_id, email) "
              "VALUES(:fname, :lname, :phone, :bday, :tariff_id" + QString(!no_email ? ", :email);" : ", NULL);"));

        query.bindValue(":fname", fname);
        query.bindValue(":lname", lname);
        query.bindValue(":phone", phone);
        query.bindValue(":bday", bday);
        query.bindValue(":tariff_id", tariff_id);

        if(!no_email)
            query.bindValue(":email", email);

        if(!query.exec())
            qDebug() << "InsertCustomerToDB() query fault: " << query.lastError();
        ui->incorrect_data_label->setVisible(false);
    }else{
        ui->incorrect_data_label->setVisible(true);
    }
}
