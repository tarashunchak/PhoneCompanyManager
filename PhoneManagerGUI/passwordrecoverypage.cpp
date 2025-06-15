#include "includes/passwordrecoverypage.h"
#include "ui_passwordrecoverypage.h"
#include <QSqlQuery>
#include <QRandomGenerator>

PasswordRecoveryPage::PasswordRecoveryPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PasswordRecoveryPage)
    , file("email_template_text.txt")
{
    ui->setupUi(this);
    ui->return_to_login_btn->setIcon(QIcon{"./img/exit.png"});
    process.setParent(this);
    connect(ui->confirm_btn, &QPushButton::clicked
            , this, &PasswordRecoveryPage::SendMessageToEmail);
    ui->code_LineEdit->setVisible(false);
    ui->error_message->setVisible(false);
    ui->check_code_btn->setVisible(false);
}

PasswordRecoveryPage::~PasswordRecoveryPage()
{
    delete ui;
}
static void clearWidgets(const Ui::PasswordRecoveryPage* ui){
    ui->recovery_widget->setVisible(false);
    ui->confirmed_widget->setVisible(true);
    ui->confirm_btn->setVisible(true);
    ui->check_code_btn->setVisible(false);
    ui->new_pass_LineEdit->clear();
    ui->repeated_pass_LineEdit->clear();
    ui->code_LineEdit->clear();
    ui->email_LineEdit->clear();
}

void PasswordRecoveryPage::RecoverPassword(const uint empl_id)const{
    QSqlQuery query(QSqlDatabase::database("remote"));
    if(ui->new_pass_LineEdit->text() == ui->repeated_pass_LineEdit->text()
        && ui->repeated_pass_LineEdit->text().size() > 8)
    {
        ui->error_message->setVisible(false);
        query.prepare("UPDATE users "
                      "SET password = :new_pass "
                      "WHERE empl_id = :empl_id;");
        query.bindValue(":new_pass", ui->repeated_pass_LineEdit->text());
        query.bindValue(":empl_id", empl_id);
        query.exec();
        clearWidgets(ui);
        void on_return_to_login_btn_clicked();
    }else{
        ui->error_message->setText("Password must contain at least 8 charachters");
        ui->error_message->setVisible(true);
    }
}

void PasswordRecoveryPage::SendMessageToEmail(){
    static QString code{};
    static QSqlQuery query(QSqlDatabase::database("remote"));
    QString email = ui->email_LineEdit->text();
    query.prepare("SELECT * FROM employees WHERE email = :email;");
    query.bindValue(":email", email);

    if(query.exec() && query.next()){
        const uint empl_id = query.value("id").toUInt();
        ui->code_LineEdit->setVisible(true);
        if(!file.is_open()){
            qDebug() << "cannot open file";
            return;
        }
        code = "";
        for (int i = 0; i < 6; i++)
            code += QString::number(QRandomGenerator::global()->bounded(10));

        file << "From: tarashunchak43214321@gmail.com\r\n";
        file << "To: " + email.toStdString() + "\r\n";
        file << "Subject: Password Recovery\r\n";
        file << "\r\n";
        file << "Dear Team Member,\n"
                "A password reset has been requested for your account. Use the following verification code to proceed:\n"
                "Password recovery code: " + code.toStdString() + "\r\n"
                "For security reasons, do not share this code with anyone.\n"
                "No administrator or colleague will ever ask you for this code. If you did not request a password reset,\n"
                "please report this to the system administrator immediately.";

        QString empl_full_name = query.value("first_name").toString() + ' '
                     + query.value("last_name").toString();

        QStringList commands;
        commands << "--ssl-reqd"
        << "--url" << "smtps://smtp.gmail.com:465"
        << "--user" << "tarashunchak43214321@gmail.com:tmsfwvwyqikicioz"
        << "--mail-from" << "tarashunchak43214321@gmail.com"
        << "--mail-rcpt" << email
        << "--upload-file" << "./email_template_text.txt";

        process.start("curl", commands);
        process.waitForFinished();
        qDebug() << "Curl exit code:" << process.exitCode();
        qDebug() << "Curl output:" << process.readAllStandardOutput();
        qDebug() << "Curl error:" << process.readAllStandardError();
        ui->confirm_btn->setVisible(false);
        ui->check_code_btn->setVisible(true);
        connect(ui->check_code_btn, &QPushButton::clicked, this, [this, empl_id](){
            if(ui->code_LineEdit->text() == code){
                ui->error_message->setVisible(false);
                ui->email_LineEdit->clear();
                ui->code_LineEdit->clear();
                RecoverPassword(empl_id);
                ui->confirm_btn->setVisible(true);
                ui->check_code_btn->setVisible(false);
            }else{
                ui->error_message->setText("Incorrect code");
                ui->error_message->setVisible(true);
            }
        });
    }else{
        ui->error_message->setText("There is no employee with this email!");
        ui->error_message->setVisible(true);
    }
    file.close();
}
