#ifndef PASSWORDRECOVERYPAGE_H
#define PASSWORDRECOVERYPAGE_H

#include <QWidget>
#include <QFile>
#include <QProcess>
#include <fstream>

namespace Ui {
class PasswordRecoveryPage;
}

class PasswordRecoveryPage : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordRecoveryPage(QWidget *parent = nullptr);
    ~PasswordRecoveryPage();

public slots:
    void SendMessageToEmail();

signals:
    void on_return_to_login_btn_clicked();

private:
    Ui::PasswordRecoveryPage *ui;
    std::fstream file;
    QProcess process;
};

#endif // PASSWORDRECOVERYPAGE_H
