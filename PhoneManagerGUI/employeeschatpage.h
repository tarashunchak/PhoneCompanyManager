#ifndef EMPLOYEESCHATPAGE_H
#define EMPLOYEESCHATPAGE_H

#include <QWidget>

namespace Ui {
class EmployeesChatPage;
}

class EmployeesChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesChatPage(QWidget *parent = nullptr);
    ~EmployeesChatPage();
    void fillChatsWidget()const;
    void fillMessagesWidget(const int)const;

private:
    void searchChats()const;

private:
    Ui::EmployeesChatPage *ui;
};

#endif // EMPLOYEESCHATPAGE_H
