#include "insertcustomerdialog.h"
#include "ui_insertcustomerdialog.h"
#include <QSqlQuery>

InsertCustomerDialog::InsertCustomerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InsertCustomerDialog)
{
    ui->setupUi(this);
    ui->incorrect_data_label->setVisible(false);
    updateComboBoxData();
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
