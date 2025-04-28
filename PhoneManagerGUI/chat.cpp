#include "includes/chat.h"
#include "ui_chat.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include "messagebox.h"
#include <QScrollBar>
#include "includes/currentuser.h"

ChatUI::ChatUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatUI)
    , scrollArea(new QScrollArea{})
    , mainWidget(new QWidget{})
    , innerVBoxLayout(new QVBoxLayout{})
{
    ui->setupUi(this);
    ui->phone_lineEdit->setVisible(false);
    ui->send_btn->setIcon(QIcon{"./img/paper-plane.svg"});
    connect(ui->send_btn, &QPushButton::clicked, this, &ChatUI::SendMessage);
    innerVBoxLayout->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    mainWidget->setLayout(innerVBoxLayout);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(mainWidget);
    scrollArea->verticalScrollBar()->setVisible(false);
    ui->verticalLayout->addWidget(scrollArea);

    phone_choose_handler();
}

ChatUI::~ChatUI()
{
    delete ui;
}

void ChatUI::SendMessage(){
    if(ui->lineEdit->text().isEmpty()){
        return;
    }

    int i = 0;
    for(const auto& ch : ui->lineEdit->text().toStdString()){
        if(ch != ' '){
            break;
        }
        else{
            ++i;
        }
    }
    //if all of characters is empty -> return!
    if(i == ui->lineEdit->text().length()){
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Messages(message_text, date_time, origin, destination) "
                  "VALUES(:message, :date, :origin, :dest);");
    query.bindValue(":message", ui->lineEdit->text());
    query.bindValue(":date", QDateTime::currentDateTime().toString());
    query.bindValue(":origin", CurrentUser::getCurrentUserID());
    query.bindValue(":dest", current_number);
    ui->lineEdit->clear();
    if(!query.exec()){
        qDebug() << "SendMessaget()const fault!: " << query.lastError();
    }
    DisplayAllMessages();
}

void ChatUI::DisplayAllMessages(QSqlQuery query){
    if(!query.exec()){
        qDebug() << "DisplayAllMessages()const fault!: " << query.lastError();
        return;
    }
    QLayout* layout = innerVBoxLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
        layout = nullptr;
    }
    while(query.next()){
        QString message_text{query.value("message_text").toString()};
        QString message_date_time{query.value("date_time").toString()};
        MessageBox* message = new MessageBox{};
        message->SetMessageText(message_text);
        message->SetMessageDateTime(message_date_time);
        innerVBoxLayout->addWidget(message);
    }
}

void ChatUI::DisplayLastMessage()const{

}

void ChatUI::phone_choose_handler(){
    connect(ui->phone_btn, &QPushButton::clicked, this, [this](){
        ui->phone_btn->setVisible(false);
        ui->phone_btn->setText("Chose phone number");
        ui->phone_lineEdit->setVisible(true);
    });
    connect(ui->phone_lineEdit, &QLineEdit::editingFinished, this, [this](){
        if(is_exist(ui->phone_lineEdit->text())){
            ui->phone_btn->setVisible(true);
            ui->phone_btn->setText(ui->phone_lineEdit->text());
            //ui->phone_lineEdit->clear();
            ui->phone_lineEdit->setVisible(false);
        }else{
            ui->phone_btn->setVisible(false);
            ui->phone_btn->setText("Chose phone number");
            ui->phone_lineEdit->setVisible(true);
            //ui->phone_lineEdit->clear();
        }
    });
}

bool ChatUI::is_exist(QString dest_number){
    QSqlQuery query;
    query.prepare("SELECT *FROM Messages WHERE destination = :dest AND origin = :origin;");
    query.bindValue(":dest", dest_number);
    query.bindValue(":origin", CurrentUser::getCurrentUserID());
    if(!query.exec()){
        qDebug() << "Ooh nooo";
        ui->phone_btn->setVisible(false);
        ui->phone_btn->setText("Chose phone number");
        ui->phone_lineEdit->setVisible(true);
        current_number.clear();
        return false;
    }
    current_number = dest_number;
    DisplayAllMessages(std::move(query));
    return true;
}
