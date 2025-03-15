#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QWidget>

namespace Ui {
class RegistrationPage;
}

class RegistrationPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationPage(QWidget *parent = nullptr);
    ~RegistrationPage();

private:
    Ui::RegistrationPage *ui;
};

#endif // REGISTRATIONPAGE_H
