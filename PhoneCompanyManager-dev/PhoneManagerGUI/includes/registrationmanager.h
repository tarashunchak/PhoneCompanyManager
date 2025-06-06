#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <QObject>

class RegistrationManager : public QObject
{
    Q_OBJECT
public:
    RegistrationManager();
    ~RegistrationManager();
public slots:
    void registerNewUser(const QString&, const QString&);
    void is_exist(const QString&);

signals:
    void employee_not_founded();
    void employee_is_founded();
    void unsuccessful_registration();
    void successful_registration();
    void not_allowed_to_registration();

private:/*Methods*/
    void setConnections();

private:
    int empl_id;
};

#endif // REGISTRATIONMANAGER_H
