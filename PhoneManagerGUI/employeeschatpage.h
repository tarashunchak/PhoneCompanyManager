#ifndef EMPLOYEESCHATPAGE_H
#define EMPLOYEESCHATPAGE_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class EmployeesChatPage;
}

class EmployeesChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesChatPage(QWidget *parent = nullptr);
    ~EmployeesChatPage();
    void fillChatsWidget(QSqlQuery query = QSqlQuery{});
    void fillMessagesWidget(const int, const QString&, QPixmap pixmap = QPixmap{});
    void updateLastSeenTimestamp();

private:
    void searchChats();
    void sendMessage();
    void chat_is_empty();

private:
    Ui::EmployeesChatPage *ui;
    int user_id{};
    int chat_id{};
};

#endif // EMPLOYEESCHATPAGE_H
