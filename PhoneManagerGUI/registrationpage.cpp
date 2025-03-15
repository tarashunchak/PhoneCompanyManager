#include "registrationpage.h"
#include "ui_registrationpage.h"

RegistrationPage::RegistrationPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegistrationPage)
{
    ui->setupUi(this);
}

RegistrationPage::~RegistrationPage()
{
    delete ui;
}
