#include "includes/insertemployeedialog.h"
#include "ui_insertemployeedialog.h"
#include <QSqlQuery>
#include <QSqlError>

InsertEmployeeDialog::InsertEmployeeDialog(QDialog* parent)
    : QDialog(parent)
    , ui(new Ui::InsertEmployeeDialog)
{
    ui->setupUi(this);
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
    QSqlQuery query;
    query.prepare("SELECT * FROM Departments;");
    query.exec();
    while(query.next()){
        ui->department_comboBox->addItem(query.value("department_name").toString()
                                         , query.value("id").toInt());
    }

    query.prepare("SELECT * FROM Positions;");
    query.exec();
    while(query.next()){
        ui->position_comboBox->addItem(query.value("position_name").toString()
                                       , query.value("id").toInt());
    }
}

void InsertEmployeeDialog::InsertEmployeeToDB(){
    QString first_name = ui->first_name_lineEdit->text();
    QString last_name = ui->last_name_lineEdit->text();
    QString phone = ui->phone_lineEdit->text();
    QString email = ui->email_lineEdit->text();
    if(!first_name.isEmpty()
        && !last_name.isEmpty()
        && !phone.isEmpty()
        && !email.isEmpty())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO Employees (first_name, last_name, phone, email, hire_date, "
                      "						department_id, position_id, salary) "
                      "VALUES(:fname, :lname, :phone, :email, :hdate, :d_id, :p_id, 0.0);");
        query.bindValue(":fname", first_name);
        query.bindValue(":lname", last_name);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);
        query.bindValue(":hdate", ui->hire_date_dateEdit->dateTime());
        query.bindValue(":d_id", ui->department_comboBox->currentData().toInt());
        query.bindValue(":p_id", ui->position_comboBox->currentData().toInt());

        if(!query.exec())
            qDebug() << "InsertEmployeeDialog::InsertEmployeeToDB() query fault: " << query.lastError();
        else{
            ui->incorrect_data_label->setVisible(false);
            clearWidgets();
            this->close();
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
