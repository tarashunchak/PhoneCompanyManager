#include "databasesynchronizer.h"
#include "includes/databasemanager.h"
#include <QTimer>

DatabaseSynchronizer::DatabaseSynchronizer(QObject* parent)
    : QObject{parent}
    , thread{new QThread{this}}
{
    connect(thread, &QThread::started, this, &DatabaseSynchronizer::syncAllTables);
    connect(this, &DatabaseSynchronizer::sync_finished, this, [this]() {
        //qDebug() << "Sync finished, waiting to restart...";
        QTimer::singleShot(5000, this, [this]() {
            if (!thread->isRunning()) {
                thread->start();
            }
            emit update_info();
            syncAllTables();
        });
    });

    moveToThread(thread);
}

DatabaseSynchronizer::~DatabaseSynchronizer(){
    if(thread->isRunning()){
        thread->quit();
        thread->wait();
    }
}

void DatabaseSynchronizer::startSync(const QList<TABLE>& tables){
    if(thread->isRunning()){
        //qDebug() << "thread is running";
        return;
    }

    //qDebug() << "startSync";
    this->tables = tables;
    thread->start();
}

void DatabaseSynchronizer::syncAllTables(){
    static QString remote_conn_name = QString{"remote_sync"};
    static QString local_conn_name = QString{"local_sync"};
    QSqlDatabase local_sync = QSqlDatabase::addDatabase("QSQLITE", local_conn_name);
    local_sync.setDatabaseName("./database/database.db");

    QSqlDatabase remote_sync = QSqlDatabase::addDatabase("QPSQL", remote_conn_name);
    remote_sync.setHostName("ep-divine-sun-a83zg48v-pooler.eastus2.azure.neon.tech");
    remote_sync.setPort(5432);
    remote_sync.setDatabaseName("neondb");
    remote_sync.setUserName("neondb_owner");
    remote_sync.setPassword("npg_qILNuP6Diz1Z");
    remote_sync.setConnectOptions("sslmode=require");

    remote_sync.open();
    local_sync.open();

    for (auto table : tables) {
        QString table_str = DatabaseManager::tableToString(table);
        //qDebug() << "sync table " + table_str;

        if (!remote_sync.isOpen() || !local_sync.isOpen()) {
            //qDebug() << "Database not opened: " << remote_sync.lastError();
            return;
        }

        QString query_str = "SELECT * FROM " + table_str + ";";

        {
            QSqlQuery remote_query(remote_sync);
            if (!remote_query.prepare(query_str) || !remote_query.exec()) {
                //qDebug() << "Error to exec remote query";
                return;
            }

            {
                QSqlQuery clear_sqlite_query(local_sync);
                if (!clear_sqlite_query.exec("DELETE FROM " + table_str + ";")) {
                    //qDebug() << "Clear " << table_str << " error";
                    local_sync.rollback();
                    return;
                }
            }

            QStringList columns = DatabaseManager::Columns::all_columns[table_str];
            int count = columns.size();

            QString place_holder{};
            for (int i = 0; i < count - 1; ++i) {
                place_holder += "?, ";
            }
            place_holder += "?";

            QString insert_query_str = QString{"INSERT INTO %1 (%2) VALUES (%3);"}
                                           .arg(table_str)
                                           .arg(columns.join(", "))
                                           .arg(place_holder);

            while (remote_query.next()) {
                QSqlQuery insert_query(local_sync);
                if (!insert_query.prepare(insert_query_str)) {
                    //qDebug() << "Prepare insert query failed";
                    break;
                }

                for (const auto& col : columns) {
                    insert_query.addBindValue(remote_query.value(col).toString());
                }

                if (!remote_sync.isOpen() || !local_sync.isOpen()) {
                    if (!remote_sync.open() || !local_sync.open()) {
                        //qDebug() << "Database reopen failed: " << remote_sync.lastError();
                        return;
                    }
                }

                if (!insert_query.exec()) {
                    //qDebug() << "insert " + table_str + " to SQLite error";
                    break;
                }

                {
                    QSqlQuery update_query(remote_sync);
                    update_query.prepare("UPDATE chat_participants "
                                  "SET last_seen = CURRENT_TIMESTAMP "
                                  "WHERE participants_id = :my_id;");
                    update_query.bindValue(":my_id", EmployeesChatPage::ChatUnits::my_participant_id);
                    if(!update_query.exec())
                        qDebug() << "updatelastseen error" << update_query.lastError();
                }
            }
        }
    }

    remote_sync.close();
    local_sync.close();

    if (QSqlDatabase::contains(remote_conn_name))
        QSqlDatabase::removeDatabase(remote_conn_name);
    if (QSqlDatabase::contains(local_conn_name))
        QSqlDatabase::removeDatabase(local_conn_name);

    emit sync_finished();
}
