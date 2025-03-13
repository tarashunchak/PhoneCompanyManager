#include "authmanager.h"
#include "databasemanager.h"
#include <QSqlQuery>

AuthManager::AuthManager():db(&DatabaseManager::instance().getDatabase()){}

void AuthManager::aunthenticate(const QString username, const QString password){
    db = &DatabaseManager::instance().getDatabase();
    QSqlQuery query;
    query.prepare("SELECT *FROM Users WHERE username = :user AND password = :pass;");
    query.bindValue(":user", username);
    query.bindValue(":pass", password);
    if(!query.exec()){
        qDebug() << "There is no User with this username or pass in DB!\n";
        emit incorrect_login_data();
    }

}
