#ifndef EMPLOYEESCHATPAGE_H
#define EMPLOYEESCHATPAGE_H

#include <QWidget>
#include <QSqlQuery>
#include <QLabel>
#include "messagechecker.h"

namespace Ui {
class EmployeesChatPage;
}

class EmployeesChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesChatPage(QWidget *parent = nullptr);
    ~EmployeesChatPage();
    void fillChatsWidget(QSqlQuery query = QSqlQuery{QSqlDatabase::database("local")}, bool is_search_res = false);
    void fillMessagesWidget(const uint, const QString&
                            , QLabel* partner_label = nullptr
                            , QPixmap pixmap = QPixmap{});
    void updateLastSeenTimestamp();
    void closeCurrentChat();
    struct ChatUnits{
        static const bool is_corporate = true;
        static bool is_chat_exist;
        static uint partner_id;
        static uint chat_id;
        static uint my_participant_id;
        static uint partner_participant_id;
        static void reset();
    };
private:
    void searchChats();
    void sendMessage();
    void chat_is_empty();

signals:
    void on_partner_profile_pic_btn_clicked(const uint);
    void notify_employee();

private:
    Ui::EmployeesChatPage *ui;
};

#endif // EMPLOYEESCHATPAGE_H
