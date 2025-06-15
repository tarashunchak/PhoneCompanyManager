#include "messagechecker.h"
#include <QtConcurrent/QtConcurrent>
#include <QSqlDatabase>
#include <QSqlQuery>

MessageChecker::MessageChecker(QObject* parrent) : QObject(parrent)
{
    QTimer* timer = new QTimer{this};
    timer->setInterval(2000);
    connect(timer, &QTimer::timeout, this, &MessageChecker::checkForNewMessages);
    timer->start();
}

void MessageChecker::checkForNewMessages(){
    if(chat_id)
        QtConcurrent::run([this](){
            QString thread_id = QString::number(reinterpret_cast<quintptr>(QThread::currentThreadId()));
            QString remote_conn_name = QString{"db_conn_%1"}.arg(thread_id);

            if(QSqlDatabase::contains(remote_conn_name))
                QSqlDatabase::removeDatabase(remote_conn_name);

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
                    return;
                }
                QString query_str = QString{
                                "SELECT MAX(id) AS max_id "
                                "FROM messages "
                                "WHERE chat_id = %1;"}.arg(QString::number(chat_id));
                QSqlQuery query(db_conn);
                query.prepare(query_str);
                if(query.exec() && query.next()){
                    uint max_id = query.value("max_id").toUInt();
                    if(last_message_id < max_id){
                        last_message_id = max_id;
                        emit new_message_detected();
                    }
                }
                query.clear();

                db_conn.close();
            }
            //QSqlDatabase::removeDatabase(remote_conn_name);
        });
}

void MessageChecker::setChatID(const uint id){
    chat_id = id;
}
