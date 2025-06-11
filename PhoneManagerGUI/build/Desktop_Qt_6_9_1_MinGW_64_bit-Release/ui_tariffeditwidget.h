/********************************************************************************
** Form generated from reading UI file 'tariffeditwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARIFFEDITWIDGET_H
#define UI_TARIFFEDITWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TariffEditWidget
{
public:
    QPushButton *calcel_btn;
    QPushButton *save_btn;
    QLabel *tariff_name_label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLineEdit *messages_lineEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *daily_price_lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLineEdit *internet_lineEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *call_minutes_lineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *monthly_price_lineEdit;
    QLabel *incorrect_data_label;

    void setupUi(QWidget *TariffEditWidget)
    {
        if (TariffEditWidget->objectName().isEmpty())
            TariffEditWidget->setObjectName("TariffEditWidget");
        TariffEditWidget->resize(520, 360);
        TariffEditWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(155,160, 165);\n"
"font-family:Lato, Arial, Consolas;\n"
"color:black;\n"
"font-size:18px;"));
        calcel_btn = new QPushButton(TariffEditWidget);
        calcel_btn->setObjectName("calcel_btn");
        calcel_btn->setGeometry(QRect(260, 310, 100, 25));
        calcel_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:black;\n"
"background-color:white;\n"
"border:1px solid black;\n"
"border-radius:4px;\n"
"font-size:16px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(200, 200, 200);\n"
"}"));
        save_btn = new QPushButton(TariffEditWidget);
        save_btn->setObjectName("save_btn");
        save_btn->setGeometry(QRect(150, 310, 100, 25));
        save_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:black;\n"
"background-color:white;\n"
"border:1px solid black;\n"
"border-radius:4px;\n"
"font-size:16px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(200, 200, 200);\n"
"}"));
        tariff_name_label = new QLabel(TariffEditWidget);
        tariff_name_label->setObjectName("tariff_name_label");
        tariff_name_label->setGeometry(QRect(0, 0, 520, 40));
        tariff_name_label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-size:36px;"));
        tariff_name_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(TariffEditWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 60, 395, 185));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout_5->addWidget(label_4);

        messages_lineEdit = new QLineEdit(layoutWidget);
        messages_lineEdit->setObjectName("messages_lineEdit");
        messages_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_5->addWidget(messages_lineEdit);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        daily_price_lineEdit = new QLineEdit(layoutWidget);
        daily_price_lineEdit->setObjectName("daily_price_lineEdit");
        daily_price_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_4->addWidget(daily_price_lineEdit);


        gridLayout->addLayout(verticalLayout_4, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        internet_lineEdit = new QLineEdit(layoutWidget);
        internet_lineEdit->setObjectName("internet_lineEdit");
        internet_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_2->addWidget(internet_lineEdit);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        call_minutes_lineEdit = new QLineEdit(layoutWidget);
        call_minutes_lineEdit->setObjectName("call_minutes_lineEdit");
        call_minutes_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout->addWidget(call_minutes_lineEdit);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        monthly_price_lineEdit = new QLineEdit(layoutWidget);
        monthly_price_lineEdit->setObjectName("monthly_price_lineEdit");
        monthly_price_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_3->addWidget(monthly_price_lineEdit);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        incorrect_data_label = new QLabel(TariffEditWidget);
        incorrect_data_label->setObjectName("incorrect_data_label");
        incorrect_data_label->setGeometry(QRect(0, 260, 521, 31));
        incorrect_data_label->setStyleSheet(QString::fromUtf8("color:red;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:18px;\n"
"background-color:transparent;\n"
""));
        incorrect_data_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(TariffEditWidget);

        QMetaObject::connectSlotsByName(TariffEditWidget);
    } // setupUi

    void retranslateUi(QWidget *TariffEditWidget)
    {
        TariffEditWidget->setWindowTitle(QCoreApplication::translate("TariffEditWidget", "Form", nullptr));
        calcel_btn->setText(QCoreApplication::translate("TariffEditWidget", "Cancel", nullptr));
        save_btn->setText(QCoreApplication::translate("TariffEditWidget", "Save", nullptr));
        tariff_name_label->setText(QCoreApplication::translate("TariffEditWidget", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("TariffEditWidget", "Messages", nullptr));
        label_3->setText(QCoreApplication::translate("TariffEditWidget", "Daily price", nullptr));
        label_5->setText(QCoreApplication::translate("TariffEditWidget", "Internet(GB)", nullptr));
        label->setText(QCoreApplication::translate("TariffEditWidget", "Call minutes", nullptr));
        label_2->setText(QCoreApplication::translate("TariffEditWidget", "Monthly price", nullptr));
        incorrect_data_label->setText(QCoreApplication::translate("TariffEditWidget", "Incorrect data!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TariffEditWidget: public Ui_TariffEditWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARIFFEDITWIDGET_H
