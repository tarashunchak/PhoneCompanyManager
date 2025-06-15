#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <QObject>

class RegistrationManager : public QObject
{
    Q_OBJECT
public:
    RegistrationManager() = default;
    ~RegistrationManager() = default;

public slots:
    void registerNewUser(const QString&, const QString&);
    void is_exist(const QString&);

signals:
    void employee_not_founded();
    void employee_is_founded();
    void unsuccessful_registration();
    void successful_registration();
    void not_allowed_to_registration();
    void employee_allready_registered();

private:/*Methods*/
    void setConnections();

private:
    int empl_id;
};

#endif // REGISTRATIONMANAGER_H
