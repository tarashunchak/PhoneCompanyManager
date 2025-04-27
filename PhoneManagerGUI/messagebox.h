#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include <QDateTime>
#include <QString>

class MessageBox : public QWidget
{
    Q_OBJECT
public:
    MessageBox(QWidget* parent = nullptr);

private:
    QString message;
    QDateTime message_date_time;

};

#endif // MESSAGEBOX_H
