/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QPushButton *close_open_chat_btn;
    QWidget *side_bar_menu;
    QLabel *profile_pic;
    QPushButton *dashboard_btn;
    QPushButton *customers_btn;
    QLabel *side_menu_logo;
    QPushButton *employees_btn;
    QFrame *line;
    QPushButton *tariffs_btn;
    QPushButton *requests_btn;
    QPushButton *log_out_btn;
    QLabel *name_label;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *chats_btn;
    QLabel *logo_label;
    QPushButton *close_open_calc_btn;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(1920, 1080);
        MainWidget->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(250, 0, 1670, 1080));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        close_open_chat_btn = new QPushButton(MainWidget);
        close_open_chat_btn->setObjectName("close_open_chat_btn");
        close_open_chat_btn->setEnabled(true);
        close_open_chat_btn->setGeometry(QRect(1810, 980, 50, 50));
        close_open_chat_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:4px;\n"
"	background-color:rgb(57, 135, 57);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:rgb(57, 155, 57);\n"
"}"));
        close_open_chat_btn->setIconSize(QSize(40, 40));
        side_bar_menu = new QWidget(MainWidget);
        side_bar_menu->setObjectName("side_bar_menu");
        side_bar_menu->setGeometry(QRect(0, 0, 250, 1080));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(side_bar_menu->sizePolicy().hasHeightForWidth());
        side_bar_menu->setSizePolicy(sizePolicy);
        side_bar_menu->setStyleSheet(QString::fromUtf8("border-right: 5px solid rgba(0, 0, 0, 0.3);\n"
"background-color:#73819C;"));
        profile_pic = new QLabel(side_bar_menu);
        profile_pic->setObjectName("profile_pic");
        profile_pic->setGeometry(QRect(35, 60, 180, 180));
        profile_pic->setStyleSheet(QString::fromUtf8("border:none;"));
        profile_pic->setScaledContents(true);
        dashboard_btn = new QPushButton(side_bar_menu);
        dashboard_btn->setObjectName("dashboard_btn");
        dashboard_btn->setGeometry(QRect(25, 330, 200, 55));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        font.setBold(true);
        font.setItalic(false);
        dashboard_btn->setFont(font);
        dashboard_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: Lato;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    background-color: rgba(39, 48, 141, 1);\n"
"    font-size: 24px;\n"
"    color: white;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(87, 91, 129, 1);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("ui/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/img/dashboards.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dashboard_btn->setIcon(icon);
        dashboard_btn->setIconSize(QSize(30, 30));
        dashboard_btn->setAutoExclusive(false);
        dashboard_btn->setFlat(false);
        customers_btn = new QPushButton(side_bar_menu);
        customers_btn->setObjectName("customers_btn");
        customers_btn->setGeometry(QRect(10, 405, 230, 45));
        customers_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: Lato;\n"
"	padding-left:35px;\n"
"    border-radius: 5px;\n"
"	border:none;\n"
"    background-color:rgba(80, 80, 80, 0.6);\n"
"    font-size: 24px;\n"
"    color: white;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(87, 91, 129, 1);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("ui/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/img/customers.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        customers_btn->setIcon(icon1);
        customers_btn->setIconSize(QSize(30, 30));
        side_menu_logo = new QLabel(side_bar_menu);
        side_menu_logo->setObjectName("side_menu_logo");
        side_menu_logo->setGeometry(QRect(20, 210, 200, 55));
        side_menu_logo->setStyleSheet(QString::fromUtf8("border:none;"));
        side_menu_logo->setPixmap(QPixmap(QString::fromUtf8("ui/img/company_name.svg")));
        side_menu_logo->setScaledContents(true);
        employees_btn = new QPushButton(side_bar_menu);
        employees_btn->setObjectName("employees_btn");
        employees_btn->setGeometry(QRect(10, 455, 230, 45));
        employees_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: Lato;\n"
