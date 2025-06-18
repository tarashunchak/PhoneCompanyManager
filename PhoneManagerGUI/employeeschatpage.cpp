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
uint EmployeesChatPage::ChatUnits::partner_id = 0u;
uint EmployeesChatPage::ChatUnits::chat_id = 0u;
uint EmployeesChatPage::ChatUnits::my_participant_id = 0u;
uint EmployeesChatPage::ChatUnits::partner_participant_id = 0u;
uint EmployeesChatPage::ChatUnits::partner_empl_id = 0u;

void EmployeesChatPage::ChatUnits::reset(){
    is_chat_exist = false;
    partner_id = 0u;
    chat_id = 0u;
    my_participant_id = 0u;
    partner_participant_id = 0u;
}

void chatActive(Ui::EmployeesChatPage*, bool);
void set_last_seen(Ui::EmployeesChatPage*, int);

//EmployeesChatPage methods
EmployeesChatPage::EmployeesChatPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesChatPage)
{
    ui->setupUi(this);

    ui->chats_widget->setParent(ui->chats_scrollArea);
    ui->verticalLayoutWidget->setParent(ui->chats_widget);
    ui->chats_scrollArea->setWidget(ui->chats_widget);

    ui->send_message_btn->setIcon(QIcon{"./img/white_paper_plane.svg"});
    ui->send_message_btn->setIconSize({28, 28});
    ui->empty_chat_widget->setVisible(false);
    ui->message_area_widget->setStyleSheet("background:url(./img/wall_telegram_light.jpg);");
    connect(ui->search_lineEdit, &QLineEdit::textEdited, this, &EmployeesChatPage::searchChats);
    connect(ui->message_input_lineEdit, &QLineEdit::editingFinished, this, &EmployeesChatPage::sendMessage);
    connect(ui->say_hello_btn, &QPushButton::clicked, this, [this]() {
        ui->message_input_lineEdit->setText("HI!!!");
        sendMessage();
    });
    connect(MessageChecker::getChecker(), &MessageChecker::new_message_detected, this, [this](){
        fillMessagesWidget(ChatUnits::chat_id, {});
        emit notify_employee();
    });
    connect(DatabaseManager::getSynchronizer(), &DatabaseSynchronizer::update_info, this
            , &EmployeesChatPage::updateLastSeenTimestamp);

    connect(ui->profile_pic_btn, &QPushButton::clicked, this, [this](){
        if(ChatUnits::is_chat_exist)
            emit on_partner_profile_pic_btn_clicked(ChatUnits::partner_empl_id);
    });

    chatActive(ui, false);
}

EmployeesChatPage::~EmployeesChatPage()
{
    delete ui;
}

void EmployeesChatPage::updateLastSeenTimestamp(){
    QSqlQuery select_query(QSqlDatabase::database("remote"));
    select_query.prepare("SELECT EXTRACT(EPOCH FROM(CURRENT_TIMESTAMP - last_seen)) AS second_ago "
                         "FROM chat_participants "
                         "WHERE participants_id = ?;");
    select_query.addBindValue(ChatUnits::partner_participant_id);
    if(select_query.exec() && select_query.next()){
        int second_ago = select_query.value("second_ago").toInt();
        set_last_seen(ui, second_ago);
    }
}

void set_last_seen(Ui::EmployeesChatPage* ui, int second_ago){
    qDebug() << "update_last_seen";
    QString last_seen_str{"last seen "};
    if(second_ago > 60 && second_ago < 3600){
        last_seen_str += QString::number(int(second_ago / 60)) + " minutes ago";
    }else if(second_ago > 3600 && second_ago < 86400){
        last_seen_str += QString::number(int(second_ago / 3600)) + " hours ago";
    }else if((second_ago / 86400) > 0){
        last_seen_str += QString::number(int(second_ago / 86400)) + " days ago";
    }else{
        last_seen_str += "recently";
    }

    static QString style{
        "font-family:Lato, Arial, Consolas;"
        "font-size:20px;"
    };

    if(second_ago <= 10){
        ui->last_seen_label->setText("online");
        ui->last_seen_label->setStyleSheet(style + "color:lime;");
    }else{
        ui->last_seen_label->setText(last_seen_str);
        ui->last_seen_label->setStyleSheet(style + "color:white;");
    }
}

