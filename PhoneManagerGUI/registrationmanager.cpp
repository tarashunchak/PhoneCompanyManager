#include "includes/registrationmanager.h"

#include <QSqlQuery>

RegistrationManager::RegistrationManager(){}

RegistrationManager::~RegistrationManager(){
}

void RegistrationManager::is_exist(const QString& email){
    QSqlQuery query;
    query.prepare("SELECT Employees.id AS id, Positions.position_name AS position "
                  "FROM Employees "
                  "JOIN Positions ON Positions.id = Employees.position_id "
                  "WHERE email = :email;");
    query.bindValue(":email", email);
    if(!query.exec() || !query.next()){
        qDebug() << "Employee is not exist!";
        emit employee_not_founded();
        return;
    }else{
        QString position = query.value("position").toString();
        if(position == "Administrator" || position == "Manager"){
            empl_id = query.value("id").toInt();
            qDebug() << "Employee is exist!";
            emit employee_is_founded();
            return;
        }else{
            emit not_allowed_to_registration();
            return;
        }
    }
}

void RegistrationManager::registerNewUser(const QString& user, const QString& pass){
    QSqlQuery query;
    query.prepare("INSERT INTO Users(empl_id, username, pass_hash) "
                  "VALUES(:e_id, :username, :pass);");
    query.bindValue(":e_id", empl_id);
    query.bindValue(":username", user);
    query.bindValue(":pass", pass);
    empl_id = 0;
    if(query.exec()){
        emit successful_registration();
        return;
    }else{
        emit unsuccessful_registration();
        return;
    }
}
