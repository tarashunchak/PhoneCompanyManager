#include "includes/databasemanager.h"
#include <QSqlError>
#include <QSqlQuery>
#include "includes/currentuser.h"
#include "includes/customersdetailspage.h"
#include "employeesdetailspage.h"
#include <QSqlDriver>
#include <QObject>

QString DatabaseManager::tableToString(TABLE table){
    switch (table) {
    case TABLE::CUSTOMERS :
        return "customers";
    case TABLE::EMPLOYEES :
        return "employees";
    case TABLE::USERS :
        return "users";
    case TABLE::TARIFFS :
        return "tariffs";
    case TABLE::CHATS :
        return "chats";
    case TABLE::CHAT_PARTICIPANTS :
        return "chat_participants";
    case TABLE::PARTICIPANTS :
        return "participants";
    case TABLE::DEPARTMENTS :
        return "departments";
    case TABLE::POSITIONS :
        return "positions";
    case TABLE::PAYMENTS :
        return "payments";
    case TABLE::MESSAGES :
        return "messages";
    case TABLE::COMMENTS :
        return "comments";
    case TABLE::REQUESTS :
        return "requests";
    case TABLE::USAGE :
        return "usages";
    }
    return {};
}

DatabaseManager::DatabaseManager()
{
    local_db = QSqlDatabase::addDatabase("QSQLITE", "local");
    local_db.setDatabaseName("./database/database.db");

    remote_db = QSqlDatabase::addDatabase("QPSQL", "remote");
    QString host = "ep-divine-sun-a83zg48v-pooler.eastus2.azure.neon.tech";
    QString dbName = "neondb";
    QString user = "neondb_owner";
    QString password = "npg_qILNuP6Diz1Z";
    int port = 5432;

    remote_db.setHostName(host);
    remote_db.setPort(port);
    remote_db.setDatabaseName(dbName);
    remote_db.setUserName(user);
    remote_db.setPassword(password);
    remote_db.setConnectOptions("sslmode=require");

    if (!remote_db.open() || !local_db.open()) {
        qDebug() << "Database Connection Error:" << remote_db.lastError().text();
    } else {
        qDebug() << "Database Successfully Connected!";
    }
    QSqlQuery remote_query(remote_db);
    QSqlQuery local_query(local_db);
    if (!remote_query.exec("LISTEN new_message;")  || !local_query.exec("SELECT 1")) {
        qDebug() << "Database first query connection failed: " << remote_query.lastError();
    } else {
        qDebug() << "Database connected and queary is valid!";
    }
}

QSqlDatabase DatabaseManager::remote_db = QSqlDatabase{};
QSqlDatabase DatabaseManager::local_db = QSqlDatabase{};

DatabaseManager::~DatabaseManager() {
    if (remote_db.isOpen() || local_db.isOpen()) {
        remote_db.close();
        local_db.close();
        qDebug() << "Database Is Closed!";
    }
    cleanUpConnections();
}

