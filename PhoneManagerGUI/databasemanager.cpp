#include "includes/databasemanager.h"
#include <QSqlError>
#include <QSqlQuery>
#include "includes/currentuser.h"
#include "includes/customersdetailspage.h"
#include "employeesdetailspage.h"

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./database/database.db");

    /*db = QSqlDatabase::addDatabase("QPSQL");
    db.setConnectOptions("sslmode=require");
    db.setHostName("db.kdehjeyheklfhkifcftq.supabase.co");
    db.setPort(5432);
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("new_pass123321!");*/

    if (!db.open()) {
        qDebug() << "Database Connection Error:" << db.lastError().text();
    } else {
        qDebug() << "Database Successfully Connected!";
    }
    QSqlQuery query;
    if (!query.exec("SELECT 1")) {
        qDebug() << "Database first query connection failed: " << query.lastError();
    } else {
        qDebug() << "Database connected and queary is valid!";
    }
}

QSqlDatabase DatabaseManager::db = QSqlDatabase{};

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database Is Closed!";
    }
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

QSqlDatabase& DatabaseManager::getDatabase() {
    return db;
}

bool DatabaseManager::isConnected() {
    return db.isOpen();
}

QSqlQuery DatabaseManager::findByName(const QString& table, const QString& text){
    //if customers or employees
    QString query_str = {"SELECT * FROM " + table +
                         " WHERE LOWER(first_name) LIKE LOWER(:text) "
                         "OR LOWER(last_name) LIKE LOWER(:text) "
                         "OR LOWER(COALESCE(first_name, '') || ' ' || COALESCE(last_name, '')) LIKE LOWER(:text) "};
    if(table == "customers"){
        query_str += "OR LOWER(phone) LIKE LOWER(:text) ";
    }else if(table == "employees"){
        query_str += "OR id = :id ";
    }
    query_str += ";";

    QSqlQuery query;
    query.prepare(query_str);
    query.bindValue(":text", text + "%");
    if(table == "employees")
        query.bindValue(":id", text);
    query.exec();
    return query;
}

QSqlQuery DatabaseManager::inProgressRequests(){
    QSqlQuery query;
    query.prepare("SELECT r.id AS \"ID\", "
                  "(COALESCE(c.first_name, '') || ' ' || COALESCE(c.last_name, '')) AS \"Customer\", "
                  "r.request_type AS \"Req. type\", "
                  "r.status AS \"Status\", r.date AS \"String\" "
                  "FROM requests r "
                  "JOIN customers c ON c.id = r.cust_id "
                  "WHERE r.status = 'In Progress' "
                  "AND r.assigned_to_id = :my_user_id;");
    query.bindValue(":my_user_id", CurrentUser::getCurrentUserID());
    return query;
}

QSqlQuery DatabaseManager::unassignedRequests(){
    QSqlQuery query;
    query.prepare("SELECT r.id AS \"ID\", "
                  "(COALESCE(c.first_name, '') || ' ' || COALESCE(c.last_name, '')) AS \"Customer\", "
                  "r.request_type AS \"Req. type\", "
                  "r.status AS \"Status\", r.date AS \"String\" "
                  "FROM requests r "
                  "JOIN customers c ON c.id = r.cust_id "
                  "WHERE assigned_to_id = -1;");
    return query;
}

QSqlQuery DatabaseManager::completedRequests(){
    QSqlQuery query;
    query.prepare("SELECT * FROM requests "
                  "WHERE (status = 'Confirmed' "
                  "OR status = 'Rejected') "
                  "AND assigned_to_id = :my_user_id;");
    query.bindValue(":my_user_id", CurrentUser::getCurrentUserID());
    return query;
}

QSqlQuery DatabaseManager::requestsHistory(PAGE page, QString period){
    QSqlQuery query;
    if(page == PAGE::REQUESTS_PAGE){
        query.prepare("SELECT r.id AS \"ID\", "
                      "(COALESCE(c.first_name, '') || ' ' || COALESCE(c.last_name, '') "
                      "|| ' ID(' || c.id || ')') AS \"Customer\", "
                      "r.request_type AS \"Req. type\", "
                      "r.status AS \"Status\", r.date AS \"String\", "
                      "(COALESCE(e.first_name, '') || ' ' || COALESCE(e.last_name, '') "
                      "|| ' ID(' || e.id  || ')') AS \"Handled by\" "
                      "FROM requests r "
                      "LEFT JOIN employees e ON e.id = r.assigned_to_id "
                      "LEFT JOIN customers c ON c.id = r.cust_id;");
    }else if(page == PAGE::DASHBOARD_PAGE){
        query.prepare("SELECT r.id AS \"ID\", "
                      "c.phone AS \"Phone\", "
                      "r.date AS \"String\" "
                      "FROM requests r "
                      "JOIN customers c ON c.id = r.cust_id "
                      "ORDER BY r.id DESC LIMIT " + period + ";");
    }
    return query;
}

