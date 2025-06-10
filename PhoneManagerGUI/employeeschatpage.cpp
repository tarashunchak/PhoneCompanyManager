#include "employeeschatpage.h"
#include "ui_employeeschatpage.h"
#include <QSqlError>
#include "includes/currentuser.h"
#include <QFile>
#include <QScrollBar>
#include <QTimer>
#include "includes/databasemanager.h"

//ChatUnits struct
bool EmployeesChatPage::ChatUnits::is_chat_exist = false;
uint EmployeesChatPage::ChatUnits::partner_id = 0;
uint EmployeesChatPage::ChatUnits::chat_id = 0;
uint EmployeesChatPage::ChatUnits::my_participant_id = 0;
uint EmployeesChatPage::ChatUnits::partner_participant_id = 0;

void EmployeesChatPage::ChatUnits::reset(){
    is_chat_exist = false;
    partner_id = 0;
    chat_id = 0;
    my_participant_id = 0;
    partner_participant_id = 0;
}

//EmployeesChatPage methods
EmployeesChatPage::EmployeesChatPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesChatPage)
{
    ui->setupUi(this);

    ui->chats_widget->setParent(ui->chats_scrollArea);
    ui->verticalLayoutWidget->setParent(ui->chats_widget);
    ui->chats_scrollArea->setWidget(ui->chats_widget);

    ui->send_message_btn->setIcon(QIcon{"./img/paper-plane.svg"});
    ui->send_message_btn->setIconSize({30, 30});
    ui->empty_chat_widget->setVisible(false);
    ui->message_area_widget->setStyleSheet("background:url(./img/wall_telegram_light.jpg);");
    connect(ui->search_lineEdit, &QLineEdit::textEdited, this, &EmployeesChatPage::searchChats);
    connect(ui->message_input_lineEdit, &QLineEdit::editingFinished, this, &EmployeesChatPage::sendMessage);
     connect(ui->say_hello_btn, &QPushButton::clicked, this, [this]() {
            ui->message_input_lineEdit->setText("HI!!!");
            sendMessage();
        });
}

EmployeesChatPage::~EmployeesChatPage()
{
    delete ui;
}

void EmployeesChatPage::updateLastSeenTimestamp(){
    QSqlQuery query;
    query.prepare("UPDATE chat_participants "
                  "SET last_seen = CURRENT_TIMESTAMP "
                  "WHERE participants_id = :my_id;");
    query.bindValue(":my_id", CurrentUser::getCurrentUserID());
    query.exec();
}

static void clearLayout(QLayout* layout){
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            if(QWidget* widget = item->widget()){
                delete widget;
            }else if(QLayout* childLayout = item->layout()){
                clearLayout(childLayout);
            }
            delete item;
        }
    }
}

