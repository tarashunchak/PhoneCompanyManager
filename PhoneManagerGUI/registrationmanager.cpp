#include "includes/registrationmanager.h"
#include <QSqlQuery>

void RegistrationManager::is_exist(const QString& email){
    QSqlQuery query(QSqlDatabase::database("remote"));
    query.prepare("SELECT e.id AS id, p.position_name AS position "
                  "FROM employees e "
                  "JOIN positions p ON p.id = e.position_id "
                  "WHERE e.email = ?;");
    query.addBindValue(email);
    if(!query.exec() || !query.next()){
        qDebug() << "Employee is not exist!";
        emit employee_not_founded();
    }else{
        empl_id = query.value("id").toInt();

        QSqlQuery is_registered(QSqlDatabase::database("remote"));
        is_registered.prepare("SELECT * FROM users "
                              "WHERE empl_id = ?;");
        is_registered.addBindValue(empl_id);
        if(is_registered.exec() && is_registered.next()){
            emit employee_allready_registered();
            return;
        }
        QString position = query.value("position").toString();
        if(position == "Administrator" || position == "Manager"){
            qDebug() << "Employee is exist!";
            emit employee_is_founded();
        }else{
            emit not_allowed_to_registration();
        }
    }
}

void RegistrationManager::registerNewUser(const QString& user, const QString& pass){
    QSqlQuery user_query(QSqlDatabase::database("remote"));
    user_query.prepare("INSERT INTO users(empl_id, username, password) "
                  "VALUES(:e_id, :username, :pass) RETURNING id;");
    user_query.bindValue(":e_id", empl_id);
    user_query.bindValue(":username", user);
    user_query.bindValue(":pass", pass);
    empl_id = 0;
    uint inserted_user_id;
    if(user_query.exec() && user_query.next()){
        inserted_user_id = user_query.value("id").toUInt();
        QSqlQuery participant_query(QSqlDatabase::database("remote"));
        participant_query.prepare("INSERT INTO participants(role, reference_id) "
                      "VALUES('employee', ?);");
        participant_query.addBindValue(inserted_user_id);
        if(participant_query.exec()){
            emit successful_registration();
        }else{
            QSqlQuery delete_user_query(QSqlDatabase::database("remote"));
            delete_user_query.prepare("DELETE FROM users "
                                      "WHERE id = ?;");
            delete_user_query.addBindValue(inserted_user_id);
            if(delete_user_query.exec())
                qDebug() << "incorrect inserted user successfully deleted!";
            emit unsuccessful_registration();
        }
    }else{
        emit unsuccessful_registration();
    }
}