void clearLayout(QLayout* layout){
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

void chatActive(Ui::EmployeesChatPage* ui, bool is_active){
    ui->last_seen_label->setVisible(is_active);
    ui->empl_full_name_label->setVisible(is_active);
    ui->profile_pic_btn->setVisible(is_active);
    ui->message_input_lineEdit->setVisible(is_active);
    ui->send_message_btn->setVisible(is_active);
    ui->empty_chat_widget->setVisible(false);
}

void EmployeesChatPage::closeCurrentChat(){
    clearLayout(ui->messages_vLayout);
    chatActive(ui, false);
}

void EmployeesChatPage::fillChatsWidget(QSqlQuery query, bool is_search_res){
    if(!is_search_res){
        query = DatabaseManager::MyAllCorporateChats();
        if(!query.exec()){
            qDebug() << "fillChatsWidget()const query fault: " << query.lastError();
            return;
        }
    }

    clearLayout(ui->chats_vLayout);

    while(query.next()){
        const uint tmp_chat_id = !is_search_res ? query.value("chat_id").toInt() : 0u;
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
            "	font-family:Lato, Arial, Consolas;"
            "	font-size:16px;"
            "	color:white;"
            "}"
            );
        const uint partner_part_id = query.value("part_id").toUInt();
        const uint partner_user_id = query.value("user_id").toUInt();
        const uint partner_empl_id = query.value("empl_id").toUInt();
        qDebug() << "fillChatsWidget() partner_user_id = " << partner_user_id;
        qDebug() << "fillChatsWidget() partner_part_id = " << partner_part_id;
        partner_name->setProperty("partner_part_id", partner_part_id);
        partner_name->setProperty("partner_user_id", partner_user_id);
        partner_name->setProperty("partner_empl_id", partner_empl_id);

        ui->chats_vLayout->addWidget(chat_widget);

        connect(chat_widget, &QPushButton::clicked, this, [this, tmp_chat_id, full_name, pixmap, partner_name](){
            if(tmp_chat_id != ChatUnits::chat_id)
                fillMessagesWidget(tmp_chat_id, full_name, partner_name
                                , pixmap.scaled(50, 50, Qt::KeepAspectRatioByExpanding));
        });
    }

    ui->chats_vLayout->setContentsMargins(10, 0, 0, 0);
    ui->chats_vLayout->setAlignment(Qt::AlignTop);
    ui->chats_widget->setLayout(ui->chats_vLayout);
}

