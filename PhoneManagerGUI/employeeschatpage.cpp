#include "employeeschatpage.h"
#include "ui_employeeschatpage.h"
#include <QSqlError>
#include "includes/currentuser.h"
#include <QFile>
#include <QScrollBar>
#include <QTimer>

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
    connect(ui->search_lineEdit, &QLineEdit::textChanged, this, &EmployeesChatPage::searchChats);
    connect(ui->message_input_lineEdit, &QLineEdit::editingFinished, this, &EmployeesChatPage::sendMessage);
}

EmployeesChatPage::~EmployeesChatPage()
{
    delete ui;
}

void EmployeesChatPage::updateLastSeenTimestamp(){
    QSqlQuery query;
    query.prepare("UPDATE chat_participants "
                  "SET last_seen = CURRENT_TIMESTAMP "
                  "WHERE user_id = :my_id;");
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
    if(!query.exec()){
        query.prepare("SELECT u.id AS user_id, c.id AS chat_id, "
                      "e.first_name AS partner_fname, "
                      "e.last_name AS partner_lname, e.photo AS profile_pic "
                      "FROM chats c "
                      "JOIN chat_participants cp1 ON cp1.chat_id = c.id "
                      "JOIN chat_participants cp2 ON cp2.chat_id = c.id "
                      "JOIN users u ON u.id = cp2.user_id "
                      "JOIN employees e ON e.id = u.empl_id "
                      "WHERE cp1.user_id = :my_id AND cp2.user_id != :my_id;");

        query.bindValue(":my_id", CurrentUser::getCurrentUserID());
        if(!query.exec()){
            qDebug() << "fillChatsWidget()const query fault: " << query.lastError();
            return;
        }
    }

    clearLayout(ui->chats_vLayout);

    while(query.next()){
        const int tmp_chat_id = query.value("chat_id").toInt();
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

        QString full_name = query.value("partner_fname").toString() +
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
        partner_name->setProperty("id", partner_id);

        ui->chats_vLayout->addWidget(chat_widget);
        ui->chats_vLayout->setContentsMargins(10, 0, 0, 0);
        ui->chats_vLayout->setAlignment(Qt::AlignTop);
        ui->chats_widget->setLayout(ui->chats_vLayout);
        connect(chat_widget, &QPushButton::clicked, this, [this, tmp_chat_id, full_name, pixmap, partner_name](){
            fillMessagesWidget(tmp_chat_id, full_name, partner_name
                               , pixmap.scaled(50, 50, Qt::KeepAspectRatioByExpanding));
        });
    }
}

