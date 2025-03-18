#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QWidget>
#include "registrationmanager.h"

namespace Ui {
class RegistrationPage;
}

class RegistrationPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationPage(QWidget *parent = nullptr);
    ~RegistrationPage();

signals:
    void on_confirm_btn_clicked();

private:/*Methods*/
    void SetConnections();

private:
    Ui::RegistrationPage *ui;
    RegistrationManager* reg_manager;
};

#endif // REGISTRATIONPAGE_H
