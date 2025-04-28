#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class MessageBox : public QFrame
{
    Q_OBJECT
public:
    [[nodiscard]] MessageBox(QFrame* parent = nullptr);
    //Attach message data to message-box.
    void SetMessageText(QString);
    void SetMessageDateTime(QString);

private:
    void setMessageStyle();

private:
    QLabel* message_text;
    QLabel* message_date_time;
    QVBoxLayout* verticalLayout;

};

#endif // MESSAGEBOX_H
