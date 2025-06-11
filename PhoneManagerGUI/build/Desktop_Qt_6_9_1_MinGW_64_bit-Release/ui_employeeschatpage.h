/********************************************************************************
** Form generated from reading UI file 'employeeschatpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEESCHATPAGE_H
#define UI_EMPLOYEESCHATPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeesChatPage
{
public:
    QWidget *side_menu_widget;
    QLineEdit *search_lineEdit;
    QScrollArea *chats_scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *chats_widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *chats_vLayout;
    QWidget *header_widget;
    QLabel *profile_pic_label;
    QLabel *empl_full_name_label;
    QLabel *last_seen_label;
    QLineEdit *message_input_lineEdit;
    QPushButton *send_message_btn;
    QWidget *message_area_widget;
    QScrollArea *messages_scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *messages_widget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *messages_vLayout;
    QWidget *empty_chat_widget;
    QPushButton *say_hello_btn;
    QLabel *label;

    void setupUi(QWidget *EmployeesChatPage)
    {
        if (EmployeesChatPage->objectName().isEmpty())
            EmployeesChatPage->setObjectName("EmployeesChatPage");
        EmployeesChatPage->resize(1670, 1080);
        EmployeesChatPage->setStyleSheet(QString::fromUtf8(""));
        side_menu_widget = new QWidget(EmployeesChatPage);
        side_menu_widget->setObjectName("side_menu_widget");
        side_menu_widget->setGeometry(QRect(0, 0, 360, 1080));
        side_menu_widget->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgb(25, 30, 50);\n"
"color:white;"));
        search_lineEdit = new QLineEdit(side_menu_widget);
        search_lineEdit->setObjectName("search_lineEdit");
        search_lineEdit->setGeometry(QRect(30, 15, 300, 40));
        search_lineEdit->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:16px;\n"
"padding-left:18px;\n"
"background-color:rgb(20, 20, 20);\n"
"border-radius:20px;"));
        search_lineEdit->setCursorPosition(0);
        chats_scrollArea = new QScrollArea(side_menu_widget);
        chats_scrollArea->setObjectName("chats_scrollArea");
        chats_scrollArea->setGeometry(QRect(0, 70, 360, 991));
        chats_scrollArea->setFrameShadow(QFrame::Shadow::Raised);
        chats_scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 360, 991));
        chats_widget = new QWidget(scrollAreaWidgetContents_2);
        chats_widget->setObjectName("chats_widget");
        chats_widget->setGeometry(QRect(0, 0, 360, 1001));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chats_widget->sizePolicy().hasHeightForWidth());
        chats_widget->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(chats_widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 361, 1001));
        chats_vLayout = new QVBoxLayout(verticalLayoutWidget);
        chats_vLayout->setObjectName("chats_vLayout");
        chats_vLayout->setContentsMargins(0, 0, 0, 0);
        chats_scrollArea->setWidget(scrollAreaWidgetContents_2);
        header_widget = new QWidget(EmployeesChatPage);
        header_widget->setObjectName("header_widget");
        header_widget->setGeometry(QRect(360, -1, 1310, 71));
        header_widget->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgb(25, 30, 50);\n"
"color:white;"));
        profile_pic_label = new QLabel(header_widget);
        profile_pic_label->setObjectName("profile_pic_label");
        profile_pic_label->setGeometry(QRect(30, 10, 50, 50));
        profile_pic_label->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"background-color:white;"));
        empl_full_name_label = new QLabel(header_widget);
        empl_full_name_label->setObjectName("empl_full_name_label");
        empl_full_name_label->setGeometry(QRect(90, 10, 300, 30));
        empl_full_name_label->setStyleSheet(QString::fromUtf8("font-family:Lato, Arial, Consolas;\n"
"font-size:24px;\n"
"background-color:transparent;\n"
"border:none;\n"
"color:white;"));
        last_seen_label = new QLabel(header_widget);
        last_seen_label->setObjectName("last_seen_label");
        last_seen_label->setGeometry(QRect(90, 40, 170, 20));
        last_seen_label->setStyleSheet(QString::fromUtf8("font-family:Lato, Arial, Consolas;\n"
"font-size:16px;\n"
"background-color:transparent;\n"
"border:none;"));
        message_input_lineEdit = new QLineEdit(EmployeesChatPage);
        message_input_lineEdit->setObjectName("message_input_lineEdit");
        message_input_lineEdit->setGeometry(QRect(624, 971, 811, 60));
        message_input_lineEdit->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:20px;\n"
"padding-left:40px;\n"
"background-color:rgb(30, 30, 30);\n"
"border-radius:12px;\n"
"border:1px solid rgba(140, 140, 140, 0.4);"));
        send_message_btn = new QPushButton(EmployeesChatPage);
        send_message_btn->setObjectName("send_message_btn");
        send_message_btn->setGeometry(QRect(1445, 970, 60, 60));
        send_message_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:30px;\n"
"background-color:rgb(56, 54, 106);\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgb(36, 34, 86);	\n"
"}"));
        message_area_widget = new QWidget(EmployeesChatPage);
        message_area_widget->setObjectName("message_area_widget");
        message_area_widget->setGeometry(QRect(360, 70, 1310, 1010));
        messages_scrollArea = new QScrollArea(EmployeesChatPage);
        messages_scrollArea->setObjectName("messages_scrollArea");
        messages_scrollArea->setGeometry(QRect(630, 70, 840, 871));
        messages_scrollArea->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
        messages_scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 840, 871));
        messages_widget = new QWidget(scrollAreaWidgetContents);
        messages_widget->setObjectName("messages_widget");
        messages_widget->setGeometry(QRect(0, 0, 840, 871));
        sizePolicy.setHeightForWidth(messages_widget->sizePolicy().hasHeightForWidth());
        messages_widget->setSizePolicy(sizePolicy);
        verticalLayoutWidget_2 = new QWidget(messages_widget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 841, 871));
        messages_vLayout = new QVBoxLayout(verticalLayoutWidget_2);
        messages_vLayout->setObjectName("messages_vLayout");
        messages_vLayout->setContentsMargins(0, 0, 0, 0);
        messages_scrollArea->setWidget(scrollAreaWidgetContents);
        empty_chat_widget = new QWidget(EmployeesChatPage);
        empty_chat_widget->setObjectName("empty_chat_widget");
        empty_chat_widget->setGeometry(QRect(915, 435, 200, 140));
        empty_chat_widget->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgba(25, 30, 50, 0.5);\n"
"border-radius:8px;\n"
"color:white;"));
        say_hello_btn = new QPushButton(empty_chat_widget);
        say_hello_btn->setObjectName("say_hello_btn");
        say_hello_btn->setGeometry(QRect(70, 100, 61, 27));
        say_hello_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"background-color:rgb(56, 54, 106);\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgb(36, 34, 86);	\n"
"}"));
        label = new QLabel(empty_chat_widget);
        label->setObjectName("label");
        label->setGeometry(QRect(22, 10, 161, 81));
        label->setStyleSheet(QString::fromUtf8("font-family:Lato, Arial, Consolas;\n"
"font-size:20px;\n"
"background-color:transparent;\n"
"color:white;\n"
"text-align:center;"));
        label->setScaledContents(true);
        label->setWordWrap(true);
        side_menu_widget->raise();
        header_widget->raise();
        message_area_widget->raise();
        message_input_lineEdit->raise();
        send_message_btn->raise();
        messages_scrollArea->raise();
        empty_chat_widget->raise();

        retranslateUi(EmployeesChatPage);

        QMetaObject::connectSlotsByName(EmployeesChatPage);
    } // setupUi

    void retranslateUi(QWidget *EmployeesChatPage)
    {
        EmployeesChatPage->setWindowTitle(QCoreApplication::translate("EmployeesChatPage", "Form", nullptr));
        search_lineEdit->setPlaceholderText(QCoreApplication::translate("EmployeesChatPage", "Search employee by name or id", nullptr));
        profile_pic_label->setText(QString());
        empl_full_name_label->setText(QCoreApplication::translate("EmployeesChatPage", "TextLabel", nullptr));
        last_seen_label->setText(QCoreApplication::translate("EmployeesChatPage", "TextLabel", nullptr));
        send_message_btn->setText(QString());
        say_hello_btn->setText(QCoreApplication::translate("EmployeesChatPage", "HI!!!", nullptr));
        label->setText(QCoreApplication::translate("EmployeesChatPage", "You haven't had a chat with this user yet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeesChatPage: public Ui_EmployeesChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEESCHATPAGE_H
