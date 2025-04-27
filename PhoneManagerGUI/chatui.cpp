#include "includes/chatui.h"
#include "ui_chatui.h"
#include <QSqlQuery>
#include <QSqlError>

ChatUI::ChatUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatUI)
{
    ui->setupUi(this);
    ui->send_btn->setIcon(QIcon{"./img/paper-plane.svg"});
    connect(ui->send_btn, &QPushButton::clicked, this, &ChatUI::SendMessage);
}

ChatUI::~ChatUI()
{
    delete ui;
}

void ChatUI::SendMessage()const{
    QSqlQuery query;
    query.prepare("INSERT INTO Messages(message_text, date_time) "
                  "VALUE(:message, :date_time);");
    query.bindValue(":message", ui->lineEdit->text());
    query.bindValue(":date_time", ui->lineEdit->text());
    ui->lineEdit->clear();
    if(!query.exec()){
        qDebug() << "SendMessaget()const fault!: " << query.lastError();
    }
}
