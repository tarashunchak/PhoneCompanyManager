#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include "authmanager.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

signals:
    void login_succsess();
    void on_registration_Link_linkActivated(const QString &link);

private: /*Methods*/
    void setConnections();

private:
    Ui::LoginPage *ui;
    AuthManager* authManager;
};

#endif // LOGINPAGE_H
