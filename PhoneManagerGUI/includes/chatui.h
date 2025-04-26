#ifndef CHATUI_H
#define CHATUI_H

#include <QWidget>

namespace Ui {
class ChatUI;
}

class ChatUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChatUI(QWidget *parent = nullptr);
    ~ChatUI();

private:
    Ui::ChatUI *ui;
};


#endif // CHATUI_H
