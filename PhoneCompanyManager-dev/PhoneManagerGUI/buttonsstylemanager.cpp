#include "includes/buttonsstylemanager.h"

ButtonsStyleManager::ButtonsStyleManager(QList<QPushButton*>*& buttons){
    delete buttons_list;
    buttons_list = buttons;
    buttons = nullptr;
    SetLeftMenuIcons(buttons_list);
}

QList<QPushButton*>* ButtonsStyleManager::buttons_list = nullptr;

QList<QPushButton*>* ButtonsStyleManager::getButtonsList(){
    return buttons_list;
}

void ButtonsStyleManager::SetLeftMenuIcons(QList<QPushButton*>* buttons){
    //Dashboard Button
    buttons->at(0)->setIcon(QIcon("./img/dashboards.png"));
    //Customers Button
    buttons->at(1)->setIcon(QIcon("./img/customers.png"));
    //Employees Button
    buttons->at(2)->setIcon(QIcon("./img/employee.png"));
    //Tariff Button
    buttons->at(3)->setIcon(QIcon("./img/tariffs.png"));
    //Requests Button
    buttons->at(4)->setIcon(QIcon("./img/requests.png"));
    //Tasks Button
    buttons->at(5)->setIcon(QIcon("./img/task.png"));
    //Chats Button
    buttons->at(6)->setIcon(QIcon("./img/chat.png"));
}

void ButtonsStyleManager::SetActiveButton(LEFT_SIDE_MENU active_button){
    static const QString hover{
                "QPushButton:hover {"
                "background-color: rgba(87, 91, 129, 1);"
                "}"};

    for(int i = 0; i < buttons_list->size(); ++i){
        if(i == static_cast<int>(LEFT_SIDE_MENU::DASHBOARD_BTN)){
            if(i == static_cast<int>(active_button)){
                buttons_list->at(i)->setStyleSheet(
                    "QPushButton { "
                        "font-family: Lato;"
                        "border: none;"
                        "border-radius: 5px;"
                        "background-color: rgba(39, 48, 141, 1);"
                        "font-size: 24px;"
                        "color: white;"
                        "text-align: center;"
                    "}" + hover);
            }else{
                buttons_list->at(i)->setStyleSheet(
                    "QPushButton { "
                        "font-family: Lato;"
                        "border: none;"
                        "border-radius: 5px;"
                        "background-color:rgba(80, 80, 80, 0.6);"
                        "font-size: 24px;"
                        "color: white;"
                        "text-align: center;"
                    "}" + hover);
            }
        }else{
            if(i == static_cast<int>(active_button)){
                buttons_list->at(i)->setStyleSheet(
                "QPushButton { "
                    "font-family: Lato;"
                    "padding-left:35px;"
                    "border: none;"
                    "border-radius: 5px;"
                    "background-color: rgba(39, 48, 141, 1);"
                    "font-size: 24px;"
                    "color: white;"
                    "text-align: left;"
                "}" + hover);
            }else{
                buttons_list->at(i)->setStyleSheet(
                "QPushButton {"
                    "font-family: Lato;"
                    "padding-left:35px;"
                    "border-radius: 5px;"
                    "border:none;"
                    "background-color:rgba(80, 80, 80, 0.6);"
                    "font-size: 24px;"
                    "color: white;"
                    "text-align: left;"
                "}" + hover);
            }
        }
    }
}
