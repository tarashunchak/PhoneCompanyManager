#include "includes/authmanager.h"
#include "includes/databasemanager.h"
#include <QSqlQuery>
#include <QByteArray>
#include <QCryptographicHash>
#include "includes/currentuser.h"

AuthManager::AuthManager():db(&DatabaseManager::instance().getDatabase()){}

AuthManager::~AuthManager(){
    db = nullptr;
}

void AuthManager::authenticate(const QString& username, const QString& password){
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QSqlQuery query;
    query.prepare("SELECT *FROM Users WHERE username = :user AND pass_hash = :pass;");
    query.bindValue(":user", username);
    query.bindValue(":pass", hash);
    if(query.exec() && query.next()){
        const int userID = query.value("empl_id").toInt();
        CurrentUser::setCurrentUserID(userID);
        emit authSuccess();
    }else{
        qDebug() << "There is no User with this username or pass in DB!\n";
        emit incorrect_login_data();
    }

}
