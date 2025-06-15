#ifndef SUPPORTCHAT_H
#define SUPPORTCHAT_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QSqlQuery>

namespace Ui {
class ChatUI;
}

class SupportChat : public QFrame
{
    Q_OBJECT

public:
    explicit SupportChat(QFrame *parent = nullptr);
    ~SupportChat();
    struct ChatUnits{
        static const bool is_corporate = false;
        static bool is_chat_exist;
        static uint partner_id;
        static uint chat_id;
        static uint my_participant_id;
        static uint partner_participant_id;
        static uint last_message_id;
        static void reset();
    };

public slots:
    void SendMessage();
    void DisplayAllMessages(QSqlQuery& query);
    void DisplayLastMessage()const;
    void SetPhoneNumber(const QString&);

private:
    void phone_choose_handler();
    void find_phones_in_db(const QString&);
    bool is_exist();

private:
    Ui::ChatUI *ui;
    QScrollArea* scrollArea;
    QWidget* mainWidget;
    QVBoxLayout* innerVBoxLayout;
    static bool is_valid_partner;
};


#endif // SUPPORTCHAT_H
