#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QSqlQuery>

namespace Ui {
class ChatUI;
}

class ChatUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChatUI(QWidget *parent = nullptr);
    ~ChatUI();

public slots:
    void SendMessage();
    void DisplayAllMessages(QSqlQuery query = QSqlQuery{});
    void DisplayLastMessage()const;

private:
    void phone_choose_handler();
    void find_phones_in_db(QString);
    bool is_exist(QString);

private:
    Ui::ChatUI *ui;
    QScrollArea* scrollArea;
    QWidget* mainWidget;
    QVBoxLayout* innerVBoxLayout;
    QString current_number;

};


#endif // CHAT_H
