#include "registrationmanager.h"
#include "databasemanager.h"

#include <QSqlQuery>

RegistrationManager::RegistrationManager(): db(&DatabaseManager::instance().getDatabase()) {}

RegistrationManager::~RegistrationManager(){
    db = nullptr;
}

void RegistrationManager::registerNewUser(const QString& email, const QString& user, const QString& pass){
    QSqlQuery query;
    query.prepare("SELECT *FROM Users WHERE email = :email;");
    query.bindValue(":email", email);

    if(!query.exec()){
        emit employee_not_founded();
        return;
    }

    const int empl_id = query.value("id").toInt();
    query.prepare("INSERT INTO Users(empl_id, username, pass_hash) "
                  "VALUES(:e_id, :username, :pass);");
    query.bindValue(":e_id", empl_id);
    query.bindValue(":username", user);
    query.bindValue(":pass", pass);

    if(!query.exec()){
        emit unsuccessful_registration();
        return;
    }
}