void DatabaseManager::cleanUpConnections(){
    for(const QString& remove_db : QSqlDatabase::connectionNames()){
        QSqlDatabase::removeDatabase(remove_db);
    }
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

QSqlDatabase& DatabaseManager::getDatabase() {
    return local_db;
}

bool DatabaseManager::isConnected() {
    return local_db.isOpen();
}

void DatabaseManager::syncAllTables(){
    using enum TABLE;
    static const QList<TABLE> tables{
        POSITIONS, DEPARTMENTS, USERS, EMPLOYEES
        ,CUSTOMERS, TARIFFS, REQUESTS, CHATS
        ,CHAT_PARTICIPANTS, PARTICIPANTS, /*USAGE,*/ COMMENTS, MESSAGES
    };
    for(auto table : tables)
        syncTable(table);
}

void DatabaseManager::syncTable(TABLE table){
    QString thread_id = QString::number(reinterpret_cast<quintptr>(QThread::currentThreadId()));
    QString remote_conn_name = QString{"remote_sync_%1"}.arg(thread_id);
    QString local_conn_name = QString{"local_sync_%1"}.arg(thread_id);

    if(QSqlDatabase::contains(remote_conn_name))
        QSqlDatabase::removeDatabase(remote_conn_name);
    if(QSqlDatabase::contains(local_conn_name))
        QSqlDatabase::removeDatabase(local_conn_name);

    {
        QSqlDatabase local_sync = QSqlDatabase::addDatabase("QSQLITE", local_conn_name);
        local_sync.setDatabaseName("./database/database.db");

        QSqlDatabase remote_sync = QSqlDatabase::addDatabase("QPSQL", remote_conn_name);
        static QString host = "ep-divine-sun-a83zg48v-pooler.eastus2.azure.neon.tech";
        static QString dbName = "neondb";
        static QString user = "neondb_owner";
        static QString password = "npg_qILNuP6Diz1Z";
        static int port = 5432;

        remote_sync.setHostName(host);
        remote_sync.setPort(port);
        remote_sync.setDatabaseName(dbName);
        remote_sync.setUserName(user);
        remote_sync.setPassword(password);
        remote_sync.setConnectOptions("sslmode=require");

        QString table_str = tableToString(table);
        QSqlQuery remote_query(remote_sync);
        if (!remote_sync.isOpen() || !local_sync.isOpen()) {
            if (!remote_sync.open() || !local_sync.open()) {
                remote_sync.close();
                qDebug() << "Database reopen failed: " << remote_sync.lastError();
                return;
            }
        }
        QString query_str = "SELECT * FROM " + table_str + ";";
        remote_query.prepare(query_str);
        if(!remote_query.exec()){
            qDebug() << "Error to exec remote query";
            return;
        }

        local_sync.transaction();
        QSqlQuery clear_sqlite_query(local_sync);
        if(!clear_sqlite_query.exec("DELETE FROM " + table_str + ";")){
            qDebug() << "Clear " << table_str << " error";
            local_db.rollback();
            return;
        }

        QStringList columns = Columns::all_columns[table_str];
        int count = columns.size();

        QString place_holder{};
        for(int i = 0; i < count - 1; ++i){
            place_holder += "?, ";
        }
        place_holder += "?";

        QString insert_query_str = QString{"INSERT INTO %1 (%2) VALUES (%3);"}
                                .arg(table_str).arg(columns.join(", "))
                                .arg(place_holder);
        QSqlQuery insert_query(local_sync);
        insert_query.prepare(insert_query_str);

        bool is_ok = true;
        while(remote_query.next()){
            insert_query.clear();
            insert_query.prepare(insert_query_str);
            for(const auto& col : columns){
                insert_query.addBindValue(remote_query.value(col).toString());
            }
            if (!remote_sync.isOpen() || !local_sync.isOpen()) {
                if (!remote_sync.open() || !local_sync.open()) {
                    qDebug() << "Database reopen failed: " << remote_sync.lastError();
                    return;
                }
            }
            if(!insert_query.exec()){
                qDebug() << "insert " + table_str + " to SQLite error";
                is_ok = false;
                break;
            }
        }
        if(is_ok)
            local_sync.commit();
        else
            local_sync.rollback();

        remote_query.clear();
        clear_sqlite_query.clear();
        insert_query.clear();

        remote_sync.close();
        local_sync.close();
    }
}

QSqlQuery DatabaseManager::findByName(TABLE table, const QString& text){
    static QString query_str{};
    query_str = "";
    if(table == TABLE::CUSTOMERS || table == TABLE::EMPLOYEES)
        query_str = {"SELECT * FROM " + tableToString(table) +
                     " WHERE LOWER(first_name) LIKE LOWER(:text) "
                     "OR LOWER(last_name) LIKE LOWER(:text) "
                     "OR LOWER(COALESCE(first_name, '') || ' ' || COALESCE(last_name, '')) LIKE LOWER(:text) "};
    else if(table == TABLE::TARIFFS)
        query_str = "SELECT * FROM tariffs "
                     "WHERE LOWER(tariff_name) LIKE LOWER(:text) "
                     "OR id = :id;";

    switch (table){
    case TABLE::CUSTOMERS : {
        query_str += "OR LOWER(phone) LIKE LOWER(:text) ";
        break;
    }
    case TABLE::EMPLOYEES : {
        query_str += "OR id = :id ";
        break;
    }
    }

    QSqlQuery query(local_db);
    query.prepare(query_str);
    query.bindValue(":text", text + "%");
    if(table == TABLE::EMPLOYEES || table == TABLE::TARIFFS)
        query.bindValue(":id", text);
    if(!remote_db.isOpen()) remote_db.open();
    query.exec();
    return query;
}

QSqlQuery DatabaseManager::inProgressRequests(){
    QSqlQuery query(local_db);
    query.prepare("SELECT r.id AS \"ID\", "
                  "(COALESCE(c.first_name, '') || ' ' || COALESCE(c.last_name, '')) AS \"Customer\", "
                  "r.request_type AS \"Req. type\", "
                  "r.status AS \"Status\", r.date AS \"String\" "
                  "FROM requests r "
                  "JOIN customers c ON c.id = r.cust_id "
                  "WHERE r.status = 'In Progress' "
                  "AND r.assigned_to_id = :my_user_id;");
    query.bindValue(":my_user_id", CurrentUser::getCurrentUserID());
    //QtConcurrent::run(&DatabaseManager::syncAllTables);
    return query;
}

QSqlQuery DatabaseManager::unassignedRequests(){
    QSqlQuery query(local_db);
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
    QSqlQuery query(local_db);
    query.prepare("SELECT * FROM requests "
                  "WHERE (status = 'Confirmed' "
                  "OR status = 'Rejected') "
                  "AND assigned_to_id = :my_user_id;");
    query.bindValue(":my_user_id", CurrentUser::getCurrentUserID());
    return query;
}

QSqlQuery DatabaseManager::requestsHistory(PAGE page, QString period){
    QSqlQuery query(local_db);
    if(page == PAGE::EMPLOYEES_DETAILS_PAGE){
        query.prepare("SELECT id AS ID, date AS Date"
                      ", request_type AS Type, cust_id AS \"Cust. ID\", "
                      "status AS Status "
                      "FROM requests WHERE assigned_to_id = :id "
                      "ORDER BY DATE(date) DESC;");
        query.bindValue(":id", EmployeesDetailsPage::CurrentEmployee::id);
    }else if(page == PAGE::CUSTOMERS_DETAILS_PAGE){
        query.prepare("SELECT id AS ID, "
                      "date AS Date, "
                      "request_type AS Type "
                      "FROM requests "
                      "WHERE cust_id = :id "
                      "ORDER BY DATE(date) DESC;");
        query.bindValue(":id", CustomersDetailsPage::CurrentCustomer::id);
    }else if(page == PAGE::REQUESTS_PAGE){
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
    }else if(page == PAGE::DASHBOARD_PAGE && !period.isEmpty()){
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
    QSqlQuery query(local_db);
    if(is_today){
        query.prepare("SELECT COUNT(*) AS cust_count, DATETIME(date) AS date "
                      "FROM customers "
                      "WHERE DATE(date) = DATE(CURRENT_DATE) "
                      "GROUP BY DATE(date) ORDER BY DATE(date) DESC;");
    }else{
        query.prepare("SELECT COUNT(id) AS cust_count, DATETIME(date) AS date "
                      "FROM customers "
                      "WHERE DATE(date) >= DATE(CURRENT_DATE + INTERVAL '" + period + "') "
                      "GROUP BY DATE(date) ORDER BY DATE(date) DESC;");
    }
    return query;
}

QSqlQuery DatabaseManager::newRequestsByPeriod(const bool is_today, QString period){
    QSqlQuery query(local_db);
    if(is_today){
        query.prepare("SELECT COUNT(*) AS req_count, date "
                      "FROM requests "
                      "WHERE DATE(date) = DATE(CURRENT_DATE) "
                      "GROUP BY DATE(date) ORDER BY DATE(date) DESC;");
    }else{
        query.prepare("SELECT COUNT(id) AS req_count, date "
                      "FROM requests "
                      "WHERE DATE(date) >= DATE(CURRENT_DATE + INTERVAL '" + period + "') "
                                 "GROUP BY DATE(date) ORDER BY DATE(date) DESC;");
    }
    return query;
}

QSqlQuery DatabaseManager::currentCustomer(const uint curr_cust_id){
    QtConcurrent::run(&DatabaseManager::syncAllTables);
    QTimer::singleShot(1000, nullptr, nullptr);
    QSqlQuery query(local_db);
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
                  "WHERE c.id = ?;");
    query.addBindValue(curr_cust_id);
    if(!remote_db.isOpen()) remote_db.open();
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
                  "WHERE c.id = ?;");
    query.addBindValue(curr_cust_id);
    return query;
}

