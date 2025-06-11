/********************************************************************************
** Form generated from reading UI file 'tariffspage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARIFFSPAGE_H
#define UI_TARIFFSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TariffsPage
{
public:
    QWidget *widget;
    QLineEdit *lineEdit;
    QPushButton *add_tariff_btn;
    QLabel *label;
    QFrame *frame;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *TariffsPage)
    {
        if (TariffsPage->objectName().isEmpty())
            TariffsPage->setObjectName("TariffsPage");
        TariffsPage->resize(1670, 1080);
        TariffsPage->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font-family:Lato, Consolas;"));
        widget = new QWidget(TariffsPage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1670, 80));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgba(200, 200, 200, 1);"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(1335, 23, 290, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:black;\n"
"text-align:left;\n"
"padding-left:4px;\n"
"padding-bottom:2px;\n"
"border:none;\n"
"border-radius:4px;\n"
"background-color:rgb(220, 220, 220);\n"
"font-family:Lato, Arial, Consolas;"));
        add_tariff_btn = new QPushButton(widget);
        add_tariff_btn->setObjectName("add_tariff_btn");
        add_tariff_btn->setGeometry(QRect(350, 23, 140, 34));
        add_tariff_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:white;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"border:none;\n"
"border-radius:4px;\n"
"font-size:16px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(220, 220, 220);\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 350, 70));
        label->setStyleSheet(QString::fromUtf8("font-family:Lato, Arial, Consolas;\n"
"font-size:32px;\n"
"padding-left:20px;\n"
"color:black;\n"
"background-color:rgb(200, 200, 200);"));
        frame = new QFrame(TariffsPage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 1030, 1670, 50));
        frame->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgba(42, 42, 42, 0.4);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        scrollArea = new QScrollArea(TariffsPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 80, 1670, 1000));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1668, 998));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 1671, 1001));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        widget->raise();
        scrollArea->raise();
        frame->raise();

        retranslateUi(TariffsPage);

        QMetaObject::connectSlotsByName(TariffsPage);
    } // setupUi

    void retranslateUi(QWidget *TariffsPage)
    {
        TariffsPage->setWindowTitle(QCoreApplication::translate("TariffsPage", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("TariffsPage", "Search Tariff by name or id", nullptr));
        add_tariff_btn->setText(QCoreApplication::translate("TariffsPage", "Add tariff", nullptr));
        label->setText(QCoreApplication::translate("TariffsPage", "Tariffs list page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TariffsPage: public Ui_TariffsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARIFFSPAGE_H
