#include "includes/chat.h"
#include "ui_chat.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include "includes/messagebox.h"
#include <QScrollBar>
#include "includes/currentuser.h"
#include <QTimer>
#include "includes/databasemanager.h"

//ChatUnits struct
bool Chat::ChatUnits::is_chat_exist = false;
uint Chat::ChatUnits::partner_id = 0;
uint Chat::ChatUnits::chat_id = 0;
uint Chat::ChatUnits::my_participant_id = 0;
uint Chat::ChatUnits::partner_participant_id = 0;

void Chat::ChatUnits::reset(){
    is_chat_exist = false;
    partner_id = 0;
    chat_id = 0;
    my_participant_id = 0;
    partner_participant_id = 0;
}

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
    /*if(!is_all_chars_empty(ui->lineEdit->text())
            || !is_all_chars_empty(ui->phone_btn->text()))
        return;*/
    DatabaseManager::sendMessage<Chat>(ui->lineEdit->text());
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
    ui->empty_chat_label->setVisible(false);
    MessageBox* message = DatabaseManager::lastMessage<DatabaseManager::PAGE::CHAT_PAGE>();
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
        ChatUnits::partner_id = query.value("id").toUInt();
        qDebug() << "curr_cust_id = " << ChatUnits::partner_id;
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
    query.prepare("SELECT ch.id AS CHAT_ID, "
                  "p_cust.id AS P1_ID, p_empl.id AS P2_ID "
                  "FROM chats ch "
                  "JOIN chat_participants cp_cust ON cp_cust.chat_id = ch.id "
                  "JOIN participants p_cust ON p_cust.id = cp_cust.participants_id "
                  "JOIN chat_participants cp_empl ON cp_empl.chat_id = ch.id "
                  "JOIN participants p_empl ON p_empl.id = cp_empl.participants_id "
                  "WHERE ch.is_corporate = 0 "
                  "AND (p_cust.role = 'customer' "
                  "     AND p_cust.reference_id = :cust_id) "
                  "AND (p_empl.role = 'employee' "
                  "     AND p_empl.reference_id = :empl_id);");

    query.bindValue(":cust_id", ChatUnits::partner_id);
    query.bindValue(":empl_id", CurrentUser::getCurrentUserID());
    if(!query.exec() || !query.next()){
        qDebug() << "Ooh nooo: " << query.lastError();
        ui->phone_btn->setVisible(true);
        ui->phone_btn->setText("Chose phone number");
        ui->phone_lineEdit->setVisible(false);
        ui->empty_chat_label->setVisible(true);
        ChatUnits::chat_id = 0;
        return false;
    }
    ui->empty_chat_label->setVisible(false);
    ChatUnits::chat_id = query.value("CHAT_ID").toUInt();
    scrollArea->verticalScrollBar()->setVisible(true);
    query = DatabaseManager::allMessagesFromCurrentChat<Chat>();
    DisplayAllMessages(query);
    scrollArea->verticalScrollBar()->setValue(ui->verticalLayout->count());
    scrollArea->verticalScrollBar()->setVisible(false);
    return true;
}

void Chat::SetPhoneNumber(const QString& phone){
    QSqlQuery query;
    query.prepare("SELECT c.id AS CHAT_ID, "
                  "p1.id AS P1_PART_ID, p2.id AS P2_PART_ID "
                  "FROM chats c "
                  "JOIN chat_participants cp1 ON cp1.chat_id = c.id "
                  "JOIN chat_participants cp2 ON cp2.chat_id = c.id "
                  "JOIN participants p1 ON p1.id  ON cp1.participants_id "
                  "JOIN participants p2 ON p2.id  ON cp2.participants_id "
                  "WHERE ((p1.role = 'employee' AND p2.role = 'customer') "
                  "OR (p1.role = 'customer' AND p2.role = 'employee')) "
                  "AND ((p1.reference_id = :my_id AND p2.reference_id != :my_id) "
                  "OR (p1.reference_id != :my_id AND p2.reference_id = :my_id));"
                  );
    query.bindValue(":my_id", CurrentUser::getCurrentUserID());
    query.exec();
    query.next();
    ChatUnits::partner_id = query.value("").toUInt();
    ui->phone_lineEdit->setVisible(false);
    ui->phone_lineEdit->setText(phone);
    ui->phone_lineEdit->setVisible(true);
    ui->phone_btn->setText(phone);
    is_exist();
}
