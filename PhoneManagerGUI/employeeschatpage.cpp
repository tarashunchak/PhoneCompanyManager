#include "employeeschatpage.h"
#include "ui_employeeschatpage.h"
#include <QSqlQuery>
#include <QSqlError>
#include "includes/currentuser.h"

EmployeesChatPage::EmployeesChatPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesChatPage)
{
    ui->setupUi(this);
    //this->setStyleSheet("background:url(./img/wallpaper_dark.jpg);");
}

EmployeesChatPage::~EmployeesChatPage()
{
    delete ui;
}

void EmployeesChatPage::fillChatsWidget()const{
    QSqlQuery query;
    query.prepare("SELECT c.id AS chat_id, e.first_name AS partner_fname, "
                  "e.last_name AS partner_lname "
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
    QLayout* layout = ui->chats_vLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item;
        }
    }
    while(query.next()){
        const int chat_id = query.value("chat_id").toInt();
        QPushButton* chat_widget = new QPushButton{};
        chat_widget->setMinimumSize(QSize{350, 60});
        chat_widget->setMaximumSize(QSize{350, 60});
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

        QLabel* label = new QLabel{query.value("partner_fname").toString(), chat_widget};
        label->setStyleSheet(
            "QLabel{"
            "	background-color:transparent;"
            "	font-family:Lato, Consolas;"
            "	font-size:16px;"
            "	color:white;"
            "}"
        );
        chat_widget->setContentsMargins(20, 20, 20, 20);

        ui->chats_vLayout->addWidget(chat_widget);
        ui->chats_vLayout->setContentsMargins(10, 0, 0, 0);
        ui->chats_vLayout->setAlignment(Qt::AlignTop);
        connect(chat_widget, &QPushButton::clicked, this, [this, chat_id](){
            fillMessagesWidget(chat_id);
        });
    }
}

void EmployeesChatPage::fillMessagesWidget(const int chat_id)const{
    QSqlQuery query;
    query.prepare("SELECT * FROM messages "
                  "WHERE chat_id = :id;");
    query.bindValue(":id", chat_id);
    if(!query.exec()){
        qDebug() << "fillChatsWidget()const query fault: " << query.lastError();
        return;
    }
    QLayout* layout = ui->messages_vLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item;
        }
    }
    while(query.next()){
        QHBoxLayout* message_hLayout = new QHBoxLayout{};
        QLabel* label = new QLabel{query.value("text").toString()};
        label->setStyleSheet(
            "QLabel{"
            "	background-color: #2b2b2b;"
            "	font-size:14px;"
            "	font-family:Lato, Consolas;"
            "	border-radius:6px;"
            "}"
        );
        label->setContentsMargins(10, 10, 10, 10);
        label->setWordWrap(true);
        label->setMaximumWidth(340);
        if(query.value("sender_id").toInt() == CurrentUser::getCurrentUserID()){
            message_hLayout->addStretch();
            message_hLayout->addWidget(label);
        }else{
            message_hLayout->addWidget(label);
            message_hLayout->addStretch();
        }
        ui->messages_vLayout->addLayout(message_hLayout);
        ui->messages_vLayout->setAlignment(Qt::AlignBottom);
    }
}

void EmployeesChatPage::searchChats()const{
    QSqlQuery query;
    query.prepare("SELECT * FROM ");
}
