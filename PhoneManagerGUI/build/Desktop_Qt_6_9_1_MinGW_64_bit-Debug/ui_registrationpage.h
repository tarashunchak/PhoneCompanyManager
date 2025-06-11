/********************************************************************************
** Form generated from reading UI file 'registrationpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONPAGE_H
#define UI_REGISTRATIONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationPage
{
public:
    QLabel *label_4;
    QLineEdit *email_LineEdit;
    QLabel *label_2;
    QLabel *label;
    QLabel *incorrect_data_Label;
    QWidget *confirmed_widget;
    QLineEdit *username_LineEdit;
    QLineEdit *rep_password_LineEdit;
    QLineEdit *password_LineEdit;
    QPushButton *confirm_btn;
    QPushButton *return_to_login_btn;
    QLabel *error_message;

    void setupUi(QWidget *RegistrationPage)
    {
        if (RegistrationPage->objectName().isEmpty())
            RegistrationPage->setObjectName("RegistrationPage");
        RegistrationPage->resize(1920, 1080);
        RegistrationPage->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_4 = new QLabel(RegistrationPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(550, 1440, 49, 16));
        email_LineEdit = new QLineEdit(RegistrationPage);
        email_LineEdit->setObjectName("email_LineEdit");
        email_LineEdit->setGeometry(QRect(800, 520, 320, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        font.setPointSize(14);
        email_LineEdit->setFont(font);
        email_LineEdit->setStyleSheet(QString::fromUtf8("border-radius:4px;\n"
"background-color:white;\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"border:1px solid rgba(0, 0, 0, 0.6);"));
        label_2 = new QLabel(RegistrationPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 1310, 49, 16));
        label = new QLabel(RegistrationPage);
        label->setObjectName("label");
        label->setGeometry(QRect(735, 320, 450, 100));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lato")});
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:80px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        incorrect_data_Label = new QLabel(RegistrationPage);
        incorrect_data_Label->setObjectName("incorrect_data_Label");
        incorrect_data_Label->setGeometry(QRect(1090, 1140, 211, 21));
        incorrect_data_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-size:14px;"));
        confirmed_widget = new QWidget(RegistrationPage);
        confirmed_widget->setObjectName("confirmed_widget");
        confirmed_widget->setGeometry(QRect(750, 420, 410, 350));
        confirmed_widget->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-family:Lato, Arial, Consolas;"));
        username_LineEdit = new QLineEdit(confirmed_widget);
        username_LineEdit->setObjectName("username_LineEdit");
        username_LineEdit->setGeometry(QRect(50, 40, 320, 40));
        username_LineEdit->setFont(font);
        username_LineEdit->setStyleSheet(QString::fromUtf8("border-radius:4px;\n"
"background-color:white;\n"
"color:black;\n"
"border:1px solid rgba(0, 0, 0, 0.6);"));
        rep_password_LineEdit = new QLineEdit(confirmed_widget);
        rep_password_LineEdit->setObjectName("rep_password_LineEdit");
        rep_password_LineEdit->setGeometry(QRect(50, 170, 320, 40));
        rep_password_LineEdit->setFont(font);
        rep_password_LineEdit->setStyleSheet(QString::fromUtf8("border-radius:4px;\n"
"background-color:white;\n"
"color:black;\n"
"border:1px solid rgba(0, 0, 0, 0.6);"));
        password_LineEdit = new QLineEdit(confirmed_widget);
        password_LineEdit->setObjectName("password_LineEdit");
        password_LineEdit->setGeometry(QRect(50, 101, 320, 40));
        password_LineEdit->setFont(font);
        password_LineEdit->setStyleSheet(QString::fromUtf8("border-radius:4px;\n"
"background-color:white;\n"
"color:black;\n"
"border:1px solid rgba(0, 0, 0, 0.6);"));
        confirm_btn = new QPushButton(RegistrationPage);
        confirm_btn->setObjectName("confirm_btn");
        confirm_btn->setGeometry(QRect(800, 590, 320, 40));
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1px solid black;\n"
"	border-radius:4px;\n"
"	color:white;\n"
"	font-size:18px;\n"
"	font-family:Lato;\n"
"	background-color:rgb(100, 100, 100);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(140, 140, 140);\n"
"}"));
        return_to_login_btn = new QPushButton(RegistrationPage);
        return_to_login_btn->setObjectName("return_to_login_btn");
        return_to_login_btn->setGeometry(QRect(40, 40, 40, 40));
        return_to_login_btn->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        return_to_login_btn->setIconSize(QSize(50, 50));
        error_message = new QLabel(RegistrationPage);
        error_message->setObjectName("error_message");
        error_message->setGeometry(QRect(805, 564, 310, 25));
        error_message->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"background-color:transparent;\n"
"font-size:16px;\n"
"color:rgb(252, 41, 41);\n"
"font-family:Lato, Arial, Consolas;"));
        error_message->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(RegistrationPage);

        QMetaObject::connectSlotsByName(RegistrationPage);
    } // setupUi

    void retranslateUi(QWidget *RegistrationPage)
    {
        RegistrationPage->setWindowTitle(QCoreApplication::translate("RegistrationPage", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("RegistrationPage", "TextLabel", nullptr));
        email_LineEdit->setPlaceholderText(QCoreApplication::translate("RegistrationPage", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("RegistrationPage", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("RegistrationPage", "Registration", nullptr));
        incorrect_data_Label->setText(QCoreApplication::translate("RegistrationPage", "Incorrect Username or Password!", nullptr));
        username_LineEdit->setPlaceholderText(QCoreApplication::translate("RegistrationPage", "Username", nullptr));
        rep_password_LineEdit->setPlaceholderText(QCoreApplication::translate("RegistrationPage", "Repeat password", nullptr));
        password_LineEdit->setPlaceholderText(QCoreApplication::translate("RegistrationPage", "Password", nullptr));
        confirm_btn->setText(QCoreApplication::translate("RegistrationPage", "Confirm", nullptr));
        return_to_login_btn->setText(QString());
        error_message->setText(QCoreApplication::translate("RegistrationPage", "There is no employee with this email!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationPage: public Ui_RegistrationPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONPAGE_H
