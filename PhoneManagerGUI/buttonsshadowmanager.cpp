#include "buttonsshadowmanager.h"
#include <QGraphicsDropShadowEffect>

ButtonsShadowManager::ButtonsShadowManager() {}

void ButtonsShadowManager::setSideBarButtonsShadow(QList<QPushButton*> buttons){
    for(QPushButton* button : buttons){
        if(!button){
            qDebug() << "Buttons is nullptr!";
            return;
        }
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
        shadow->setBlurRadius(15);
        shadow->setXOffset(5);
        shadow->setYOffset(5);
        shadow->setColor(QColor(0, 0, 0, 180));
        button->setGraphicsEffect(shadow);
    }
}
