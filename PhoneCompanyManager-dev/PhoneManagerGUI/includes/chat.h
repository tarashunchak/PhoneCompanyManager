#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QSqlQuery>

namespace Ui {
class ChatUI;
}

class Chat : public QFrame
{
    Q_OBJECT

public:
    explicit Chat(QFrame *parent = nullptr);
    ~Chat();

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
    static uint curr_chat_id;
    static uint curr_cust_id;
};


#endif // CHAT_H
