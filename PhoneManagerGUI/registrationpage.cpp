#include "includes/registrationpage.h"
#include "ui_registrationpage.h"

RegistrationPage::RegistrationPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegistrationPage)
    , reg_manager(new RegistrationManager)
{
    ui->setupUi(this);
    ui->confirmed_widget->setVisible(false);
    ui->error_message->setVisible(false);
    ui->error_message->setAlignment(Qt::AlignCenter);

    ui->return_to_login_btn->setStyleSheet("background-color:transparent;background: url(./img/exit.png);");

    SetConnections();
}

RegistrationPage::~RegistrationPage()
{
    delete ui;
}

void RegistrationPage::SetConnections(){
    connect(ui->email_LineEdit, &QLineEdit::textEdited, ui->error_message, &QLabel::clear);
    connect(ui->confirm_btn, &QPushButton::clicked, this, [this](){
        if(ui->confirmed_widget->isVisible()){
            if(ui->password_LineEdit->text() == ui->rep_password_LineEdit->text()){
                reg_manager->registerNewUser(ui->username_LineEdit->text()
                                            , ui->password_LineEdit->text());
            }else{
                ui->error_message->setText("Passwords did not match!");
                ui->error_message->setVisible(true);
            }
        }else{
            reg_manager->is_exist(ui->email_LineEdit->text());
        }
    });
    connect(reg_manager, &RegistrationManager::employee_not_founded, this, [this](){
        ui->error_message->setVisible(true);
        ui->error_message->setText("There is no employee with this email!");
    });
    connect(reg_manager, &RegistrationManager::employee_is_founded, this, [this](){
        ui->confirm_btn->setGeometry(800, 700, 320, 40);
        ui->error_message->setVisible(false);
        ui->confirmed_widget->setVisible(true);
    });
    connect(reg_manager, &RegistrationManager::not_allowed_to_registration, this, [this](){
        ui->error_message->setText("You are not allowed to registration!");
        ui->error_message->setVisible(true);
    });
    connect(reg_manager, &RegistrationManager::successful_registration, this, [this](){
        emit successful_registration();
    });
    connect(this, &RegistrationPage::on_return_to_login_btn_clicked, this, [this](){
        ui->confirm_btn->setGeometry(800, 590, 320, 40);
        ui->confirmed_widget->setVisible(false);
        ui->email_LineEdit->clear();
        ui->password_LineEdit->clear();
        ui->rep_password_LineEdit->clear();
    });
}
