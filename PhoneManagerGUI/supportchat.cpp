#include "includes/supportchat.h"
#include "ui_supportchat.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include "includes/messagebox.h"
#include <QScrollBar>
#include "includes/currentuser.h"
#include <QTimer>
#include "includes/databasemanager.h"

extern void clearLayout(QLayout* layout);

//ChatUnits struct
bool SupportChat::ChatUnits::is_chat_exist = false;
uint SupportChat::ChatUnits::partner_id = 0u;
uint SupportChat::ChatUnits::chat_id = 0u;
uint SupportChat::ChatUnits::my_participant_id = 0u;
uint SupportChat::ChatUnits::partner_participant_id = 0u;
uint SupportChat::ChatUnits::last_message_id = 0u;

/*-----------------------------*/
bool SupportChat::is_valid_partner = false;

void SupportChat::ChatUnits::reset(){
    is_chat_exist = false;
    partner_id = 0;
    chat_id = 0;
    my_participant_id = 0;
    partner_participant_id = 0;
}

SupportChat::SupportChat(QFrame *parent)
    : QFrame (parent)
    , ui(new Ui::ChatUI)
    , scrollArea(new QScrollArea{})
    , mainWidget(new QWidget{})
    , innerVBoxLayout(new QVBoxLayout{})
{
    ui->setupUi(this);
    ui->phone_lineEdit->setVisible(false);
    ui->send_btn->setIcon(QIcon{"./img/paper-plane.svg"});
    connect(ui->send_btn, &QPushButton::clicked, this, &SupportChat::SendMessage);
    connect(ui->lineEdit, &QLineEdit::editingFinished, this, &SupportChat::SendMessage);
    innerVBoxLayout->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    mainWidget->setLayout(innerVBoxLayout);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(mainWidget);
    scrollArea->verticalScrollBar()->setVisible(true);
    ui->verticalLayout->addWidget(scrollArea);
    this->setWindowTitle("Interactive SupportChat");
    phone_choose_handler();
    this->setWindowFlags(Qt::Widget | Qt::CustomizeWindowHint);
}

SupportChat::~SupportChat(){
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

void SupportChat::SendMessage(){
    if(is_valid_partner){
        if(!is_all_chars_empty(ui->lineEdit->text())
                || !is_all_chars_empty(ui->phone_btn->text()))
            return;
        DatabaseManager::sendMessage<SupportChat>(ui->lineEdit->text());
        ui->lineEdit->clear();
        DisplayLastMessage();
    }
}

void SupportChat::DisplayAllMessages(QSqlQuery& query){
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
    }

    QTimer::singleShot(100, this, [this](){
        ScrollDown_ScrollBar(scrollArea->verticalScrollBar());
    });
}

void SupportChat::DisplayLastMessage()const{
    ui->empty_chat_label->setVisible(false);
    MessageBox* message = new MessageBox{DatabaseManager::lastMessage<DatabaseManager::PAGE::SUPPORT_CHAT>()};
    if(!message){
        qDebug() << "display all messages fault";
        return;
    }
    innerVBoxLayout->addWidget(message);
    mainWidget->adjustSize();
    mainWidget->updateGeometry();
    QTimer::singleShot(100, this, [this](){
        ScrollDown_ScrollBar(scrollArea->verticalScrollBar());
    });
}

void SupportChat::phone_choose_handler(){
    connect(ui->phone_btn, &QPushButton::clicked, this, [this](){
        ui->phone_btn->setVisible(false);
        ui->phone_btn->setText("Chose phone number");
        ui->phone_lineEdit->setVisible(true);
        ui->phone_lineEdit->setFocus();
    });
    connect(ui->phone_lineEdit, &QLineEdit::editingFinished, this, [this](){
        clearLayout(innerVBoxLayout);
        SetPhoneNumber(ui->phone_lineEdit->text());
    });
}

bool SupportChat::is_exist(){
    QSqlQuery query(QSqlDatabase::database("local"));
    query.prepare("SELECT ch.id AS CHAT_ID, "
                  "p_cust.id AS P1_ID, p_empl.id AS P2_ID "
                  "FROM chats ch "
                  "JOIN chat_participants cp_cust ON cp_cust.chat_id = ch.id "
                  "JOIN participants p_cust ON p_cust.id = cp_cust.participants_id "
                  "JOIN chat_participants cp_empl ON cp_empl.chat_id = ch.id "
                  "JOIN participants p_empl ON p_empl.id = cp_empl.participants_id "
                  "WHERE ch.is_corporate = false "
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
        ChatUnits::is_chat_exist = false;
        return false;
    }
    ui->empty_chat_label->setVisible(false);
    ChatUnits::is_chat_exist = true;
    ChatUnits::chat_id = query.value("CHAT_ID").toUInt();
    scrollArea->verticalScrollBar()->setVisible(true);
    query = DatabaseManager::allMessagesFromCurrentChat<SupportChat>();
    DisplayAllMessages(query);
    scrollArea->verticalScrollBar()->setValue(ui->verticalLayout->count());
    scrollArea->verticalScrollBar()->setVisible(false);
    return true;
}

void SupportChat::SetPhoneNumber(const QString& phone){
    auto record = DatabaseManager::selectRecord<DatabaseManager::TABLE::CUSTOMERS>("phone", phone);

    if(!record.exec()){
        ui->empty_chat_label->setVisible(true);
        ui->phone_btn->setText("Chose phone number");
        ui->phone_lineEdit->setVisible(false);
        ui->phone_btn->setVisible(true);
        is_valid_partner = false;
        return;
    }
    if(!record.next()){
        ui->empty_chat_label->setVisible(true);
        ui->phone_btn->setText("Chose phone number");
        ui->phone_lineEdit->setVisible(false);
        ui->phone_btn->setVisible(true);
        is_valid_partner = false;
        return;
    }

    ChatUnits::partner_id = record.value("id").toUInt();
    ui->empty_chat_label->setVisible(false);
    is_valid_partner = true;
    ui->phone_btn->setText(phone);
    is_exist();

    ui->phone_lineEdit->setVisible(false);
    ui->phone_btn->setText(phone);
    ui->phone_btn->setVisible(true);
}