void EmployeesChatPage::fillChatsWidget(QSqlQuery query){
    bool is_search_result = true;
    if(!query.isActive()){
        query = DatabaseManager::MyAllCorporateChats();
        if(!query.exec()){
            qDebug() << "fillChatsWidget()const query fault: " << query.lastError();
            return;
        }
        is_search_result = false;
    }

    clearLayout(ui->chats_vLayout);

    while(query.next()){
        const int tmp_chat_id = !is_search_result ? query.value("chat_id").toInt() : 0;
        QPushButton* chat_widget = new QPushButton{};
        chat_widget->setMinimumSize(QSize{340, 60});
        chat_widget->setMaximumSize(QSize{340, 60});
        chat_widget->setStyleSheet(
            "QWidget{"
            "	background-color:transparent;"
            "	font-family:Lato, Consolas;"
            "	font-size:14px;"
            "	color:white;"
            "	border-radius:6px;"
            "}"
            "QWidget:hover{"
            "	background-color:rgba(200, 200, 200, 0.5);"
            "}"
        );

        QLabel* profile_pic = new QLabel{chat_widget};
        profile_pic->setGeometry(5, 5, 50, 50);
        QByteArray byteA{query.value("profile_pic").toByteArray()};

        QPixmap pixmap{};
        pixmap.loadFromData(byteA);

        if(pixmap.isNull()){
            profile_pic->setStyleSheet(
                "background-color:white;"
                "background: url(./img/profile_chat.png);"
                "border-radius:25px;"
            );
        }else{
            profile_pic->setStyleSheet(
                "border-radius:25px;"
            );
            profile_pic->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatioByExpanding));
        }

        QString full_name = query.value("partner_fname").toString()
                            + " " + query.value("partner_lname").toString();
        QLabel* partner_name = new QLabel{full_name};
        partner_name->setParent(chat_widget);
        partner_name->setGeometry(60, 20, 280, 20);
        partner_name->setStyleSheet(
            "QLabel{"
            "	background-color:transparent;"
            "	font-family:Lato, Consolas;"
            "	font-size:16px;"
            "	color:white;"
            "}"
        );

        const uint partner_id = query.value("user_id").toUInt();
        qDebug() << "fillChatsWidget() partner_id = " << partner_id;

        ui->chats_vLayout->addWidget(chat_widget);

        connect(chat_widget, &QPushButton::clicked, this, [this, tmp_chat_id, full_name, pixmap, partner_name, partner_id](){
            fillMessagesWidget(tmp_chat_id, partner_id, full_name, partner_name
                               , pixmap.scaled(50, 50, Qt::KeepAspectRatioByExpanding));
        });
    }

    ui->chats_vLayout->setContentsMargins(10, 0, 0, 0);
    ui->chats_vLayout->setAlignment(Qt::AlignTop);
    ui->chats_widget->setLayout(ui->chats_vLayout);
}

void EmployeesChatPage::fillMessagesWidget(const uint chat_id, const uint partner_id
                                           ,const QString& full_name, QLabel* partner_label, QPixmap pixmap)
{
    ChatUnits::chat_id = chat_id;
    QSqlQuery messageQuery;
    messageQuery.prepare("SELECT m.text AS message_text, p.reference_id AS sender_id "
                         "FROM messages m "
                         "JOIN participants p ON p.id = m.sender_participant_id "
                         "WHERE m.chat_id = :chat_id;");
    messageQuery.bindValue(":chat_id", ChatUnits::chat_id);

    if (!messageQuery.exec()) {
        ChatUnits::chat_id = 0;
        qDebug() << "fillChatsWidget() const query fault: " << messageQuery.lastError();
        return;
    }

    ChatUnits::partner_id = partner_id;

    qDebug() << "my_id = " << CurrentUser::getCurrentUserID();
    qDebug() << "user_id = " << ChatUnits::partner_id;

    uint row = 0;
    while (messageQuery.next()) {
        QHBoxLayout* message_hLayout = new QHBoxLayout{};
        QLabel* label = new QLabel{messageQuery.value("message_text").toString()};
        label->setContentsMargins(10, 10, 10, 10);
        label->setWordWrap(true);
        label->setMaximumWidth(340);
        QWidget* widget = new QWidget{};
        if (messageQuery.value("sender_id").toUInt() == CurrentUser::getCurrentUserID()) {
            message_hLayout->addStretch();
            message_hLayout->addWidget(label);
            label->setStyleSheet(
                "QLabel{"
                "	background-color: rgb(95, 85, 160);"
                "	font-size:16px;"
                "	font-family:Lato, Arial, Consolas;"
                "	border-radius:6px;"
                "   color:white;"
                "}"
                );
        } else {
            message_hLayout->addWidget(label);
            message_hLayout->addStretch();
            label->setStyleSheet(
                "QLabel{"
                "	background-color: #2b2b2b;"
                "	font-size:16px;"
                "	font-family:Lato, Arial, Consolas;"
                "	border-radius:6px;"
                "   color:white;"
                "}"
                );
        }
        message_hLayout->addWidget(widget);
        ui->messages_vLayout->addLayout(message_hLayout);
        row++;
    }
    ui->empty_chat_widget->setVisible(ui->messages_vLayout->isEmpty());
    ui->messages_vLayout->setAlignment(Qt::AlignBottom);

    QSqlQuery partnerQuery;
    partnerQuery.prepare("SELECT u.id AS partner_id, p1.id AS partner_part_id, "
                         "cp_part.last_seen AS ls, p2.id AS my_part_id "
                         "FROM chat_participants cp_part "
                         "JOIN participants p1 ON p1.id = cp_part.participants_id "
                         "JOIN users u ON u.id = p1.reference_id "
                         "JOIN chat_participants cp_me ON cp_me.chat_id = cp_part.chat_id "
                         "JOIN participants p2 ON p2.id = cp_me.participants_id "
                         "WHERE cp_part.chat_id = :chat_id AND p1.reference_id = :cust_id "
                         "AND p2.reference_id = :my_id "
                         "AND (p1.role = 'employee' AND p2.role = 'employee');");
    partnerQuery.bindValue(":chat_id", ChatUnits::chat_id);
    partnerQuery.bindValue(":my_id", CurrentUser::getCurrentUserID());
    partnerQuery.bindValue(":cust_id", ChatUnits::partner_id);

    if (!partnerQuery.exec()) {
        qDebug() << "getting partner id fault!!!" << partnerQuery.lastError().text();
    }

    if (!partnerQuery.next()) {
        ui->empty_chat_widget->setVisible(true);
        ChatUnits::chat_id = 0;
        qDebug() << "getting partner next id fault!!!";
        return;
    } else {
        ChatUnits::my_participant_id = partnerQuery.value("my_part_id").toUInt();
        ChatUnits::partner_participant_id = partnerQuery.value("partner_part_id").toUInt();
        ChatUnits::partner_id = partnerQuery.value("partner_id").toUInt();
        ui->last_seen_label->setText(partnerQuery.value("ls").toString());
        ui->empty_chat_widget->setVisible(false);
    }

    if (!full_name.isEmpty())
        ui->empl_full_name_label->setText(full_name);

    if (pixmap.isNull())
        ui->profile_pic_label->setPixmap(QPixmap{"./img/profile_chat.png"});
    else
        ui->profile_pic_label->setPixmap(pixmap);

    ui->profile_pic_label->setStyleSheet("border-radius:25px;");
    qDebug() << "fill messages user_id: " << ChatUnits::partner_id;
}

