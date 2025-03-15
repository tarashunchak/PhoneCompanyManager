#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <QSqlDatabase>

class RegistrationManager : public QObject
{
    Q_OBJECT
public:
    RegistrationManager();
    ~RegistrationManager();
public slots:
    void registerNewUser(const QString&, const QString&, const QString&);

signals:
    void employee_not_founded();
    void unsuccessful_registration();

private:
    QSqlDatabase* db;
};

#endif // REGISTRATIONMANAGER_H
