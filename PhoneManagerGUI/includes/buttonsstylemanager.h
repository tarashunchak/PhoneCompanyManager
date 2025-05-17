#ifndef BUTTONSSTYLEMANAGER_H
#define BUTTONSSTYLEMANAGER_H

#include <QList>
#include <QPushButton>

class ButtonsStyleManager
{
public:
    enum class LEFT_SIDE_MENU : int{
        DASHBOARD_BTN = 0,
        CUSTOMERS_BTN,
        EMPLOYEES_BTN,
        TARIFFS_BTN,
        REQUESTS_BTN,
        TASKS_BTN,
        CHATS_BTN
    };
    explicit ButtonsStyleManager(QList<QPushButton*>*&);
    static void SetLeftMenuIcons(QList<QPushButton*>*);
    static void SetActiveButton(LEFT_SIDE_MENU);
    static QList<QPushButton*>* getButtonsList();

private:
    static QList<QPushButton*>* buttons_list;
};

#endif // BUTTONSSTYLEMANAGER_H
