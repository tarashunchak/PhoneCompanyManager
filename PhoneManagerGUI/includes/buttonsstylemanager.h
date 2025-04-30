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
        REQUESTS_BTN
    };
    static void SetLeftMenuIcons(QList<QPushButton*>);
    void SetActiveButton(LEFT_SIDE_MENU);
    ButtonsStyleManager(QList<QPushButton*>);

private:
    QList<QPushButton*>* buttons_list;
};

#endif // BUTTONSSTYLEMANAGER_H
