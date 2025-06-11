/********************************************************************************
** Form generated from reading UI file 'taskspage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSPAGE_H
#define UI_TASKSPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TasksPage
{
public:
    QWidget *widget;
    QLabel *label;
    QPushButton *add_cust_btn;
    QTableView *tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *TasksPage)
    {
        if (TasksPage->objectName().isEmpty())
            TasksPage->setObjectName("TasksPage");
        TasksPage->resize(1670, 1080);
        TasksPage->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        widget = new QWidget(TasksPage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1670, 80));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgba(200, 200, 200, 1);"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 730, 70));
        label->setStyleSheet(QString::fromUtf8("font-family:Lato;\n"
"font-size:32px;\n"
"padding-left:20px;\n"
"color:black;\n"
"background-color:transparent;"));
        add_cust_btn = new QPushButton(widget);
        add_cust_btn->setObjectName("add_cust_btn");
        add_cust_btn->setGeometry(QRect(350, 23, 140, 34));
        add_cust_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:white;\n"
"color:black;\n"
"font-family:Lato;\n"
"border:none;\n"
"border-radius:4px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(220, 220, 220);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("build/Desktop_Qt_6_10_0-Debug/img/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        add_cust_btn->setIcon(icon);
        add_cust_btn->setIconSize(QSize(24, 24));
        tableView = new QTableView(TasksPage);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 121, 1671, 961));
        tableView->setStyleSheet(QString::fromUtf8("font-family:Consolas;\n"
"font-size:16px;\n"
"background-color:white;\n"
"color:black;"));
        tableView->verticalHeader()->setVisible(false);
        layoutWidget = new QWidget(TasksPage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 81, 1671, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"height:40px;\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:22px;\n"
"background-color:rgb(220, 220, 220);\n"
"border-top-left-radius:5px;\n"
"border-top-right-radius:5px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:white;\n"
"}"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"height:40px;\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:22px;\n"
"background-color:rgb(220, 220, 220);\n"
"border-top-left-radius:5px;\n"
"border-top-right-radius:5px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:white;\n"
"}"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(TasksPage);

        QMetaObject::connectSlotsByName(TasksPage);
    } // setupUi

    void retranslateUi(QWidget *TasksPage)
    {
        TasksPage->setWindowTitle(QCoreApplication::translate("TasksPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("TasksPage", "Tasks list page", nullptr));
        add_cust_btn->setText(QCoreApplication::translate("TasksPage", "Add Task", nullptr));
        pushButton->setText(QCoreApplication::translate("TasksPage", "Assigned to me", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TasksPage", "Created by me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TasksPage: public Ui_TasksPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSPAGE_H
