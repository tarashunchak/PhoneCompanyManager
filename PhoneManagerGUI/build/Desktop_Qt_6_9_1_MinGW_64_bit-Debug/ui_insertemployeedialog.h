/********************************************************************************
** Form generated from reading UI file 'insertemployeedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTEMPLOYEEDIALOG_H
#define UI_INSERTEMPLOYEEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertEmployeeDialog
{
public:
    QLabel *header_label;
    QPushButton *confirm_addition;
    QLabel *incorrect_data_label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *fname_label;
    QLineEdit *first_name_lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *lname_label;
    QLineEdit *last_name_lineEdit;
    QVBoxLayout *verticalLayout_5;
    QLabel *department_label;
    QComboBox *department_comboBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *phone_label;
    QLineEdit *phone_lineEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *position_label;
    QComboBox *position_comboBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *email_label;
    QLineEdit *email_lineEdit;
    QVBoxLayout *verticalLayout_7;
    QLabel *hire_date_label;
    QDateEdit *hire_date_dateEdit;
    QVBoxLayout *verticalLayout_8;
    QLabel *B_date_label;
    QDateEdit *B_date_dateEdit;

    void setupUi(QWidget *InsertEmployeeDialog)
    {
        if (InsertEmployeeDialog->objectName().isEmpty())
            InsertEmployeeDialog->setObjectName("InsertEmployeeDialog");
        InsertEmployeeDialog->resize(500, 422);
        InsertEmployeeDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(155,160, 165);\n"
"font-family:Lato, Arial, Consolas;\n"
"color:black;\n"
"font-size:18px;"));
        header_label = new QLabel(InsertEmployeeDialog);
        header_label->setObjectName("header_label");
        header_label->setGeometry(QRect(130, 10, 240, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        header_label->setFont(font);
        header_label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font-size:36px;"));
        confirm_addition = new QPushButton(InsertEmployeeDialog);
        confirm_addition->setObjectName("confirm_addition");
        confirm_addition->setGeometry(QRect(200, 375, 100, 25));
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
        incorrect_data_label = new QLabel(InsertEmployeeDialog);
        incorrect_data_label->setObjectName("incorrect_data_label");
        incorrect_data_label->setGeometry(QRect(0, 340, 500, 25));
        incorrect_data_label->setStyleSheet(QString::fromUtf8("color:red;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:18px;\n"
"background-color:transparent;\n"
""));
        incorrect_data_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(InsertEmployeeDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 66, 441, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        fname_label = new QLabel(layoutWidget);
        fname_label->setObjectName("fname_label");
        fname_label->setFont(font);

        verticalLayout->addWidget(fname_label);

        first_name_lineEdit = new QLineEdit(layoutWidget);
        first_name_lineEdit->setObjectName("first_name_lineEdit");
        first_name_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout->addWidget(first_name_lineEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lname_label = new QLabel(layoutWidget);
        lname_label->setObjectName("lname_label");
        lname_label->setMinimumSize(QSize(215, 0));
        lname_label->setFont(font);

        verticalLayout_2->addWidget(lname_label);

        last_name_lineEdit = new QLineEdit(layoutWidget);
        last_name_lineEdit->setObjectName("last_name_lineEdit");
        last_name_lineEdit->setMinimumSize(QSize(215, 0));
        last_name_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_2->addWidget(last_name_lineEdit);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        department_label = new QLabel(layoutWidget);
        department_label->setObjectName("department_label");
        department_label->setFont(font);

        verticalLayout_5->addWidget(department_label);

        department_comboBox = new QComboBox(layoutWidget);
        department_comboBox->setObjectName("department_comboBox");
        department_comboBox->setStyleSheet(QString::fromUtf8("background-color:#424242;\n"
"border:none;\n"
"font-size:20px;\n"
"color:white;\n"
"padding-left:6px;\n"
"border-radius:5px;"));

        verticalLayout_5->addWidget(department_comboBox);


        gridLayout->addLayout(verticalLayout_5, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        phone_label = new QLabel(layoutWidget);
        phone_label->setObjectName("phone_label");
        phone_label->setMinimumSize(QSize(215, 0));
        phone_label->setFont(font);

        verticalLayout_3->addWidget(phone_label);

        phone_lineEdit = new QLineEdit(layoutWidget);
        phone_lineEdit->setObjectName("phone_lineEdit");
        phone_lineEdit->setMinimumSize(QSize(215, 0));
        phone_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_3->addWidget(phone_lineEdit);


        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        position_label = new QLabel(layoutWidget);
        position_label->setObjectName("position_label");
        position_label->setFont(font);

        verticalLayout_6->addWidget(position_label);

        position_comboBox = new QComboBox(layoutWidget);
        position_comboBox->setObjectName("position_comboBox");
        position_comboBox->setStyleSheet(QString::fromUtf8("background-color:#424242;\n"
"border:none;\n"
"font-size:20px;\n"
"color:white;\n"
"padding-left:6px;\n"
"border-radius:5px;"));

        verticalLayout_6->addWidget(position_comboBox);


        gridLayout->addLayout(verticalLayout_6, 2, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        email_label = new QLabel(layoutWidget);
        email_label->setObjectName("email_label");
        email_label->setMinimumSize(QSize(215, 0));
        email_label->setFont(font);

        verticalLayout_4->addWidget(email_label);

        email_lineEdit = new QLineEdit(layoutWidget);
        email_lineEdit->setObjectName("email_lineEdit");
        email_lineEdit->setMinimumSize(QSize(215, 0));
        email_lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:18px;\n"
"border-radius:4px;\n"
"border:1px solid black;\n"
"padding-left:4px;"));

        verticalLayout_4->addWidget(email_lineEdit);


        gridLayout->addLayout(verticalLayout_4, 2, 1, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        hire_date_label = new QLabel(layoutWidget);
        hire_date_label->setObjectName("hire_date_label");
        hire_date_label->setFont(font);

        verticalLayout_7->addWidget(hire_date_label);

        hire_date_dateEdit = new QDateEdit(layoutWidget);
        hire_date_dateEdit->setObjectName("hire_date_dateEdit");
        hire_date_dateEdit->setStyleSheet(QString::fromUtf8("background-color:#424242;\n"
"border:none;\n"
"font-size:20px;\n"
"color:white;\n"
"padding-left:6px;\n"
"border-radius:5px;"));
        hire_date_dateEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        hire_date_dateEdit->setCalendarPopup(true);

        verticalLayout_7->addWidget(hire_date_dateEdit);


        gridLayout->addLayout(verticalLayout_7, 3, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        B_date_label = new QLabel(layoutWidget);
        B_date_label->setObjectName("B_date_label");
        B_date_label->setFont(font);

        verticalLayout_8->addWidget(B_date_label);

        B_date_dateEdit = new QDateEdit(layoutWidget);
        B_date_dateEdit->setObjectName("B_date_dateEdit");
        B_date_dateEdit->setStyleSheet(QString::fromUtf8("background-color:#424242;\n"
"border:none;\n"
"font-size:20px;\n"
"color:white;\n"
"padding-left:6px;\n"
"border-radius:5px;"));
        B_date_dateEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        B_date_dateEdit->setCalendarPopup(true);

        verticalLayout_8->addWidget(B_date_dateEdit);


        gridLayout->addLayout(verticalLayout_8, 3, 1, 1, 1);


        retranslateUi(InsertEmployeeDialog);

        QMetaObject::connectSlotsByName(InsertEmployeeDialog);
    } // setupUi

    void retranslateUi(QWidget *InsertEmployeeDialog)
    {
        InsertEmployeeDialog->setWindowTitle(QCoreApplication::translate("InsertEmployeeDialog", "Form", nullptr));
        header_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Add Employee", nullptr));
        confirm_addition->setText(QCoreApplication::translate("InsertEmployeeDialog", "Add to DB", nullptr));
        incorrect_data_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Incorrect data!!!", nullptr));
        fname_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "First name", nullptr));
        lname_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Last name", nullptr));
        department_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Department", nullptr));
        phone_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Phone", nullptr));
        position_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Position", nullptr));
        email_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Email", nullptr));
        hire_date_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Hire date", nullptr));
        B_date_label->setText(QCoreApplication::translate("InsertEmployeeDialog", "Date of birth", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertEmployeeDialog: public Ui_InsertEmployeeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTEMPLOYEEDIALOG_H
