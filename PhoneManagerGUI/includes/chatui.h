#ifndef CHATUI_H
#define CHATUI_H

#include <QWidget>
#include "messagebox.h"

namespace Ui {
class ChatUI;
}

class ChatUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChatUI(QWidget *parent = nullptr);
    ~ChatUI();

private slots:
    void SendMessage()const;

private:
    Ui::ChatUI *ui;

};


#endif // CHATUI_H
