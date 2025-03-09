#include "authmanager.h"
#include "databasemanager.h"
#include <QSqlQuery>

QSqlDatabase* AuthManager::db = nullptr;

void AuthManager::aunthenticate(const QString username, const QString password){
    db = &DatabaseManager::instance().getDatabase();
    QSqlQuery query;
    query.prepare("SELECT *FROM Users WHERE username = :user AND password = :pass;");
    query.bindValue(":user", username);
    query.bindValue(":pass", password);
    if(!query.exec()){

    }
}