"	padding-left:35px;\n"
"    border-radius: 5px;\n"
"	border:none;\n"
"    background-color:rgba(80, 80, 80, 0.6);\n"
"    font-size: 24px;\n"
"    color: white;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(87, 91, 129, 1);\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("ui/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/img/employee.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        employees_btn->setIcon(icon2);
        employees_btn->setIconSize(QSize(30, 30));
        line = new QFrame(side_bar_menu);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 390, 230, 1));
        line->setStyleSheet(QString::fromUtf8("background-color:white;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        tariffs_btn = new QPushButton(side_bar_menu);
        tariffs_btn->setObjectName("tariffs_btn");
        tariffs_btn->setGeometry(QRect(10, 505, 230, 45));
        tariffs_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: Lato;\n"
"	padding-left:35px;\n"
"    border-radius: 5px;\n"
"	border:none;\n"
"    background-color:rgba(80, 80, 80, 0.6);\n"
"    font-size: 24px;\n"
"    color: white;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(87, 91, 129, 1);\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("ui/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/img/tariffs.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        tariffs_btn->setIcon(icon3);
        tariffs_btn->setIconSize(QSize(30, 30));
        requests_btn = new QPushButton(side_bar_menu);
        requests_btn->setObjectName("requests_btn");
        requests_btn->setGeometry(QRect(10, 555, 230, 45));
        requests_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: Lato;\n"
"	padding-left:35px;\n"
"    border-radius: 5px;\n"
"	border:none;\n"
"    background-color:rgba(80, 80, 80, 0.6);\n"
"    font-size: 24px;\n"
"    color: white;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(87, 91, 129, 1);\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("ui/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/img/requests.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        requests_btn->setIcon(icon4);
        requests_btn->setIconSize(QSize(30, 30));
        log_out_btn = new QPushButton(side_bar_menu);
        log_out_btn->setObjectName("log_out_btn");
        log_out_btn->setGeometry(QRect(35, 950, 180, 40));
        log_out_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: Lato;\n"
"	padding-left:0px;\n"
"    border-radius: 5px;\n"
"	border:none;\n"
"    background-color:rgba(174, 62, 62, 1);\n"
"    font-size: 18px;\n"
"    color: white;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(87, 91, 129, 1);\n"
"}\n"
""));
        log_out_btn->setIconSize(QSize(30, 30));
        name_label = new QLabel(side_bar_menu);
        name_label->setObjectName("name_label");
        name_label->setGeometry(QRect(0, 270, 250, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lato")});
        font1.setPointSize(20);
        name_label->setFont(font1);
        name_label->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-family:Lato, Arial, Consolas;\n"
"color:black;\n"
"background-color:transparent;"));
        name_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        line_2 = new QFrame(side_bar_menu);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 325, 230, 1));
        line_2->setStyleSheet(QString::fromUtf8("background-color:white;"));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(side_bar_menu);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(10, 665, 230, 1));
        line_3->setStyleSheet(QString::fromUtf8("background-color:white;"));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        chats_btn = new QPushButton(side_bar_menu);
        chats_btn->setObjectName("chats_btn");
        chats_btn->setGeometry(QRect(10, 605, 230, 45));
        chats_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: Lato;\n"
"	padding-left:35px;\n"
"    border-radius: 5px;\n"
"	border:none;\n"
"    background-color:rgba(80, 80, 80, 0.6);\n"
"    font-size: 24px;\n"
"    color: white;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(87, 91, 129, 1);\n"
"}\n"
""));
        chats_btn->setIcon(icon4);
        chats_btn->setIconSize(QSize(30, 30));
        logo_label = new QLabel(side_bar_menu);
        logo_label->setObjectName("logo_label");
        logo_label->setGeometry(QRect(0, 0, 250, 50));
        logo_label->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
        logo_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dashboard_btn->raise();
        customers_btn->raise();
        side_menu_logo->raise();
        employees_btn->raise();
        profile_pic->raise();
        line->raise();
        tariffs_btn->raise();
        requests_btn->raise();
        log_out_btn->raise();
        name_label->raise();
        line_2->raise();
        line_3->raise();
        chats_btn->raise();
        logo_label->raise();
        close_open_calc_btn = new QPushButton(MainWidget);
        close_open_calc_btn->setObjectName("close_open_calc_btn");
        close_open_calc_btn->setEnabled(true);
        close_open_calc_btn->setGeometry(QRect(1730, 980, 50, 50));
        close_open_calc_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:4px;\n"
"	background-color:rgb(57, 135, 57);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:rgb(57, 155, 57);\n"
"}"));
        close_open_calc_btn->setIconSize(QSize(40, 40));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
        close_open_chat_btn->setText(QString());
        profile_pic->setText(QString());
        dashboard_btn->setText(QCoreApplication::translate("MainWidget", "Dashboard", nullptr));
        customers_btn->setText(QCoreApplication::translate("MainWidget", "Customers", nullptr));
        side_menu_logo->setText(QString());
        employees_btn->setText(QCoreApplication::translate("MainWidget", "Employees", nullptr));
        tariffs_btn->setText(QCoreApplication::translate("MainWidget", "Tariffs", nullptr));
        requests_btn->setText(QCoreApplication::translate("MainWidget", "Requests", nullptr));
        log_out_btn->setText(QCoreApplication::translate("MainWidget", "Log Out", nullptr));
        name_label->setText(QCoreApplication::translate("MainWidget", "TextLabel", nullptr));
        chats_btn->setText(QCoreApplication::translate("MainWidget", "Chats", nullptr));
        logo_label->setText(QString());
        close_open_calc_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
