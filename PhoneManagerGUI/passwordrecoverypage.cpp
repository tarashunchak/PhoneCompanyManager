#include "passwordrecoverypage.h"
#include "ui_passwordrecoverypage.h"

PasswordRecoveryPage::PasswordRecoveryPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PasswordRecoveryPage)
{
    ui->setupUi(this);
}

PasswordRecoveryPage::~PasswordRecoveryPage()
{
    delete ui;
}
