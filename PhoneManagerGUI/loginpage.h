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

private:
    Ui::LoginPage *ui;
    AuthManager* authManager;
};

#endif // LOGINPAGE_H