void EmployeesChatPage::fillMessagesWidget(const uint chat_id, const QString& full_name
                                           , QLabel* partner_label, QPixmap pixmap)
{
    ChatUnits::chat_id = chat_id;

    if (!full_name.isEmpty())
        ui->empl_full_name_label->setText(full_name);

    if (pixmap.isNull())
        ui->profile_pic_btn->setStyleSheet("background:url(./img/profile_chat.png);");
    else
        ui->profile_pic_btn->setIcon(pixmap);

    clearLayout(ui->messages_vLayout);

    if(partner_label){
        ChatUnits::partner_id = partner_label->property("partner_user_id").toUInt();
        ChatUnits::partner_participant_id = partner_label->property("partner_part_id").toUInt();
        ChatUnits::partner_empl_id = partner_label->property("partner_empl_id").toUInt();
    }

    chatActive(ui, true);
    if(!(ChatUnits::is_chat_exist = static_cast<bool>(chat_id))){
        ui->empty_chat_widget->setVisible(true);
        return;
    }

    qDebug() << "fillMessagesWidget " << ChatUnits::chat_id;

    QSqlQuery message_query(QSqlDatabase::database("remote"));
    message_query.prepare("SELECT m.text AS message_text, "
                          "TO_CHAR(m.timestamp, 'HH24:MI') AS timestamp, "
                          "p.reference_id AS sender_id "
                          "FROM messages m "
                          "JOIN participants p ON p.id = m.sender_participant_id "
                          "WHERE m.chat_id = ?;");
    message_query.addBindValue(ChatUnits::chat_id);


    if (!message_query.exec() && !message_query.next()) {
        qDebug() << "fillChatsWidget() const query fault: " << message_query.lastError();
    }else{
        ChatUnits::is_chat_exist = true;
        qDebug() << "my_id = " << CurrentUser::getCurrentUserID();
        qDebug() << "partner_user_id messages = " << ChatUnits::partner_id;
        qDebug() << "partner_part_id messages = " << ChatUnits::partner_participant_id;
    }
    message_query.previous();
    while (message_query.next()) {
        QHBoxLayout* message_hLayout = new QHBoxLayout{};
        QVBoxLayout* inner_message_vLayout = new QVBoxLayout{};
        QLabel* text_label = new QLabel{message_query.value("message_text").toString()};
        QLabel* time_label = new QLabel{message_query.value("timestamp").toString()};
        time_label->setStyleSheet("font-size:14px;");

        QWidget* widget = new QWidget{};
        inner_message_vLayout->setContentsMargins(10, 12, 10, 10);
        widget->setMaximumWidth(400);
        widget->setMinimumWidth(150);
        widget->setMinimumHeight(50);
        text_label->setWordWrap(true);
        widget->setLayout(inner_message_vLayout);

        if (message_query.value("sender_id").toUInt() == CurrentUser::getCurrentUserID()) {
            message_hLayout->addStretch();
            message_hLayout->addWidget(widget);
            inner_message_vLayout->addWidget(text_label);
            inner_message_vLayout->addWidget(time_label);
            widget->setStyleSheet(
                "QWidget{"
                "	background-color: rgb(95, 85, 160);"
                "	font-size:16px;"
                "	font-family:Lato, Arial, Consolas;"
                "	border-radius:6px;"
                "   color:white;"
                "}"
                );
        } else {
            inner_message_vLayout->addWidget(text_label);
            inner_message_vLayout->addWidget(time_label);
            message_hLayout->addWidget(widget);
            message_hLayout->addStretch();
            widget->setStyleSheet(
                "QWidget{"
                "	background-color: #2b2b2b;"
                "	font-size:16px;"
                "	font-family:Lato, Arial, Consolas;"
                "	border-radius:6px;"
                "   color:white;"
                "}"
                );
        }
        ui->messages_vLayout->addLayout(message_hLayout);
    }
    ui->messages_vLayout->setAlignment(Qt::AlignBottom);

    QSqlQuery partner_query(QSqlDatabase::database("remote"));
    partner_query.prepare("SELECT cp_part.id "
                          "FROM chat_participants cp_part "
                          "JOIN participants p ON p.id = cp_part.participants_id "
                          "WHERE cp_part.chat_id = ? AND p.reference_id = ? "
                          "AND p.role = 'employee';");

    partner_query.addBindValue(ChatUnits::chat_id);
    partner_query.addBindValue(ChatUnits::partner_id);

    if (!partner_query.exec() && !partner_query.next()) {
        ChatUnits::chat_id = 0;
        ChatUnits::is_chat_exist = false;
        ui->empty_chat_widget->setVisible(true);
        qDebug() << "getting partner next id fault!!!";
        return;
    } else {
        ChatUnits::is_chat_exist = true;
        ui->empty_chat_widget->setVisible(false);
    }



    qDebug() << "fill messages user_id: " << ChatUnits::partner_id;

    QTimer::singleShot(500, this, [this](){
        ui->messages_scrollArea->verticalScrollBar()->setValue(
            ui->messages_scrollArea->verticalScrollBar()->maximum());
    });
}

void EmployeesChatPage::searchChats(){
    if(ui->search_lineEdit->text().isEmpty())
        return fillChatsWidget();

    QSqlQuery query(QSqlDatabase::database("remote"));
    query.prepare(
        "SELECT e.first_name AS partner_fname, "
        "e.last_name AS partner_lname, "
        "COALESCE(e.photo, '') AS profile_pic, "
        "u.id AS user_id,"
        "u.empl_id AS empl_id, "
        "p.id AS part_id "
        "FROM participants p "
        "JOIN users u ON u.id = p.reference_id "
        "JOIN employees e ON e.id = u.empl_id "
        "WHERE p.id != :my_part_id "
        "AND (LOWER(e.first_name) LIKE LOWER(:text) "
        "OR LOWER(e.last_name) LIKE LOWER(:text)) "
        "AND e.is_visible = true;"
        );
    query.bindValue(":my_part_id", ChatUnits::my_participant_id);
    query.bindValue(":text", ui->search_lineEdit->text()+"%");
    if(!query.exec()){
        qDebug() << "searchChats() query fault: " << query.lastError();
        return;
    }
    fillChatsWidget(std::move(query), true);
}

void EmployeesChatPage::sendMessage(){
    if(ui->message_input_lineEdit->text().isEmpty() || ChatUnits::partner_id == 0)
        return;
    if(ChatUnits::chat_id == 0)
        qDebug() << "No chat";

    QString text = ui->message_input_lineEdit->text();
    DatabaseManager::sendMessage<EmployeesChatPage>(text);
    ui->message_input_lineEdit->clear();
    qDebug() << "send message to partner_id: " << ChatUnits::partner_id;
    fillChatsWidget();
    fillMessagesWidget(ChatUnits::chat_id, {});
    QTimer::singleShot(300, this, [this](){
        ui->messages_scrollArea->verticalScrollBar()->setValue(
            ui->messages_scrollArea->verticalScrollBar()->maximum());
    });
}
