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
    static QNetworkAccessManager* manager = new QNetworkAccessManager{this};
    QUrl url("http://192.168.1.103:8080/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["username"] = username;
    json["password"] = password;

    QJsonDocument json_doc(json);
    QByteArray byteArr = json_doc.toJson();

    QNetworkReply* reply = manager->post(request, byteArr);
    connect(reply, &QNetworkReply::finished, this, [=]() {
        reply->deleteLater();

        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Login error:" << reply->errorString();
            emit incorrect_login_data();
            return;
        }

        QByteArray response = reply->readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(response);

        if (!responseDoc.isObject()) {
            qDebug() << "Invalid response from server";
            emit incorrect_login_data();
            return;
        }

        QJsonObject obj = responseDoc.object();
        if (obj.contains("empl_id")) {
            int empl_id = obj["empl_id"].toInt();
            qDebug() << "Login success. empl_id =" << empl_id;
            CurrentUser::setCurrentUserID(empl_id);
            emit authSuccess();
        } else {
            qDebug() << "Login failed: no empl_id in response";
            emit incorrect_login_data();
        }
    });
    /*if (!QSqlDatabase::database().isOpen()) {
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
    }*/
}

