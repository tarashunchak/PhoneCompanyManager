#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QString>
#include <QSqlDatabase>

class AuthManager : public QObject
{
    Q_OBJECT
public:
    AuthManager();
    ~AuthManager();
    void authenticate(const QString&, const QString&);

signals:
    void incorrect_login_data();
    void authSuccess();
private:
    QSqlDatabase* db;

};

#endif // AUTHMANAGER_H
