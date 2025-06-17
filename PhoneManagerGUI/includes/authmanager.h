#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QObject>
#include <QString>

class AuthManager : public QObject
{
    Q_OBJECT
public:
    AuthManager() = default;
    ~AuthManager() = default;
    void authenticate(const QString&, const QString&);

signals:
    void incorrect_login_data();
    void authSuccess();
    void user_online();
};

#endif // AUTHMANAGER_H
