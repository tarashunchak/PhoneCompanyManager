#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DatabaseManager
{
private:
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager();
    ~DatabaseManager();
    struct Columns{
        static QMap<QString, QStringList> columns;
    };
public:
    enum class PAGE : uint{
        DASHBOARD_PAGE = 0u,
        CUSTOMERS_PAGE,
        EMPLOYEES_PAGE,
        REQUESTS_PAGE,
        TARIFFS_PAGE,
        CHAT_PAGE,
        CUSTOMERS_DETAILS_PAGE,
        EMPLOYEES_DETAILS_PAGE
    };
    enum class TABLE : uint{
        USERS = 0u,
        EMPLOYEES,
        CUSTOMERS,
        TARIFFS,
        REQUESTS,
        CHATS,
        CHAT_PARTICIPANTS,
        PARTICIPANTS,
        DEPATMENTS,
        POSITIONS,
        COMMENTS,
        MESSAGES,
        PAYMENTS,
        USAGE
    };

    static QString tableToString(TABLE);

    enum class ORDER : uint{
        ALL = 0u,
        ASC,
        DESC
    };

    static DatabaseManager& instance();
    static QSqlDatabase& getDatabase();
    static bool isConnected();
    static QSqlQuery findByName(TABLE, const QString&);
    static QSqlQuery inProgressRequests();
    static QSqlQuery unassignedRequests();
    static QSqlQuery completedRequests();
    static QSqlQuery requestsHistory(PAGE, QString period = {});
    static QSqlQuery departments();
    static QSqlQuery positions();
    static QSqlQuery newCustomersByPeriod(const bool, QString);
    static QSqlQuery newRequestsByPeriod(const bool, QString);
    static QSqlQuery currentCustomer(const uint);
    static QSqlQuery currentEmployee(const uint);
    static void sendMessage(const QString&, const uint);
    static void saveCommentToDB(TABLE, int, int, const QString&);
    static void deleteRecord(TABLE, const uint);

    template <typename... Args>
    static bool insertToDB(TABLE table, const std::tuple<Args...> args){
        QString table_str = tableToString(table);
        if(sizeof...(Args) != Columns::columns[table_str].size()){
            qDebug() << table_str << " not match : ( " << sizeof...(Args)  << " ), ( " <<  Columns::columns[table_str].size() << ")";
        }
        int count = Columns::columns[table_str].size();
        QString place_holder{};
        for(int i = 0; i < count-1; ++i){
            place_holder += "?, ";
        }
        place_holder += "?";
        QString query_str = QString{"INSERT INTO %1 (%2) VALUES (%3);"}
                                .arg(table_str).arg(Columns::columns[table_str].join(", "))
                                .arg(place_holder);
        QSqlQuery query;
        query.prepare(query_str);
        std::apply([&query](const auto&... data){
            (..., query.addBindValue(data));
        }, args);
        if(!query.exec())
            qDebug() << place_holder;
            qDebug() << table_str << "insertToDB error: " << query.lastError();
        return false;
    };

private:
    static QSqlDatabase db;
};


#endif // DATABASEMANAGER_H