QSqlQuery DatabaseManager::newCustomersByPeriod(const bool is_today, QString period){
    QSqlQuery query;
    if(is_today){
        query.prepare("SELECT COUNT(*) AS cust_count, date "
                      "FROM customers "
                      "WHERE DATE(date) = DATE(CURRENT_DATE) "
                      "GROUP BY date ORDER BY date DESC;");
    }else{
        query.prepare("SELECT COUNT(id) AS cust_count, date "
                      "FROM customers "
                      "WHERE DATE(date) >= DATE(CURRENT_DATE, '" + period + "') "
                      "GROUP BY date ORDER BY date DESC;");
    }
    return query;
}

QSqlQuery DatabaseManager::newRequestsByPeriod(const bool is_today, QString period){
    QSqlQuery query;
    if(is_today){
        query.prepare("SELECT COUNT(*) AS req_count, date "
                      "FROM requests "
                      "WHERE DATE(date) = DATE(CURRENT_DATE) "
                      "GROUP BY date ORDER BY date DESC;");
    }else{
        query.prepare("SELECT COUNT(id) AS req_count, date "
                      "FROM requests "
                      "WHERE DATE(date) >= DATE(CURRENT_DATE, '" + period + "') "
                                 "GROUP BY date ORDER BY date DESC;");
    }
    return query;
}

QSqlQuery DatabaseManager::currentCustomer(const uint curr_cust_id){
    QSqlQuery query;
    query.prepare("SELECT c.id AS \"Cust. ID\", "
                  "c.first_name AS \"First name\", "
                  "c.last_name AS \"Last name\", "
                  "c.phone AS \"Phone\", "
                  "COALESCE(c.email, '') AS \"Email\", "
                  "c.date AS \"Reg. date\", "
                  "c.balance AS \"Balance\", "
                  "c.date_of_B AS \"B-DAY\", "
                  "c.is_active AS \"Is active\", "
                  "t.id AS \"Tariff ID\", "
                  "t.tariff_name AS \"Tariff\", "
                  "cm.comment_text AS \"Comment text\", "
                  "COALESCE(c.comment_id, -1) AS \"Comment ID\", "
                  "e.id  AS \"Employee ID\" "
                  "FROM customers c "
                  "JOIN tariffs t ON t.id = c.tariff_id "
                  "LEFT JOIN employees e ON e.id = c.employee_id "
                  "LEFT JOIN comments cm ON cm.id = c.comment_id "
                  "WHERE c.id = :id;");
    query.bindValue(":id", curr_cust_id);
    if(query.exec() && query.next()){
        CustomersDetailsPage::CurrentCustomer::id = query.value("Cust. ID").toString();
        CustomersDetailsPage::CurrentCustomer::first_name = query.value("First name").toString();
        CustomersDetailsPage::CurrentCustomer::last_name = query.value("Last name").toString();
        CustomersDetailsPage::CurrentCustomer::phone = query.value("Phone").toString();
        CustomersDetailsPage::CurrentCustomer::email = query.value("Email").toString();
        CustomersDetailsPage::CurrentCustomer::reg_date = query.value("Reg. date").toString();
        CustomersDetailsPage::CurrentCustomer::date_of_B = query.value("B-DAY").toString();
        CustomersDetailsPage::CurrentCustomer::tariff_name = query.value("Tariff").toString();
        CustomersDetailsPage::CurrentCustomer::tariff_id = query.value("Tariff ID").toString();
        CustomersDetailsPage::CurrentCustomer::comment_text = query.value("Comment text").toString();
        CustomersDetailsPage::CurrentCustomer::comment_id = query.value("Comment ID").toString();
        CustomersDetailsPage::CurrentCustomer::balance = query.value("Balance").toString();
        CustomersDetailsPage::CurrentCustomer::employee_id = query.value("Employee ID").toString();
        CustomersDetailsPage::CurrentCustomer::is_active = query.value("Is active").toString();
    }else{
        qDebug() << "currentCustomers query error: id = " << curr_cust_id;
        qDebug() << "currentCustomers query error text = " << query.lastError();
    }

    query.prepare("SELECT c.id AS \"Cust. ID\", "
                  "(COALESCE(first_name, '') || ' ' || COALESCE(last_name, '') AS \"Full name\", "
                  "c.phone AS \"Phone\", "
                  "c.date AS \"Reg. date\", "
                  "c.balance AS \"Balance\", "
                  "t.id AS \"Tariff ID\", "
                  "t.tariff_name AS \"Tariff\", "
                  "COALESCE(c.comment_id, -1) AS comm_id,"
                  "FROM customers c "
                  "JOIN tariffs t ON t.id = c.tariff_id "
                  "LEFT JOIN comments cm ON cm.id = c.comment_id "
                  "WHERE c.id = :id;");
    query.bindValue(":id", curr_cust_id);
    return query;
}

