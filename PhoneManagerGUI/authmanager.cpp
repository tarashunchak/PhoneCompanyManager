#include "includes/authmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QByteArray>
#include <QCryptographicHash>
#include "includes/currentuser.h"
#include "employeeschatpage.h"
#include "includes/supportchat.h"
#include "includes/databasemanager.h"

void AuthManager::authenticate(const QString& username, const QString& password){
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QString hex_pass = hash.toHex();
    QSqlQuery query(QSqlDatabase::database("remote"));
    query.prepare("SELECT u.id AS user_id, "
                  "u.empl_id AS empl_id, "
                  "p.id AS part_id, "
                  "u.is_online AS is_online "
                  "FROM participants p "
                  "JOIN users u ON u.id = p.reference_id "
                  "WHERE p.role = 'employee' "
                  "AND u.username = ? "
                  "AND u.password = ?;");

    query.addBindValue(username);
    query.addBindValue(hex_pass);

    if (!query.exec()) {
        qDebug() << "Auth query error:" << query.lastError();
        emit incorrect_login_data();
        return;
    }

    if(query.next()){
        const uint userID = query.value("user_id").toUInt();
        const uint emplID = query.value("empl_id").toUInt();
        const uint participant_id = query.value("part_id").toUInt();
        const bool is_online = query.value("is_online").toBool();
        if(is_online){
            emit user_online();
            return;
        }
        EmployeesChatPage::ChatUnits::my_participant_id = participant_id;
        SupportChat::ChatUnits::my_participant_id = participant_id;
        CurrentUser::setCurrentUserID(userID);
        CurrentUser::setCurrentEmployeeID(emplID);
        //DatabaseManager::startSyncTables();
        query.prepare("UPDATE users "
                      "SET is_online = true "
                      "WHERE id = ?;");
        query.addBindValue(userID);
        query.exec();
        emit authSuccess();
    }else{
        qDebug() << "Invalid username or password!";
        emit incorrect_login_data();
    }
}

