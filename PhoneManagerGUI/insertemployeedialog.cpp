#include "insertemployeedialog.h"
#include "ui_insertemployeedialog.h"

InsertEmployeeDialog::InsertEmployeeDialog(QDialog* parent)
    : QDialog(parent)
    , ui(new Ui::InsertEmployeeDialog)
{
    ui->setupUi(this);
    this->setMinimumSize(500, 330);
    this->setMaximumSize(500, 330);
}

InsertEmployeeDialog::~InsertEmployeeDialog()
{
    delete ui;
}
