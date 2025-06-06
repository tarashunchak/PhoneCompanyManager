#ifndef EMPLOYEESCHATPAGE_H
#define EMPLOYEESCHATPAGE_H

#include <QWidget>
#include <QSqlQuery>
#include <QLabel>

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
    void fillMessagesWidget(const int, const QString&
                            , QLabel* partner_label = nullptr
                            , QPixmap pixmap = QPixmap{});
    void updateLastSeenTimestamp();
private:
    struct ChatUnits{
        static uint user_id;
        static uint chat_id;
        static uint my_participant_id;
        static uint partner_participant_id;
        static void reset();
    };
    void searchChats();
    void sendMessage();
    void chat_is_empty();
private:
    Ui::EmployeesChatPage *ui;
};

#endif // EMPLOYEESCHATPAGE_H
