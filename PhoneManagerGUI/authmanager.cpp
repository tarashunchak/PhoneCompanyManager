#include "includes/authmanager.h"
#include "includes/databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QByteArray>
#include <QCryptographicHash>
#include "includes/currentuser.h"

void AuthManager::authenticate(const QString& username, const QString& password){
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is closed before authentication!";
        emit incorrect_login_data();
        return;
    }

    //QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("SELECT * FROM Users WHERE username = :user AND pass_hash = :pass");
    query.bindValue(":user", username);
    query.bindValue(":pass", password);

    if (!query.exec()) {
        qDebug() << "Auth query error:" << query.lastError();
        emit incorrect_login_data();
        return;
    }

    if(query.next()){
        const int userID = query.value("id").toInt();
        CurrentUser::setCurrentUserID(userID);
        emit authSuccess();
    }else{
        qDebug() << "Invalid username or password!";
        emit incorrect_login_data();
    }
}

