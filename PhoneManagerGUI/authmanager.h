#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QString>
#include <QSqlDatabase>

class AuthManager : QObject
{
    Q_OBJECT
public:
    static void aunthenticate(const QString, const QString);

private:
    static QSqlDatabase* db;

};

#endif // AUTHMANAGER_H