QSqlQuery DatabaseManager::currentEmployee(const uint curr_empl_id){
    QSqlQuery query(local_db);
    query.prepare("SELECT e.id AS \"Empl. ID\", "
                  "e.first_name AS \"First name\", "
                  "e.last_name AS \"Last name\", "
                  "e.phone AS \"Phone\", "
                  "COALESCE(e.email, '') AS \"Email\", "
                  "e.date_of_b AS \"B-DAY\", "
                  "e.is_active AS \"Is active\", "
                  "e.hire_date AS \"Hire date\", "
                  "e.photo AS \"Photo\", "
                  "e.salary AS \"Salary\", "
                  "e.department_id AS \"Department ID\", "
                  "d.department_name AS \"Department name\", "
                  "e.position_id AS \"Position ID\", "
                  "p.position_name AS \"Position name\", "
                  "cm.comment_text AS \"Comment text\", "
                  "e.comment_id AS \"Comment ID\" "
                  "FROM employees e "
                  "LEFT JOIN departments d ON d.id = e.department_id "
                  "LEFT JOIN positions p ON p.id = e.position_id "
                  "LEFT JOIN comments cm ON cm.id = e.comment_id "
                  "WHERE e.id = ?;");
    query.addBindValue(curr_empl_id);

    if(!remote_db.isOpen()) remote_db.open();
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
        qDebug() << "comment_id" << (EmployeesDetailsPage::CurrentEmployee::comment_id = query.value("Comment ID").toString());
    }else{
        qDebug() << "CurrentEmployee query error: " << query.lastError();
    }
    QtConcurrent::run(&DatabaseManager::syncAllTables);
    return query;
}

