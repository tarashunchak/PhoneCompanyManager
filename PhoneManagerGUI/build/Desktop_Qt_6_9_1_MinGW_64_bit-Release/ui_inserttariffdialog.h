/********************************************************************************
** Form generated from reading UI file 'inserttariffdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTTARIFFDIALOG_H
#define UI_INSERTTARIFFDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertTariffDialog
{
public:
    QPushButton *confirm_addition_btn;
    QLabel *header_label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QLineEdit *tariff_name_lineEdit;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *daily_p_lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLineEdit *internet_GB_lineEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *call_minutes_lineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLineEdit *monthly_p_lineEdit;

    void setupUi(QDialog *InsertTariffDialog)
    {
        if (InsertTariffDialog->objectName().isEmpty())
            InsertTariffDialog->setObjectName("InsertTariffDialog");
        InsertTariffDialog->resize(440, 320);
        InsertTariffDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(155,160, 165);\n"
"font-family:Lato, Arial, Consolas;\n"
"color:black;\n"
"font-size:18px;"));
        InsertTariffDialog->setModal(true);
        confirm_addition_btn = new QPushButton(InsertTariffDialog);
        confirm_addition_btn->setObjectName("confirm_addition_btn");
        confirm_addition_btn->setGeometry(QRect(170, 270, 100, 25));
        confirm_addition_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:black;\n"
"background-color:white;\n"
"border:1px solid black;\n"
"border-radius:4px;\n"
"font-size:16px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(200, 200, 200);\n"
"}"));
        header_label = new QLabel(InsertTariffDialog);
        header_label->setObjectName("header_label");
        header_label->setGeometry(QRect(140, 10, 160, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        header_label->setFont(font);
        header_label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-size:36px;"));
        header_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(InsertTariffDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 50, 381, 208));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));

        verticalLayout_5->addWidget(label_2);

        tariff_name_lineEdit = new QLineEdit(layoutWidget);
        tariff_name_lineEdit->setObjectName("tariff_name_lineEdit");
        tariff_name_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_5->addWidget(tariff_name_lineEdit);


        verticalLayout_6->addLayout(verticalLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font-size:18px;"));

        verticalLayout->addWidget(label_3);

        daily_p_lineEdit = new QLineEdit(layoutWidget);
        daily_p_lineEdit->setObjectName("daily_p_lineEdit");
        daily_p_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout->addWidget(daily_p_lineEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font-size:18px;"));

        verticalLayout_2->addWidget(label_5);

        internet_GB_lineEdit = new QLineEdit(layoutWidget);
        internet_GB_lineEdit->setObjectName("internet_GB_lineEdit");
        internet_GB_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_2->addWidget(internet_GB_lineEdit);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("font-size:18px;"));

        verticalLayout_4->addWidget(label_4);

        call_minutes_lineEdit = new QLineEdit(layoutWidget);
        call_minutes_lineEdit->setObjectName("call_minutes_lineEdit");
        call_minutes_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_4->addWidget(call_minutes_lineEdit);


        gridLayout->addLayout(verticalLayout_4, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("font-size:18px;"));

        verticalLayout_3->addWidget(label_6);

        monthly_p_lineEdit = new QLineEdit(layoutWidget);
        monthly_p_lineEdit->setObjectName("monthly_p_lineEdit");
        monthly_p_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_3->addWidget(monthly_p_lineEdit);


        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout);

        layoutWidget->raise();
        confirm_addition_btn->raise();
        header_label->raise();

        retranslateUi(InsertTariffDialog);

        QMetaObject::connectSlotsByName(InsertTariffDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertTariffDialog)
    {
        InsertTariffDialog->setWindowTitle(QCoreApplication::translate("InsertTariffDialog", "Dialog", nullptr));
        confirm_addition_btn->setText(QCoreApplication::translate("InsertTariffDialog", "Add to DB", nullptr));
        header_label->setText(QCoreApplication::translate("InsertTariffDialog", "Add Tariff", nullptr));
        label_2->setText(QCoreApplication::translate("InsertTariffDialog", "Tariff name", nullptr));
        tariff_name_lineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("InsertTariffDialog", "Monthly price", nullptr));
        label_5->setText(QCoreApplication::translate("InsertTariffDialog", "Calls minutes", nullptr));
        label_4->setText(QCoreApplication::translate("InsertTariffDialog", "Daily price", nullptr));
        label_6->setText(QCoreApplication::translate("InsertTariffDialog", "Internet(GB)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertTariffDialog: public Ui_InsertTariffDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTTARIFFDIALOG_H
