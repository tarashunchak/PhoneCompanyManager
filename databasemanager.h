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
    QSqlDatabase& getDatabase();
    bool isConnected();

private:
    QSqlDatabase db;

};

#endif // DATABASEMANAGER_H
