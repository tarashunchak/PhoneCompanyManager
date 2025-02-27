#ifndef BUTTONSSHADOWMANAGER_H
#define BUTTONSSHADOWMANAGER_H

#include <QPushButton>
#include <QList>

class ButtonsShadowManager
{
public:
    ButtonsShadowManager();
    static void setSideBarButtonsShadow(QList<QPushButton*>);
};

#endif // BUTTONSSHADOWMANAGER_H
