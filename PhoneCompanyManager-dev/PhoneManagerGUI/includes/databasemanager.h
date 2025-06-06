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
    static DatabaseManager& instance();
    static QSqlDatabase& getDatabase();
    static bool isConnected();

private:
    static QSqlDatabase db;

};

#endif // DATABASEMANAGER_H
