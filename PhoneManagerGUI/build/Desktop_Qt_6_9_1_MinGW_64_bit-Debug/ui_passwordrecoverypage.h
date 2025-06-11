/********************************************************************************
** Form generated from reading UI file 'passwordrecoverypage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDRECOVERYPAGE_H
#define UI_PASSWORDRECOVERYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordRecoveryPage
{
public:
    QLabel *label_4;
    QLabel *incorrect_data_Label;
    QLabel *label_2;
    QLabel *error_message;
    QWidget *confirmed_widget;
    QLineEdit *code_LineEdit;
    QLineEdit *email_LineEdit;
    QLabel *label;
    QPushButton *confirm_btn;
    QPushButton *return_to_login_btn;
    QPushButton *check_code_btn;

    void setupUi(QWidget *PasswordRecoveryPage)
    {
        if (PasswordRecoveryPage->objectName().isEmpty())
            PasswordRecoveryPage->setObjectName("PasswordRecoveryPage");
        PasswordRecoveryPage->resize(1920, 1080);
        PasswordRecoveryPage->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-family:Lato, Consolas;"));
        label_4 = new QLabel(PasswordRecoveryPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(550, 1431, 49, 16));
        incorrect_data_Label = new QLabel(PasswordRecoveryPage);
        incorrect_data_Label->setObjectName("incorrect_data_Label");
        incorrect_data_Label->setGeometry(QRect(1090, 1131, 211, 21));
        incorrect_data_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-size:14px;"));
        label_2 = new QLabel(PasswordRecoveryPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 1301, 49, 16));
        error_message = new QLabel(PasswordRecoveryPage);
        error_message->setObjectName("error_message");
        error_message->setGeometry(QRect(750, 550, 410, 23));
        error_message->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"background-color:transparent;\n"
"font-size:16px;\n"
"color:red;"));
        error_message->setAlignment(Qt::AlignmentFlag::AlignCenter);
        confirmed_widget = new QWidget(PasswordRecoveryPage);
        confirmed_widget->setObjectName("confirmed_widget");
        confirmed_widget->setGeometry(QRect(750, 410, 410, 350));
        confirmed_widget->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-family:Lato, Arial, Consolas;\n"
""));
        code_LineEdit = new QLineEdit(confirmed_widget);
        code_LineEdit->setObjectName("code_LineEdit");
        code_LineEdit->setGeometry(QRect(50, 100, 320, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        font.setPointSize(14);
        code_LineEdit->setFont(font);
        code_LineEdit->setStyleSheet(QString::fromUtf8("border-radius:4px;\n"
"background-color:white;\n"
"color:black;\n"
"border:1px solid rgba(0, 0, 0, 0.6);"));
        email_LineEdit = new QLineEdit(confirmed_widget);
        email_LineEdit->setObjectName("email_LineEdit");
        email_LineEdit->setGeometry(QRect(50, 50, 320, 40));
        email_LineEdit->setFont(font);
        email_LineEdit->setStyleSheet(QString::fromUtf8("border-radius:4px;\n"
"background-color:white;\n"
"color:black;\n"
"border:1px solid rgba(0, 0, 0, 0.6);"));
        label = new QLabel(PasswordRecoveryPage);
        label->setObjectName("label");
        label->setGeometry(QRect(680, 310, 560, 100));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lato")});
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:80px;"));
        label->setTextFormat(Qt::TextFormat::AutoText);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        confirm_btn = new QPushButton(PasswordRecoveryPage);
        confirm_btn->setObjectName("confirm_btn");
        confirm_btn->setGeometry(QRect(800, 572, 320, 40));
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
        return_to_login_btn = new QPushButton(PasswordRecoveryPage);
        return_to_login_btn->setObjectName("return_to_login_btn");
        return_to_login_btn->setGeometry(QRect(40, 30, 40, 40));
        return_to_login_btn->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        return_to_login_btn->setIconSize(QSize(50, 50));
        check_code_btn = new QPushButton(PasswordRecoveryPage);
        check_code_btn->setObjectName("check_code_btn");
        check_code_btn->setGeometry(QRect(800, 572, 320, 40));
        check_code_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        retranslateUi(PasswordRecoveryPage);

        QMetaObject::connectSlotsByName(PasswordRecoveryPage);
    } // setupUi

    void retranslateUi(QWidget *PasswordRecoveryPage)
    {
        PasswordRecoveryPage->setWindowTitle(QCoreApplication::translate("PasswordRecoveryPage", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("PasswordRecoveryPage", "TextLabel", nullptr));
        incorrect_data_Label->setText(QCoreApplication::translate("PasswordRecoveryPage", "Incorrect Username or Password!", nullptr));
        label_2->setText(QCoreApplication::translate("PasswordRecoveryPage", "TextLabel", nullptr));
        error_message->setText(QCoreApplication::translate("PasswordRecoveryPage", "There is no employee with this email!", nullptr));
        code_LineEdit->setPlaceholderText(QCoreApplication::translate("PasswordRecoveryPage", "Code From E-Mail", nullptr));
        email_LineEdit->setPlaceholderText(QCoreApplication::translate("PasswordRecoveryPage", "Email", nullptr));
        label->setText(QCoreApplication::translate("PasswordRecoveryPage", "Pass Recovery", nullptr));
        confirm_btn->setText(QCoreApplication::translate("PasswordRecoveryPage", "Confirm", nullptr));
        return_to_login_btn->setText(QString());
        check_code_btn->setText(QCoreApplication::translate("PasswordRecoveryPage", "Check Code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordRecoveryPage: public Ui_PasswordRecoveryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDRECOVERYPAGE_H
