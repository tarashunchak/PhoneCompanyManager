#include "includes/insertemployeedialog.h"
#include "ui_insertemployeedialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/databasemanager.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>

InsertEmployeeDialog::InsertEmployeeDialog(QDialog* parent)
    : QDialog(parent)
    , ui(new Ui::InsertEmployeeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Insert employee");
    this->setMinimumSize(500, 376);
    this->setMaximumSize(500, 376);
    connect(ui->confirm_addition, &QPushButton::clicked, this, &InsertEmployeeDialog::InsertEmployeeToDB);
    updateComboBoxData();
    ui->incorrect_data_label->setVisible(false);
}

InsertEmployeeDialog::~InsertEmployeeDialog()
{
    delete ui;
}

void InsertEmployeeDialog::updateComboBoxData(){
    auto query = DatabaseManager::departments();
    while(query.next())
        ui->department_comboBox->addItem(query.value("department_name").toString()
                                         , query.value("id").toInt());

    query = DatabaseManager::positions();
    while(query.next())
        ui->position_comboBox->addItem(query.value("position_name").toString()
                                       , query.value("id").toInt());
}

void InsertEmployeeDialog::InsertEmployeeToDB(){
    QString fname = ui->first_name_lineEdit->text();
    QString lname = ui->last_name_lineEdit->text();
    QString phone = ui->phone_lineEdit->text();
    QString email = ui->email_lineEdit->text();
    QString date_of_B = ui->B_date_dateEdit->date().toString();
    QString hire_date = ui->hire_date_dateEdit->date().toString();
    const uint department_id = ui->department_comboBox->currentData().toUInt();
    const uint position_id = ui->position_comboBox->currentData().toUInt();
    if(!fname.isEmpty()
        && !lname.isEmpty()
        && !phone.isEmpty()
        && !email.isEmpty())
    {
        bool is_inserted = DatabaseManager::insertToDB(DatabaseManager::TABLE::EMPLOYEES,
                                                       std::tie(fname, lname, phone, email, date_of_B
                                                                , hire_date, department_id, position_id));
        if(is_inserted){
            ui->incorrect_data_label->setVisible(true);
        }else{
            ui->incorrect_data_label->setVisible(false);
            clearWidgets();
        }
    }else{
        ui->incorrect_data_label->setVisible(true);
    }
}

void InsertEmployeeDialog::clearWidgets(){
    ui->first_name_lineEdit->clear();
    ui->last_name_lineEdit->clear();
    ui->phone_lineEdit->clear();
    ui->email_lineEdit->clear();
    ui->department_comboBox->setCurrentIndex(0);
    ui->position_comboBox->setCurrentIndex(0);
}