void EmployeesChatPage::fillMessagesWidget(const int chat_id, const QString& full_name
                                           , QLabel* partner_label, QPixmap pixmap)
{
    this->chat_id = chat_id;
    QSqlQuery query;
    query.prepare("SELECT * FROM messages "
                  "WHERE chat_id = :chat_id;");
    query.bindValue(":chat_id", this->chat_id);

    if(!query.exec()){
        this->chat_id = 0;
        qDebug() << "fillChatsWidget()const query fault: " << query.lastError();
        return;
    }else{

    clearLayout(ui->messages_vLayout);
    if(partner_label)
        this->user_id = partner_label->property("id").toUInt();

    qDebug() << "my_id = " << CurrentUser::getCurrentUserID();
    qDebug() << "user_id = " << user_id;

    while(query.next()){
        QHBoxLayout* message_hLayout = new QHBoxLayout{};
        QLabel* label = new QLabel{query.value("text").toString()};

        label->setContentsMargins(10, 10, 10, 10);
        label->setWordWrap(true);
        label->setMaximumWidth(340);
        QWidget* widget = new QWidget{};
        if(query.value("sender_id").toUInt() == CurrentUser::getCurrentUserID()){
            message_hLayout->addStretch();
            message_hLayout->addWidget(label);
            label->setStyleSheet(
            "QLabel{"
            "	background-color: rgb(95, 85, 160);"
            "	font-size:16px;"
            "	font-family:Lato, Consolas;"
            "	border-radius:6px;"
            "}"
            );
        }else{
            message_hLayout->addWidget(label);
            message_hLayout->addStretch();
            label->setStyleSheet(
            "QLabel{"
            "	background-color: #2b2b2b;"
            "	font-size:16px;"
            "	font-family:Lato, Arial, Consolas;"
            "	border-radius:6px;"
            "}"
            );
        }
        message_hLayout->addWidget(widget);
        ui->messages_vLayout->addLayout(message_hLayout);
        ui->messages_vLayout->setAlignment(Qt::AlignBottom);
    }
    }
    query.prepare("SELECT u.id AS user_id, cp.last_seen AS ls "
                  "FROM chat_participants cp "
                  "JOIN users u ON u.id = cp.user_id "
                  "WHERE cp.chat_id = :chat_id AND cp.user_id != :my_id;");
    query.bindValue(":chat_id", this->chat_id);
    query.bindValue(":my_id", CurrentUser::getCurrentUserID());
    if(!query.exec()){
        qDebug() << "getting partner id fault!!!";
    }
    if(!query.next()){
        ui->empty_chat_widget->setVisible(true);
        this->chat_id = 0;
        connect(ui->say_hello_btn, &QPushButton::clicked, this, [this](){
            ui->message_input_lineEdit->setText("HI!!!");
            sendMessage();
        });
        qDebug() << "getting partner next id fault!!!";
    }else{
        this->user_id = query.value("user_id").toUInt();
        qDebug() << "user_id fillMessageWidget = " << user_id;
        ui->empty_chat_widget->setVisible(false);
    }

    ui->last_seen_label->setText(query.value("ls").toString());

    if(!full_name.isEmpty())
        ui->empl_full_name_label->setText(full_name);

    if(pixmap.isNull())
        ui->profile_pic_label->setPixmap(QPixmap{"./img/profile_chat.png"});
    else
        ui->profile_pic_label->setPixmap(pixmap);

    ui->profile_pic_label->setStyleSheet(
            "border-radius:25px;"
    );

    qDebug() << "fill messages user_id: " << user_id;
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
    if(ui->message_input_lineEdit->text().isEmpty() || this->user_id == 0)
        return;
    QSqlQuery query;
    if(this->chat_id == 0){
        qDebug() << "No chat";
        query.prepare("INSERT INTO chats(is_corporate) VALUES(true) RETURNING id AS ID;");
        if(!query.exec() || !query.next()){
            qDebug() << "insert into chats query fault: " << query.lastError();
            return;
        }

        this->chat_id = query.value("ID").toInt();
        if(chat_id == 0){
            qDebug() << "chat id == 0";
            return;
        }

        query.prepare("INSERT INTO chat_participants(chat_id, user_id) "
                      "VALUES(:chat_id, :user_id);");
        query.bindValue(":chat_id", this->chat_id);
        query.bindValue(":user_id", this->user_id);
        if(!query.exec()){
            qDebug() << "insert into chat_participants user_id query fault: " << query.lastError();
            return;
        }

        query.prepare("INSERT INTO chat_participants(chat_id, user_id) "
                      "VALUES(:chat_id, :my_id);");
        query.bindValue(":chat_id", this->chat_id);
        query.bindValue(":my_id", CurrentUser::getCurrentUserID());

        if(!query.exec()){
            qDebug() << "insert into chat_participants my_id query fault: " << query.lastError();
            return;
        }
    }
    query.prepare("SELECT c.id "
                  "FROM chats c "
                  "JOIN chat_participants cp1 ON cp1.chat_id = c.id "
                  "JOIN chat_participants cp2 ON cp2.chat_id = c.id "
                  "WHERE cp1.user_id = :user_id AND cp2.user_id = :my_id "
                  "AND c.is_corporate = true;"
                  );
    query.bindValue(":user_id", this->user_id);
    query.bindValue(":my_id", CurrentUser::getCurrentUserID());
    if(!query.exec() || !query.next()){
        qDebug() << "new Chat query fault!";
        return;
    }

    query.prepare("INSERT INTO messages(text, sender_id, chat_id) "
                  "VALUES(:text, :sender_id, :chat_id);");
    query.bindValue(":text", ui->message_input_lineEdit->text());
    query.bindValue(":sender_id", CurrentUser::getCurrentUserID());
    query.bindValue(":chat_id", this->chat_id);
    query.exec();
    ui->message_input_lineEdit->clear();
    qDebug() << "send message user_id: " << this->user_id;
    fillChatsWidget();
    fillMessagesWidget(this->chat_id, {});
    QTimer::singleShot(200, this, [this](){
        ui->messages_scrollArea->verticalScrollBar()->setValue(
                    ui->messages_scrollArea->verticalScrollBar()->maximum());
    });
}
