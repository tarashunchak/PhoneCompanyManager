/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatUI
{
public:
    QWidget *widget;
    QLineEdit *phone_lineEdit;
    QPushButton *phone_btn;
    QWidget *widget_2;
    QLineEdit *lineEdit;
    QPushButton *send_btn;
    QFrame *line;
    QPushButton *mode_btn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *empty_chat_label;

    void setupUi(QWidget *ChatUI)
    {
        if (ChatUI->objectName().isEmpty())
            ChatUI->setObjectName("ChatUI");
        ChatUI->setEnabled(true);
        ChatUI->resize(350, 600);
        ChatUI->setMinimumSize(QSize(350, 600));
        ChatUI->setMaximumSize(QSize(350, 600));
        ChatUI->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:rgb(25, 30, 35);\n"
"border-radius:5px;\n"
"font-family:Robotic;"));
        widget = new QWidget(ChatUI);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 350, 51));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(45, 45, 45);\n"
"border:none;\n"
"border-bottom-right-radius:0px;\n"
"border-bottom-left-radius:0px;"));
        phone_lineEdit = new QLineEdit(widget);
        phone_lineEdit->setObjectName("phone_lineEdit");
        phone_lineEdit->setGeometry(QRect(30, 10, 290, 30));
        phone_lineEdit->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:16px;\n"
"font-family:Lato;\n"
"background-color:rgb(140, 140, 140);\n"
"border:none;\n"
"border-radius:5px;"));
        phone_btn = new QPushButton(widget);
        phone_btn->setObjectName("phone_btn");
        phone_btn->setGeometry(QRect(30, 10, 290, 30));
        phone_btn->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"font-family:Robotic;\n"
"background-color:rgb(50, 50, 50);\n"
"border-radius:5px;\n"
"color:white;"));
        widget_2 = new QWidget(ChatUI);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 540, 350, 60));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(56, 56, 56);\n"
"border:none;\n"
"border-radius:0px;"));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(60, 11, 231, 36));
        QFont font;
        font.setFamilies({QString::fromUtf8("Robotic")});
        font.setPointSize(14);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:rgb(66, 66, 66);\n"
"border:1px solid rgb(146, 146, 146);\n"
"border-radius:18px;\n"
"padding-left:10px;"));
        send_btn = new QPushButton(widget_2);
        send_btn->setObjectName("send_btn");
        send_btn->setEnabled(true);
        send_btn->setGeometry(QRect(300, 10, 36, 36));
        send_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:gray;\n"
"	border:1px solid rgb(160, 160, 160);\n"
"	border-radius:18px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(140, 140, 140);\n"
"}"));
        send_btn->setIconSize(QSize(22, 22));
        line = new QFrame(widget_2);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 0, 350, 1));
        line->setStyleSheet(QString::fromUtf8("background-color:white;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        mode_btn = new QPushButton(widget_2);
        mode_btn->setObjectName("mode_btn");
        mode_btn->setGeometry(QRect(10, 10, 36, 36));
        mode_btn->setStyleSheet(QString::fromUtf8("background-color:rgb(66, 66, 66);\n"
"border:1px solid rgb(146, 146, 146);\n"
"border-radius:18px;"));
        verticalLayoutWidget = new QWidget(ChatUI);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 50, 351, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        empty_chat_label = new QLabel(ChatUI);
        empty_chat_label->setObjectName("empty_chat_label");
        empty_chat_label->setGeometry(QRect(0, 260, 350, 30));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(empty_chat_label->sizePolicy().hasHeightForWidth());
        empty_chat_label->setSizePolicy(sizePolicy);
        empty_chat_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:24px;\n"
"background-color:transparent;"));
        empty_chat_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(ChatUI);

        QMetaObject::connectSlotsByName(ChatUI);
    } // setupUi

    void retranslateUi(QWidget *ChatUI)
    {
        ChatUI->setWindowTitle(QCoreApplication::translate("ChatUI", "Form", nullptr));
        phone_btn->setText(QCoreApplication::translate("ChatUI", "Chose phone number", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("ChatUI", "Message", nullptr));
        send_btn->setText(QString());
        mode_btn->setText(QString());
        empty_chat_label->setText(QCoreApplication::translate("ChatUI", "Empty chat...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatUI: public Ui_ChatUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
