#include "messagechecker.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTimer>

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

void MessageChecker::startCheck(){
    if(thread->isRunning()){
        return;
    }
    thread->start();
}

void MessageChecker::checkForNewMessages(){
    if(chat_id > 0){
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
                            "SELECT MAX(id) AS max_id "
                            "FROM messages "
                            "WHERE chat_id = %1;"}.arg(QString::number(chat_id));
            {
                QSqlQuery query(db_conn);
                if(query.exec(query_str) && query.next()){
                    uint max_id = query.value("max_id").toUInt();
                    if(last_message_id < max_id){
                        last_message_id = max_id;
                        emit new_message_detected();
                    }
                }
                query.clear();
            }

            db_conn.close();
        }
        if(QSqlDatabase::contains(remote_conn_name))
            QSqlDatabase::removeDatabase(remote_conn_name);
    }
    emit cycle_finished();
}

void MessageChecker::setChatID(const uint id){
    chat_id = id;
}
