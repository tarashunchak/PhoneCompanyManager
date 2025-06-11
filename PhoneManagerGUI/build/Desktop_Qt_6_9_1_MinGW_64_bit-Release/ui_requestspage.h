/********************************************************************************
** Form generated from reading UI file 'requestspage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTSPAGE_H
#define UI_REQUESTSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequestsPage
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *save_btn;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *unassigned_req_btn;
    QPushButton *in_progress_req_btn;
    QPushButton *complete_req_btn;
    QPushButton *history_btn;
    QLabel *no_requests_label;

    void setupUi(QWidget *RequestsPage)
    {
        if (RequestsPage->objectName().isEmpty())
            RequestsPage->setObjectName("RequestsPage");
        RequestsPage->resize(1670, 1080);
        RequestsPage->setStyleSheet(QString::fromUtf8("background-color:rgb(150, 150, 150);\n"
"font-family:Lato, Arial, Consolas;"));
        scrollArea = new QScrollArea(RequestsPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setEnabled(true);
        scrollArea->setGeometry(QRect(0, 110, 1670, 970));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1668, 968));
        save_btn = new QPushButton(scrollAreaWidgetContents);
        save_btn->setObjectName("save_btn");
        save_btn->setGeometry(QRect(715, 860, 240, 40));
        save_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:20px;\n"
"border:1px solid rgba(0, 0, 0, 0.4);\n"
"background-color:rgb(27, 104, 87);\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:24px;\n"
"}QPushButton:hover{\n"
"background-color:rgb(7, 84, 67);\n"
"}\n"
""));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(RequestsPage);
        label->setObjectName("label");
        label->setEnabled(false);
        label->setGeometry(QRect(0, 0, 1670, 70));
        label->setStyleSheet(QString::fromUtf8("font-family:Lato, Arial, Consolas;\n"
"font-size:32px;\n"
"padding-left:20px;\n"
"color:black;\n"
"background-color:rgb(200, 200, 200);"));
        layoutWidget = new QWidget(RequestsPage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 70, 1671, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        unassigned_req_btn = new QPushButton(layoutWidget);
        unassigned_req_btn->setObjectName("unassigned_req_btn");
        unassigned_req_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"height:40px;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:22px;\n"
"background-color:rgb(220, 220, 220);\n"
"border-top-left-radius:5px;\n"
"border-top-right-radius:5px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:white;\n"
"}"));

        horizontalLayout->addWidget(unassigned_req_btn);

        in_progress_req_btn = new QPushButton(layoutWidget);
        in_progress_req_btn->setObjectName("in_progress_req_btn");
        in_progress_req_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"height:40px;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:22px;\n"
"background-color:rgb(220, 220, 220);\n"
"border-top-left-radius:5px;\n"
"border-top-right-radius:5px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:white;\n"
"}"));

        horizontalLayout->addWidget(in_progress_req_btn);

        complete_req_btn = new QPushButton(layoutWidget);
        complete_req_btn->setObjectName("complete_req_btn");
        complete_req_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"height:40px;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:22px;\n"
"background-color:rgb(220, 220, 220);\n"
"border-top-left-radius:5px;\n"
"border-top-right-radius:5px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:white;\n"
"}"));

        horizontalLayout->addWidget(complete_req_btn);

        history_btn = new QPushButton(layoutWidget);
        history_btn->setObjectName("history_btn");
        history_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"height:40px;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:22px;\n"
"background-color:rgb(220, 220, 220);\n"
"border-top-left-radius:5px;\n"
"border-top-right-radius:5px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:white;\n"
"}"));

        horizontalLayout->addWidget(history_btn);

        no_requests_label = new QLabel(RequestsPage);
        no_requests_label->setObjectName("no_requests_label");
        no_requests_label->setEnabled(false);
        no_requests_label->setGeometry(QRect(0, 110, 1670, 970));
        no_requests_label->setStyleSheet(QString::fromUtf8("font-family:Lato, Arial, Consolas;\n"
"font-size:54px;\n"
"color:black;\n"
"background:transparent;\n"
"border:none;\n"
""));
        no_requests_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget->raise();
        label->raise();
        scrollArea->raise();
        no_requests_label->raise();

        retranslateUi(RequestsPage);

        QMetaObject::connectSlotsByName(RequestsPage);
    } // setupUi

    void retranslateUi(QWidget *RequestsPage)
    {
        RequestsPage->setWindowTitle(QCoreApplication::translate("RequestsPage", "Form", nullptr));
        save_btn->setText(QCoreApplication::translate("RequestsPage", "Save", nullptr));
        label->setText(QCoreApplication::translate("RequestsPage", "Customers requests", nullptr));
        unassigned_req_btn->setText(QCoreApplication::translate("RequestsPage", "Unassigned", nullptr));
        in_progress_req_btn->setText(QCoreApplication::translate("RequestsPage", "In Progress", nullptr));
        complete_req_btn->setText(QCoreApplication::translate("RequestsPage", "Completed", nullptr));
        history_btn->setText(QCoreApplication::translate("RequestsPage", "History", nullptr));
        no_requests_label->setText(QCoreApplication::translate("RequestsPage", "No Requests!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RequestsPage: public Ui_RequestsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTSPAGE_H
