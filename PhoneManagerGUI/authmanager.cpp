#include "includes/authmanager.h"
#include "includes/databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QByteArray>
#include <QCryptographicHash>
#include "includes/currentuser.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

void AuthManager::authenticate(const QString& username, const QString& password){
    //QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QSqlQuery query;
    query.prepare("SELECT * FROM users "
                  "WHERE username = :user "
                  "AND password = :pass");

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

