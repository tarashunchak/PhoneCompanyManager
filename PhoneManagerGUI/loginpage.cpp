#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
    , authManager(new AuthManager)
{
    ui->setupUi(this);
    ui->incorrect_data_Label->setVisible(false);

    setConnections();

}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::setConnections(){
    connect(ui->username_LineEdit, &QLineEdit::textChanged, this, [this](){
        ui->incorrect_data_Label->setVisible(false);
    });
    connect(ui->password_LineEdit, &QLineEdit::textChanged, this, [this](){
        ui->incorrect_data_Label->setVisible(false);
    });
    connect(authManager, &AuthManager::incorrect_login_data, this, [this](){
        ui->incorrect_data_Label->setVisible(true);
    });
    connect(ui->confirm_btn, &QPushButton::clicked, this, [this](){
        authManager->aunthenticate(ui->username_LineEdit->text(), ui->password_LineEdit->text());
    });
    connect(authManager, &AuthManager::authSuccess, this, [this](){
        ui->username_LineEdit->clear();
        ui->password_LineEdit->clear();
        emit login_succsess();
    });

}

