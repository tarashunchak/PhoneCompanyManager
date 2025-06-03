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
}

PasswordRecoveryPage::~PasswordRecoveryPage()
{
    delete ui;
}

void PasswordRecoveryPage::SendMessageToEmail(){
    static QString code{};
    static QSqlQuery query;
    QString email = ui->email_LineEdit->text();
    query.prepare("SELECT * FROM employees WHERE email = :email;");
    query.bindValue(":email", email);

    if(query.exec() && query.next()){
        if(!file.open(QIODevice::WriteOnly)){
            qDebug() << "cannot open file";
            return;
        }
        code = "";
        for (int i = 0; i < 6; i++) {
            code += QString::number(QRandomGenerator::global()->bounded(10));
        }
        QTextStream emailFile(&file);
        emailFile << "From: tarashunchak43214321@gmail.com\r\n";
        emailFile << "To: " + email + "\r\n";
        emailFile << "Subject: Password Recovery\r\n";
        emailFile << "\r\n";
        emailFile << "Dear Team Member,\n"
                     "A password reset has been requested for your account. Use the following verification code to proceed:\n"
                     "Password recovery code: " + code + "\r\n"
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
        << "--upload-file" << "/email_tamplate_text.txt";

        process.start("curl", commands);
        process.waitForFinished();
        qDebug() << "Curl exit code:" << process.exitCode();
        qDebug() << "Curl output:" << process.readAllStandardOutput();
        qDebug() << "Curl error:" << process.readAllStandardError();

        if(ui->code_LineEdit->text() == code){

        }
    }
    file.close();
}
