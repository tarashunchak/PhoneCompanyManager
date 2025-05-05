#include "includes/databasemanager.h"
#include <QSqlError>
#include <QSqlQuery>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QPSQL");
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("./database/database.db");

    db.setHostName("192.168.1.103");
    db.setPort(5432);
    db.setDatabaseName("database");
    db.setUserName("postgres");
    db.setPassword("new_password");

    if (!db.open()) {
        qDebug() << "Database Connection Error:" << db.lastError().text();
    } else {
        qDebug() << "Database Successfully Connected!";
    }
    QSqlQuery query;
    if (!query.exec("SELECT 1")) {
        qDebug() << "Database first query connection failed: " << query.lastError();
    } else {
        qDebug() << "Database connected and queary is valid!";
    }
}

QSqlDatabase DatabaseManager::db = QSqlDatabase{};

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database Is Closed!";
    }
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

QSqlDatabase& DatabaseManager::getDatabase() {
    return db;
}

bool DatabaseManager::isConnected() {
    return db.isOpen();
}
