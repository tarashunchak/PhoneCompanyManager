#include "customerspage.h"
#include "ui_customerspage.h"

CustomersPage::CustomersPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersPage)
{
    ui->setupUi(this);
}

CustomersPage::~CustomersPage()
{
    delete ui;
}
