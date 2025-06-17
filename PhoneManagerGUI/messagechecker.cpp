#include "messagechecker.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTimer>
#include "includes/currentuser.h"
#include "employeeschatpage.h"
#include <QApplication>
#include "includes/navigationmanager.h"

MessageChecker::MessageChecker(QObject* parrent)
    : QObject{parrent}
    , thread{new QThread{this}}
{
    connect(thread, &QThread::started, this, &MessageChecker::checkForNewMessages);
    connect(this, &MessageChecker::cycle_finished, this, [this](){
        QTimer::singleShot(5000, this, [this](){
            if(!thread->isRunning())
                thread->start();
            checkForNewMessages();
        });
    });
    moveToThread(thread);
}

MessageChecker::~MessageChecker(){
    if(thread->isRunning()){
        thread->quit();
        thread->wait();
    }
}

const MessageChecker* MessageChecker::getChecker(){
    static MessageChecker* checker = new MessageChecker{};
    checker->startCheck();
    return checker;
}

void MessageChecker::startCheck(){
    if(thread->isRunning()){
        return;
    }
    thread->start();
}

void MessageChecker::checkForNewMessages(){
    qDebug() << "check for new message";
    QString remote_conn_name = QString{"db_conn"};

    {
        QSqlDatabase db_conn = QSqlDatabase::addDatabase("QPSQL", remote_conn_name);
        db_conn.setHostName("ep-divine-sun-a83zg48v-pooler.eastus2.azure.neon.tech");
        db_conn.setPort(5432);
        db_conn.setDatabaseName("neondb");
        db_conn.setUserName("neondb_owner");
        db_conn.setPassword("npg_qILNuP6Diz1Z");
        db_conn.setConnectOptions("sslmode=require");
        if(!db_conn.open()){
            qDebug() << "cannot open check database";
            if(QSqlDatabase::contains(remote_conn_name))
                QSqlDatabase::removeDatabase(remote_conn_name);
            return;
        }
        QString query_str = QString{
                        "SELECT m.id AS max_id, "
                        "m.sender_participant_id AS sender_id "
                        "FROM messages m "
                        "JOIN chat_participants cp ON m.chat_id = cp.chat_id "
                        "WHERE cp.participants_id = %1 "
                        "ORDER by m.id DESC LIMIT 1;"}.arg(EmployeesChatPage::ChatUnits::my_participant_id);
        {
            QSqlQuery query(db_conn);
            if(query.exec(query_str) && query.next()){
                uint max_id = query.value("max_id").toUInt();
                if(last_message_id < max_id){
                    qDebug() << "message received";
                    last_message_id = max_id;
                    if(query.value("sender_id").toUInt() != CurrentUser::getCurrentEmployeeID()){
                        if(!NavigationManager::is_chat_page)
                            QApplication::beep();
                        emit notify_employee();
                    }
                    emit new_message_detected();
                }
            }else{
                qDebug() << "kjaslkfdjhldskfjhlsadkjfhlsdkjf";
            }
            query.clear();
        }
        db_conn.close();
    }
    if(QSqlDatabase::contains(remote_conn_name))
        QSqlDatabase::removeDatabase(remote_conn_name);
    emit cycle_finished();
}
