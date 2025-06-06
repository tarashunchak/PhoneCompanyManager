#include "includes/chat.h"
#include "ui_chat.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include "includes/messagebox.h"
#include <QScrollBar>
#include "includes/currentuser.h"
#include <QTimer>

Chat::Chat(QFrame *parent)
    : QFrame (parent)
    , ui(new Ui::ChatUI)
    , scrollArea(new QScrollArea{})
    , mainWidget(new QWidget{})
    , innerVBoxLayout(new QVBoxLayout{})
{
    ui->setupUi(this);
    ui->phone_lineEdit->setVisible(false);
    ui->send_btn->setIcon(QIcon{"./img/paper-plane.svg"});
    ui->mode_btn->setIcon(QIcon{"img/support.svg"});
    connect(ui->send_btn, &QPushButton::clicked, this, &Chat::SendMessage);
    connect(ui->lineEdit, &QLineEdit::editingFinished, this, &Chat::SendMessage);
    innerVBoxLayout->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    mainWidget->setLayout(innerVBoxLayout);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(mainWidget);
    scrollArea->verticalScrollBar()->setVisible(true);
    ui->verticalLayout->addWidget(scrollArea);
    this->setWindowTitle("Interactive Chat");
    phone_choose_handler();
    this->setWindowFlags(Qt::Widget | Qt::CustomizeWindowHint);
}

Chat::~Chat(){
    delete ui;
}

uint Chat::curr_cust_id = 0;

uint Chat::curr_chat_id = 0;

static void ScrollDown_ScrollBar(QScrollBar* sb){
    sb->setValue(sb->maximum());
}

static bool is_all_chars_empty(QString str){
    if(str.isEmpty()){
        return false;
    }else{
        int i = 0;
        for(const auto& ch : str.toStdString()){
            if(ch != ' ')
                break;
            else
                ++i;
        }
        if(i == str.length())
            return false;
    }
    return true;
}

void Chat::SendMessage(){
    if(!is_all_chars_empty(ui->lineEdit->text())
            || !is_all_chars_empty(ui->phone_btn->text()))
    {
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO messages(text, sender_participant_id, chat_id) "
                  "VALUES(:message, :origin_id, :chat_id);");
    query.bindValue(":message", ui->lineEdit->text());
    query.bindValue(":origin_id", CurrentUser::getCurrentUserID());
    query.bindValue(":chat_id", curr_chat_id);
    if(!query.exec()){
        qDebug() << "SendMessaget()const fault!: " << query.lastError();
        return;
    }
    ui->lineEdit->clear();
    DisplayLastMessage();
}

void Chat::DisplayAllMessages(QSqlQuery& query){
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
    int counter = 0;
    while(true){
        if(!query.next()){
            if(counter == 0){
                ui->empty_chat_label->setVisible(true);
            }
            break;
        }
        counter++;
        ui->empty_chat_label->setVisible(false);
        QString message_text{query.value("text").toString()};
        QString message_date_time{query.value("timestamp").toString()};
        MessageBox* message = new MessageBox{};
        message->SetMessageText(message_text);
        message->SetMessageDateTime(message_date_time);
        innerVBoxLayout->addWidget(message);
        mainWidget->adjustSize();
        mainWidget->updateGeometry();
        QTimer::singleShot(100, this, [this](){
            ScrollDown_ScrollBar(scrollArea->verticalScrollBar());
        });
    }
}

