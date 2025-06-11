/********************************************************************************
** Form generated from reading UI file 'insertcustomerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTCUSTOMERDIALOG_H
#define UI_INSERTCUSTOMERDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertCustomerDialog
{
public:
    QLabel *header_label;
    QPushButton *confirm_addition;
    QLabel *incorrect_data_label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *fname_label;
    QLineEdit *first_name_lineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *lname_label;
    QLineEdit *last_name_lineEdit;
    QVBoxLayout *verticalLayout_5;
    QLabel *tariff_label;
    QComboBox *tariff_comboBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *phone_label;
    QLineEdit *phone_lineEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *email_label_2;
    QDateEdit *bday_dateEdit;
    QVBoxLayout *verticalLayout;
    QLabel *email_label;
    QLineEdit *email_lineEdit;

    void setupUi(QDialog *InsertCustomerDialog)
    {
        if (InsertCustomerDialog->objectName().isEmpty())
            InsertCustomerDialog->setObjectName("InsertCustomerDialog");
        InsertCustomerDialog->resize(500, 340);
        InsertCustomerDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(155,160, 165);\n"
"font-family:Lato, Arial, Consolas;\n"
"color:black;\n"
"font-size:18px;"));
        InsertCustomerDialog->setModal(true);
        header_label = new QLabel(InsertCustomerDialog);
        header_label->setObjectName("header_label");
        header_label->setGeometry(QRect(130, 10, 240, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        header_label->setFont(font);
        header_label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-size:36px;"));
        header_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        confirm_addition = new QPushButton(InsertCustomerDialog);
        confirm_addition->setObjectName("confirm_addition");
        confirm_addition->setGeometry(QRect(200, 290, 100, 25));
        confirm_addition->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:black;\n"
"background-color:white;\n"
"border:1px solid black;\n"
"border-radius:4px;\n"
"font-size:16px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(200, 200, 200);\n"
"}"));
        incorrect_data_label = new QLabel(InsertCustomerDialog);
        incorrect_data_label->setObjectName("incorrect_data_label");
        incorrect_data_label->setGeometry(QRect(0, 260, 500, 25));
        incorrect_data_label->setStyleSheet(QString::fromUtf8("color:red;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:18px;\n"
"background-color:transparent;\n"
""));
        incorrect_data_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(InsertCustomerDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 65, 441, 191));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        fname_label = new QLabel(layoutWidget);
        fname_label->setObjectName("fname_label");
        fname_label->setFont(font);
        fname_label->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        verticalLayout_4->addWidget(fname_label);

        first_name_lineEdit = new QLineEdit(layoutWidget);
        first_name_lineEdit->setObjectName("first_name_lineEdit");
        first_name_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_4->addWidget(first_name_lineEdit);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lname_label = new QLabel(layoutWidget);
        lname_label->setObjectName("lname_label");
        lname_label->setFont(font);
        lname_label->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        verticalLayout_3->addWidget(lname_label);

        last_name_lineEdit = new QLineEdit(layoutWidget);
        last_name_lineEdit->setObjectName("last_name_lineEdit");
        last_name_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_3->addWidget(last_name_lineEdit);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        tariff_label = new QLabel(layoutWidget);
        tariff_label->setObjectName("tariff_label");
        tariff_label->setFont(font);
        tariff_label->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        verticalLayout_5->addWidget(tariff_label);

        tariff_comboBox = new QComboBox(layoutWidget);
        tariff_comboBox->setObjectName("tariff_comboBox");
        tariff_comboBox->setStyleSheet(QString::fromUtf8("background-color:#424242;\n"
"border:none;\n"
"font-size:20px;\n"
"color:white;\n"
"padding-left:6px;\n"
"border-radius:5px;"));

        verticalLayout_5->addWidget(tariff_comboBox);


        gridLayout->addLayout(verticalLayout_5, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        phone_label = new QLabel(layoutWidget);
        phone_label->setObjectName("phone_label");
        phone_label->setFont(font);
        phone_label->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        verticalLayout_2->addWidget(phone_label);

        phone_lineEdit = new QLineEdit(layoutWidget);
        phone_lineEdit->setObjectName("phone_lineEdit");
        phone_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_2->addWidget(phone_lineEdit);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        email_label_2 = new QLabel(layoutWidget);
        email_label_2->setObjectName("email_label_2");
        email_label_2->setFont(font);
        email_label_2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        verticalLayout_6->addWidget(email_label_2);

        bday_dateEdit = new QDateEdit(layoutWidget);
        bday_dateEdit->setObjectName("bday_dateEdit");
        bday_dateEdit->setStyleSheet(QString::fromUtf8("background-color:#424242;\n"
"border:none;\n"
"font-size:20px;\n"
"color:white;\n"
"border-radius:5px;"));
        bday_dateEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        bday_dateEdit->setCalendarPopup(true);
        bday_dateEdit->setTimeSpec(Qt::TimeSpec::UTC);
        bday_dateEdit->setDate(QDate(2000, 5, 27));

        verticalLayout_6->addWidget(bday_dateEdit);


        gridLayout->addLayout(verticalLayout_6, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        email_label = new QLabel(layoutWidget);
        email_label->setObjectName("email_label");
        email_label->setFont(font);
        email_label->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        verticalLayout->addWidget(email_label);

        email_lineEdit = new QLineEdit(layoutWidget);
        email_lineEdit->setObjectName("email_lineEdit");
        email_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout->addWidget(email_lineEdit);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);


        retranslateUi(InsertCustomerDialog);

        QMetaObject::connectSlotsByName(InsertCustomerDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertCustomerDialog)
    {
        InsertCustomerDialog->setWindowTitle(QCoreApplication::translate("InsertCustomerDialog", "Dialog", nullptr));
        header_label->setText(QCoreApplication::translate("InsertCustomerDialog", "Add Customer", nullptr));
        confirm_addition->setText(QCoreApplication::translate("InsertCustomerDialog", "Add to DB", nullptr));
        incorrect_data_label->setText(QCoreApplication::translate("InsertCustomerDialog", "Incorrect data!!!", nullptr));
        fname_label->setText(QCoreApplication::translate("InsertCustomerDialog", "First name", nullptr));
        lname_label->setText(QCoreApplication::translate("InsertCustomerDialog", "Last name", nullptr));
        tariff_label->setText(QCoreApplication::translate("InsertCustomerDialog", "Tariff", nullptr));
        phone_label->setText(QCoreApplication::translate("InsertCustomerDialog", "Phone", nullptr));
        email_label_2->setText(QCoreApplication::translate("InsertCustomerDialog", "Date of birth", nullptr));
        email_label->setText(QCoreApplication::translate("InsertCustomerDialog", "Email(optional)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertCustomerDialog: public Ui_InsertCustomerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTCUSTOMERDIALOG_H
