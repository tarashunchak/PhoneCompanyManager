#ifndef PASSWORDRECOVERYPAGE_H
#define PASSWORDRECOVERYPAGE_H

#include <QWidget>

namespace Ui {
class PasswordRecoveryPage;
}

class PasswordRecoveryPage : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordRecoveryPage(QWidget *parent = nullptr);
    ~PasswordRecoveryPage();

signals:
    void on_return_to_login_btn_clicked();

private:
    Ui::PasswordRecoveryPage *ui;
};

#endif // PASSWORDRECOVERYPAGE_H
