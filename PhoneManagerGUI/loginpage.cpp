#include "includes/loginpage.h"
#include "ui_loginpage.h"
#include <QGridLayout>

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
    , authManager(new AuthManager)
{
    ui->setupUi(this);
    ui->incorrect_data_Label->setVisible(false);
    ui->pushButton->setIcon(QIcon{"./img/eye-closed.svg"});
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
        authManager->authenticate(ui->username_LineEdit->text(), ui->password_LineEdit->text());
    });
    connect(authManager, &AuthManager::authSuccess, this, [this](){
        ui->username_LineEdit->clear();
        ui->password_LineEdit->clear();
        emit login_succsess();
    });
    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        if(ui->password_LineEdit->echoMode() == QLineEdit::Password){
            ui->password_LineEdit->setEchoMode(QLineEdit::Normal);
            ui->pushButton->setIcon(QIcon{"./img/opened-eye.svg"});
        }else{
            ui->password_LineEdit->setEchoMode(QLineEdit::Password);
            ui->pushButton->setIcon(QIcon{"./img/eye-closed.svg"});
        }
    });
}
