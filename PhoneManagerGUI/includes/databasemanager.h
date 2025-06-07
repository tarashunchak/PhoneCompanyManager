#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
private:
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager();
    ~DatabaseManager();

public:
    enum class PAGE : uint{
        DASHBOARD_PAGE = 0u,
        CUSTOMERS_PAGE,
        EMPLOYEES_PAGE,
        REQUESTS_PAGE,
        TARIFFS_PAGE,
        CHAT_PAGE
    };

    static DatabaseManager& instance();
    static QSqlDatabase& getDatabase();
    static bool isConnected();
    static QSqlQuery findByName(const QString&, const QString&);
    static QSqlQuery inProgressRequests();
    static QSqlQuery unassignedRequests();
    static QSqlQuery completedRequests();
    static QSqlQuery requestsHistory(PAGE, QString period = {});
    static QSqlQuery newCustomersByPeriod(const bool, QString);
    static QSqlQuery newRequestsByPeriod(const bool, QString);
    static QSqlQuery currentCustomer(const uint);
    static QSqlQuery currentEmployee(const uint);
    static void sendMessage(const QString&, const uint);
    static void saveCommentToDB(PAGE, int, int, const QString&);

private:
    static QSqlDatabase db;

};

#endif // DATABASEMANAGER_H
