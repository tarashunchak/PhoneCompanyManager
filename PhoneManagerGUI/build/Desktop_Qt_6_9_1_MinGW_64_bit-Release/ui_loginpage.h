/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QPushButton *confirm_btn;
    QLabel *label;
    QLabel *incorrect_data_Label;
    QPushButton *registration_btn;
    QPushButton *pass_rec_btn;
    QLabel *label_2;
    QLineEdit *username_LineEdit;
    QLineEdit *password_LineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(1920, 1080);
        LoginPage->setMinimumSize(QSize(1920, 0));
        LoginPage->setStyleSheet(QString::fromUtf8("font-family:Lato, Consolas;\n"
"background-color:rgb(205, 205, 205);"));
        confirm_btn = new QPushButton(LoginPage);
        confirm_btn->setObjectName("confirm_btn");
        confirm_btn->setGeometry(QRect(795, 585, 330, 40));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(confirm_btn->sizePolicy().hasHeightForWidth());
        confirm_btn->setSizePolicy(sizePolicy);
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
        label = new QLabel(LoginPage);
        label->setObjectName("label");
        label->setGeometry(QRect(845, 300, 230, 100));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato;\n"
"font-size:80px;"));
        incorrect_data_Label = new QLabel(LoginPage);
        incorrect_data_Label->setObjectName("incorrect_data_Label");
        incorrect_data_Label->setEnabled(false);
        incorrect_data_Label->setGeometry(QRect(850, 550, 220, 20));
        sizePolicy.setHeightForWidth(incorrect_data_Label->sizePolicy().hasHeightForWidth());
        incorrect_data_Label->setSizePolicy(sizePolicy);
        incorrect_data_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-size:14px;"));
        registration_btn = new QPushButton(LoginPage);
        registration_btn->setObjectName("registration_btn");
        registration_btn->setGeometry(QRect(905, 640, 110, 25));
        sizePolicy.setHeightForWidth(registration_btn->sizePolicy().hasHeightForWidth());
        registration_btn->setSizePolicy(sizePolicy);
        registration_btn->setStyleSheet(QString::fromUtf8("text-decoration:underline;\n"
"color:rgb(47, 85, 255);\n"
"border:none;\n"
"font-size:14px;\n"
"font-family:Lato;\n"
"background-color:transparent;"));
        pass_rec_btn = new QPushButton(LoginPage);
        pass_rec_btn->setObjectName("pass_rec_btn");
        pass_rec_btn->setGeometry(QRect(900, 680, 120, 25));
        sizePolicy.setHeightForWidth(pass_rec_btn->sizePolicy().hasHeightForWidth());
        pass_rec_btn->setSizePolicy(sizePolicy);
        pass_rec_btn->setStyleSheet(QString::fromUtf8("text-decoration:underline;\n"
"color:rgb(47, 85, 255);\n"
"border:none;\n"
"font-size:14px;\n"
"font-family:Lato;\n"
"background-color:transparent;"));
        label_2 = new QLabel(LoginPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(955, 663, 16, 20));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(47, 85, 255);\n"
"font-size:14px;\n"
"font-family:Lato;\n"
"background-color:transparent;"));
        username_LineEdit = new QLineEdit(LoginPage);
        username_LineEdit->setObjectName("username_LineEdit");
        username_LineEdit->setGeometry(QRect(795, 440, 330, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(username_LineEdit->sizePolicy().hasHeightForWidth());
        username_LineEdit->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lato")});
        font1.setPointSize(14);
        username_LineEdit->setFont(font1);
        username_LineEdit->setStyleSheet(QString::fromUtf8("border-radius:4px;\n"
"background-color:white;\n"
"color:black;\n"
"border:1px solid rgba(0, 0, 0, 0.6);"));
        password_LineEdit = new QLineEdit(LoginPage);
        password_LineEdit->setObjectName("password_LineEdit");
        password_LineEdit->setGeometry(QRect(795, 500, 330, 40));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(password_LineEdit->sizePolicy().hasHeightForWidth());
        password_LineEdit->setSizePolicy(sizePolicy2);
        password_LineEdit->setFont(font1);
        password_LineEdit->setStyleSheet(QString::fromUtf8("border-radius:4px;\n"
"background-color:white;\n"
"color:black;\n"
"border:1px solid rgba(0, 0, 0, 0.6);"));
        password_LineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton = new QPushButton(LoginPage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1090, 502, 33, 36));
        pushButton->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:white;\n"
"color:black;\n"
"border-top-right-radius:4px;\n"
"border-bottom-right-radius:4px;"));

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        confirm_btn->setText(QCoreApplication::translate("LoginPage", "Confirm", nullptr));
        label->setText(QCoreApplication::translate("LoginPage", "Log In", nullptr));
        incorrect_data_Label->setText(QCoreApplication::translate("LoginPage", "Incorrect Username or Password!", nullptr));
        registration_btn->setText(QCoreApplication::translate("LoginPage", "Create Account?", nullptr));
        pass_rec_btn->setText(QCoreApplication::translate("LoginPage", "Forgot Password?", nullptr));
        label_2->setText(QCoreApplication::translate("LoginPage", "or", nullptr));
        username_LineEdit->setPlaceholderText(QCoreApplication::translate("LoginPage", "Username", nullptr));
        password_LineEdit->setPlaceholderText(QCoreApplication::translate("LoginPage", "Password", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