void Chat::DisplayLastMessage()const{
    QSqlQuery query;
    query.prepare("SELECT * FROM messages m "
                  "JOIN chats c ON c.id = m.chat_id "
                  "WHERE m.chat_id = :chat_id "
                  "AND c.is_corporate = false "
                  "ORDER BY id DESC LIMIT 1;");
    query.bindValue(":chat_id", curr_chat_id);
    if(!query.exec() || !query.next()){
        qDebug() << "DisplayLastMessage()const query fault!: " << query.lastError();
        return;
    }
    ui->empty_chat_label->setVisible(false);
    QString message_text{query.value("text").toString()};
    QString message_date_time{query.value("timestamp").toString()};
    MessageBox* message= new MessageBox{};
    message->SetMessageText(message_text);
    message->SetMessageDateTime(message_date_time);
    innerVBoxLayout->addWidget(message);
    mainWidget->adjustSize();
    mainWidget->updateGeometry();
    QTimer::singleShot(100, this, [this](){
        ScrollDown_ScrollBar(scrollArea->verticalScrollBar());
    });
}

void Chat::phone_choose_handler(){
    connect(ui->phone_btn, &QPushButton::clicked, this, [this](){
        ui->phone_btn->setVisible(false);
        ui->phone_btn->setText("Chose phone number");
        ui->phone_lineEdit->setVisible(true);
        ui->phone_lineEdit->setFocus();
    });
    connect(ui->phone_lineEdit, &QLineEdit::editingFinished, this, [this](){
        QSqlQuery query;
        query.prepare("SELECT id FROM customers WHERE phone = :phone;");
        query.bindValue(":phone", ui->phone_lineEdit->text());
        query.exec();
        query.next();
        curr_cust_id = query.value("id").toUInt();
        qDebug() << "curr_cust_id = " << curr_cust_id;
        if(is_exist()){
            ui->phone_btn->setVisible(true);
            ui->phone_btn->setText(ui->phone_lineEdit->text());
            ui->phone_lineEdit->setVisible(false);
        }else{
            ui->phone_btn->setVisible(false);
            ui->phone_btn->setText("Chose phone number");
            ui->phone_lineEdit->setVisible(true);
        }
    });
}

bool Chat::is_exist(){
    QSqlQuery query;
    query.prepare("SELECT ch.id AS CHAT_ID FROM chats ch "
                  "JOIN chat_participants cp_cust ON cp_cust.chat_id = ch.id "
                  "JOIN participants p_cust ON p_cust.id = cp_cust.participants_id "
                  "JOIN chat_participants cp_empl ON cp_empl.chat_id = ch.id "
                  "JOIN participants p_empl ON p_empl.id = cp_empl.participants_id "
                  "JOIN messages m ON m.chat_id = ch.id "
                  "WHERE cp.is_corporate = false "
                  "AND p_cust.role = 'customer' "
                  "     AND p_cust.reference_id = :cust_id "
                  "AND p_empl.role = 'employee' "
                  "     AND p_empl.reference_id = :empl_id;");

    query.bindValue(":cust_id", curr_cust_id);
    query.bindValue(":empl_id", CurrentUser::getCurrentUserID());
    if(!query.exec() || !query.next()){
        qDebug() << "Ooh nooo: " << query.lastError();
        ui->phone_btn->setVisible(true);
        ui->phone_btn->setText("Chose phone number");
        ui->phone_lineEdit->setVisible(false);
        ui->empty_chat_label->setVisible(true);
        curr_chat_id = -1;
        return false;
    }
    ui->empty_chat_label->setVisible(false);
    curr_chat_id = query.value("CHAT_ID").toUInt();
    scrollArea->verticalScrollBar()->setVisible(true);
    DisplayAllMessages(query);
    scrollArea->verticalScrollBar()->setValue(ui->verticalLayout->count());
    scrollArea->verticalScrollBar()->setVisible(false);
    return true;
}

void Chat::SetPhoneNumber(const QString& phone){
    QSqlQuery query;
    query.prepare("SELECT id FROM customers WHERE phone = :phone;");
    query.bindValue(":phone", phone);
    query.exec();
    query.next();
    curr_cust_id = query.value("id").toUInt();
    ui->phone_lineEdit->setVisible(false);
    ui->phone_lineEdit->setText(phone);
    ui->phone_btn->setText(phone);
    is_exist();
}