void DatabaseManager::saveCommentToDB(TABLE table, int entity_id, int comment_id
                                      , const QString& comment_text)
{
    QString table_str = tableToString(table);
    QSqlQuery query(remote_db);
    qDebug() << "comment_id = " << comment_id;
    if(comment_id == -1){
        query.prepare("INSERT INTO comments(comment_text, written_by_id) "
                      "VALUES(?, ?) RETURNING id;");
        query.addBindValue(comment_text);
        query.addBindValue(CurrentUser::getCurrentEmployeeID());

        if(!remote_db.isOpen()) remote_db.open();
        if(!query.exec() || !query.next()){
            qDebug() << "insert into comment query fault: " << query.lastError();
            return;
        }
        comment_id = query.value("id").toInt();
        QString query_str{"UPDATE " + table_str +
                          " SET comment_id = ? "
                          "WHERE id = ?;"};
        query.prepare(query_str);
        query.addBindValue(comment_id);
        query.addBindValue(entity_id);

    }else{
        query.prepare("UPDATE comments "
                      "SET comment_text = ? "
                      "WHERE id = ?;");
        query.addBindValue(comment_text);
        query.addBindValue(comment_id);
    }
    if(!remote_db.isOpen()) remote_db.open();
    if(!query.exec())
        qDebug() << "update comments query fault: " << query.lastError();
    query.clear();
    QtConcurrent::run(&DatabaseManager::syncAllTables);
}

QSqlQuery DatabaseManager::departments(){
    return QSqlQuery{"SELECT * FROM departments;", local_db};
}

QSqlQuery DatabaseManager::positions(){
    return QSqlQuery{"SELECT * FROM positions;", local_db};
}

QSqlQuery DatabaseManager::MyAllCorporateChats(){
    QSqlQuery query(local_db);
    query.prepare("SELECT DISTINCT u.id AS user_id, c.id AS chat_id, "
                  "e.first_name AS partner_fname, "
                  "e.last_name AS partner_lname, e.photo AS profile_pic, "
                  "p2.id AS part_id "
                  "FROM chats c "
                  "JOIN chat_participants cp1 ON cp1.chat_id = c.id "
                  "JOIN chat_participants cp2 ON cp2.chat_id = c.id "
                  "JOIN participants p1 ON p1.id = cp1.participants_id "
                  "JOIN participants p2 ON p2.id = cp2.participants_id "
                  "JOIN users u ON u.id = p2.reference_id "
                  "JOIN employees e ON e.id = u.empl_id "
                  "WHERE (p1.role = 'employee' AND p2.role = 'employee') "
                  "AND (p1.reference_id = :my_id AND p2.reference_id != :my_id);");
    query.bindValue(":my_id", CurrentUser::getCurrentUserID());
    QtConcurrent::run(&DatabaseManager::syncAllTables);
    return query;
}

QSqlQuery DatabaseManager::AllMessageFromSupportChat(){
    if(!remote_db.isOpen()) remote_db.open();
    QSqlQuery query(remote_db);
    query.prepare("SELECT m.text AS text, c.id AS chat_id, "
                  "m.sender_participant_id AS sender_id "
                  "FROM messages m "
                  "JOIN chats c ON c.id = m.chat_id "
                  "JOIN chat_participants cp1 ON cp1.chat_id = c.id "
                  "JOIN chat_participants cp2 ON cp2.chat_id = c.id "
                  "JOIN participants p1 ON p1.id = cp1.participants_id "
                  "JOIN participants p2 ON p2.id = cp2.participants_id "
                  "WHERE p1.role = 'employee' AND p2.role = 'customer' "
                  "AND p1.reference_id = :my_id AND p2.reference_id != :my_id;");
    query.bindValue(":my_id", CurrentUser::getCurrentUserID());
    return query;
}
