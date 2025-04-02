#ifndef BUTTONSSTYLEMANAGER_H
#define BUTTONSSTYLEMANAGER_H

#include <QList>
#include <QPushButton>

class ButtonsStyleManager
{
public:
    static void SetLeftMenuIcons(QList<QPushButton*>);
private:
    ButtonsStyleManager() = delete;
};

#endif // BUTTONSSTYLEMANAGER_H
