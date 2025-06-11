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
    void fillMessagesWidget(const uint, const uint, const QString&
                            , QLabel* partner_label = nullptr
                            , QPixmap pixmap = QPixmap{});
    void updateLastSeenTimestamp();
    struct ChatUnits{
        static const bool is_corporate = true;
        static bool is_chat_exist;
        static uint partner_id;
        static uint chat_id;
        static uint my_participant_id;
        static uint partner_participant_id;
        static void reset();
    };
    void clearChat();
private:
    void searchChats();
    void sendMessage();
    void chat_is_empty();
private:
    Ui::EmployeesChatPage *ui;
};

#endif // EMPLOYEESCHATPAGE_H
