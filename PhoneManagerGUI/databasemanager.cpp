#include "databasemanager.h"
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./database/database.db");

    if (!db.open()) {
        qDebug() << "Database Connection Error:" << db.lastError().text();
    } else {
        qDebug() << "Database Successfully Connected!";
    }
}

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