void DatabaseManager::sendMessage(const QString& message_text, const uint chat_id){
    QSqlQuery query;
    query.prepare("INSERT INTO messages(text, sender_participant_id, chat_id) "
                  "VALUES(:message, :origin_id, :chat_id);");
    query.bindValue(":message", message_text);
    query.bindValue(":origin_id", CurrentUser::getCurrentUserID());
    query.bindValue(":chat_id", chat_id);
    if(!query.exec()){
        qDebug() << "SendMessaget()const fault!: " << query.lastError();
        return;
    }
}

QSqlQuery DatabaseManager::currentEmployee(const uint curr_empl_id){
    QSqlQuery query;
    query.prepare("SELECT e.id AS \"Empl. ID\", "
                  "e.first_name AS \"First name\", "
                  "e.last_name AS \"Last name\", "
                  "e.phone AS \"Phone\", "
                  "COALESCE(e.email, '') AS \"Email\", "
                  "e.date_of_B AS \"B-DAY\", "
                  "e.is_active AS \"Is active\", "
                  "e.hire_date AS \"Hire date\", "
                  "e.photo AS \"Photo\", "
                  "e.salary AS \"Salary\", "
                  "e.department_id AS \"Department ID\", "
                  "d.department_name AS \"Department name\", "
                  "e.position_id AS \"Position ID\", "
                  "p.position_name AS \"Position name\", "
                  "cm.comment_text AS \"Comment text\", "
                  "COALESCE(e.comment_id, -1) AS \"Comment ID\" "
                  "FROM employees e "
                  "LEFT JOIN departments d ON d.id = e.department_id "
                  "LEFT JOIN positions p ON p.id = e.position_id "
                  "LEFT JOIN comments cm ON cm.id = e.comment_id "
                  "WHERE e.id = :id;");
    query.bindValue(":id", curr_empl_id);

    if(query.exec() && query.next()){
        EmployeesDetailsPage::CurrentEmployee::id = query.value("Empl. ID").toString();
        EmployeesDetailsPage::CurrentEmployee::first_name = query.value("First name").toString();
        EmployeesDetailsPage::CurrentEmployee::last_name = query.value("Last name").toString();
        EmployeesDetailsPage::CurrentEmployee::department_id = query.value("Department ID").toString();
        EmployeesDetailsPage::CurrentEmployee::department_name = query.value("Department name").toString();
        EmployeesDetailsPage::CurrentEmployee::position_id = query.value("Position ID").toString();
        EmployeesDetailsPage::CurrentEmployee::position_name = query.value("Position name").toString();
        EmployeesDetailsPage::CurrentEmployee::hire_date = query.value("Hire date").toString();
        EmployeesDetailsPage::CurrentEmployee::salary = query.value("Salary").toString();
        EmployeesDetailsPage::CurrentEmployee::phone = query.value("Phone").toString();
        EmployeesDetailsPage::CurrentEmployee::email = query.value("Email").toString();
        //EmployeesDetailsPage::CurrentEmployee::photo = query.value("Photo").toString();
        EmployeesDetailsPage::CurrentEmployee::is_active = query.value("Is active").toString();
        EmployeesDetailsPage::CurrentEmployee::date_of_B = query.value("B-DAY").toString();
        EmployeesDetailsPage::CurrentEmployee::comment_text = query.value("Comment text").toString();
        EmployeesDetailsPage::CurrentEmployee::comment_id = query.value("Comment ID").toString();
    }else{
        qDebug() << "CurrentEmployee query error: " << query.lastError();
    }
    return query;
}

void DatabaseManager::saveCommentToDB(PAGE page, int entity_id, int comment_id
                                      , const QString& comment_text)
{
    QString table{page == PAGE::CUSTOMERS_PAGE ? "customers" : "employees"};
    static QSqlQuery query;
    if(comment_id == -1){
        query.prepare("INSERT INTO comments(comment_text, written_by_id) "
                      "VALUES(:text, :my_id) RETURNING id;");
        query.bindValue(":text", comment_text);
        query.bindValue(":my_id", CurrentUser::getCurrentUserID());

        if(!query.exec() || !query.next()){
            qDebug() << "insert into comment query fault: " << query.lastError();
            return;
        }
        comment_id = query.value("id").toInt();
        query.clear();
        QString query_str{"UPDATE " + table +
                          " SET comment_id = :comm_id "
                          "WHERE id = :entity_id;"};
        query.prepare(query_str);
        query.bindValue(":comm_id", comment_id);
        query.bindValue(":entity_id", entity_id);

        if(!query.exec())
            qDebug() << "update customers || employees comment_id query fault: " << query.lastError();

        return;
    }
    query.clear();
    query.prepare("UPDATE comments "
                  "SET comment_text = :text "
                  "WHERE id = :comm_id;");
    query.bindValue(":text", comment_text);
    query.bindValue(":comm_id", comment_id);
    if(!query.exec())
        qDebug() << "update comments query fault: " << query.lastError();
}
