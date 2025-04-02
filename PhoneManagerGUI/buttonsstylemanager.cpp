#include "includes/buttonsstylemanager.h"

void ButtonsStyleManager::SetLeftMenuIcons(QList<QPushButton*> buttons){

    //Dashboard Button
    buttons[0]->setIcon(QIcon("./img/dashboards.png"));
    //Customers Button
    buttons[1]->setIcon(QIcon("./img/customers.png"));
    //Employees Button
    buttons[2]->setIcon(QIcon("./img/employee.png"));
    //Tariff Button
    buttons[3]->setIcon(QIcon("./img/tariffs.png"));
    //Requests Button
    buttons[4]->setIcon(QIcon("./img/requests.png"));

}
