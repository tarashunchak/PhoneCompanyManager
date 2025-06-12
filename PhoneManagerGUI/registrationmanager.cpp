#include "includes/registrationmanager.h"

#include <QSqlQuery>

RegistrationManager::RegistrationManager(){}

RegistrationManager::~RegistrationManager(){
}

void RegistrationManager::is_exist(const QString& email){
    QSqlQuery query;
    query.prepare("SELECT e.id AS id, p.position_name AS position "
                  "FROM employees e "
                  "JOIN positions p ON p.id = e.position_id "
                  "WHERE e.email = :email;");
    query.bindValue(":email", email);
    if(!query.exec() || !query.next()){
        qDebug() << "Employee is not exist!";
        emit employee_not_founded();
    }else{
        QString position = query.value("position").toString();
        if(position == "Administrator" || position == "Manager"){
            empl_id = query.value("id").toInt();
            qDebug() << "Employee is exist!";
            emit employee_is_founded();
        }else{
            emit not_allowed_to_registration();
        }
    }
}

void RegistrationManager::registerNewUser(const QString& user, const QString& pass){
    QSqlQuery query;
    query.prepare("INSERT INTO users(empl_id, username, password) "
                  "VALUES(:e_id, :username, :pass) RETURNING id;");
    query.bindValue(":e_id", empl_id);
    query.bindValue(":username", user);
    query.bindValue(":pass", pass);
    empl_id = 0;
    uint inserted_user_id;
    if(query.exec() && query.next()){
        inserted_user_id = query.value("id").toUInt();
        query.prepare("INSERT INTO participants(role, reference_id) "
                      "VALUES(employee, :u_id);");
        query.bindValue(":u_id", inserted_user_id);
        if(query.exec() && query.next()){
            emit successful_registration();
        }
    }else{
        emit unsuccessful_registration();
    }
}