void EmployeesChatPage::searchChats(){
    if(ui->search_lineEdit->text().isEmpty())
        return fillChatsWidget();

    QSqlQuery query;
    query.prepare(
        "SELECT e.first_name AS partner_fname, "
        "e.last_name AS partner_lname, "
        "e.photo AS profile_pic, "
        "e.id AS empl_id, "
        "u.id AS user_id "
        "FROM users u "
        "JOIN employees e ON e.id = u.empl_id "
        "WHERE u.id != :my_id "
        "AND (LOWER(e.first_name) LIKE LOWER(:text) "
        "OR LOWER(e.last_name) LIKE LOWER(:text));"
    );
    query.bindValue(":my_id", CurrentUser::getCurrentUserID());
    query.bindValue(":text", ui->search_lineEdit->text()+"%");
    if(!query.exec()){
        qDebug() << "searchChats() query fault: " << query.lastError();
        return;
    }
    fillChatsWidget(std::move(query));
}

void EmployeesChatPage::sendMessage(){
    if(ui->message_input_lineEdit->text().isEmpty() || ChatUnits::partner_id == 0)
        return;
    if(ChatUnits::chat_id == 0)
        qDebug() << "No chat";

    DatabaseManager::sendMessage<EmployeesChatPage>(ui->message_input_lineEdit->text());
    ui->message_input_lineEdit->clear();
    qDebug() << "send message to partner_id: " << ChatUnits::partner_id;
    fillChatsWidget();
    fillMessagesWidget(ChatUnits::chat_id, ChatUnits::partner_id, {});
    QTimer::singleShot(200, this, [this](){
        ui->messages_scrollArea->verticalScrollBar()->setValue(
                    ui->messages_scrollArea->verticalScrollBar()->maximum());
    });
}
