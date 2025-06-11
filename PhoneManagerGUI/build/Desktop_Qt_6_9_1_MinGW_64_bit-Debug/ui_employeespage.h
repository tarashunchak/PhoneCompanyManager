/********************************************************************************
** Form generated from reading UI file 'employeespage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEESPAGE_H
#define UI_EMPLOYEESPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeesPage
{
public:
    QFrame *frame;
    QWidget *widget_2;
    QWidget *widget;
    QLineEdit *lineEdit;
    QPushButton *add_empl_btn;
    QLabel *label;
    QPushButton *close_open_filter_btn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *filter_widget;
    QPushButton *apply_filter_btn;
    QLabel *filter_pic;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QComboBox *sort_by_comboBox;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QComboBox *tariffs_comboBox;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_8;
    QComboBox *employees_comboBox;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_9;
    QComboBox *number_comboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *active_btn;
    QPushButton *all_by_activity_btn;
    QPushButton *inactive_btn;

    void setupUi(QWidget *EmployeesPage)
    {
        if (EmployeesPage->objectName().isEmpty())
            EmployeesPage->setObjectName("EmployeesPage");
        EmployeesPage->resize(1670, 1080);
        EmployeesPage->setStyleSheet(QString::fromUtf8("font-family:Lato;\n"
"background-color:white;"));
        frame = new QFrame(EmployeesPage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 1030, 1670, 90));
        frame->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgba(42, 42, 42, 0.4);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        widget_2 = new QWidget(EmployeesPage);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 1670, 1080));
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1670, 80));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgba(200, 200, 200, 1);"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(1300, 23, 290, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:black;\n"
"text-align:left;\n"
"padding-left:4px;\n"
"padding-bottom:2px;\n"
"border:none;\n"
"border-radius:4px;\n"
"background-color:rgb(220, 220, 220);\n"
"font-family:Lato, Arial, Consolas;"));
        add_empl_btn = new QPushButton(widget);
        add_empl_btn->setObjectName("add_empl_btn");
        add_empl_btn->setGeometry(QRect(350, 23, 140, 34));
        add_empl_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        label->setGeometry(QRect(0, 0, 730, 70));
        label->setStyleSheet(QString::fromUtf8("font-family:Lato, Arial, Consolas;\n"
"font-size:32px;\n"
"padding-left:20px;\n"
"color:black;\n"
"background-color:transparent;"));
        close_open_filter_btn = new QPushButton(widget);
        close_open_filter_btn->setObjectName("close_open_filter_btn");
        close_open_filter_btn->setGeometry(QRect(1590, 23, 30, 30));
        close_open_filter_btn->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:black;\n"
"text-align:left;\n"
"padding-left:4px;\n"
"padding-bottom:2px;\n"
"border:none;\n"
"border-top-right-radius:4px;\n"
"border-bottom-right-radius:4px;\n"
"background-color:rgb(27, 104, 87);"));
        label->raise();
        lineEdit->raise();
        add_empl_btn->raise();
        close_open_filter_btn->raise();
        scrollArea = new QScrollArea(widget_2);
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
        filter_widget = new QWidget(EmployeesPage);
        filter_widget->setObjectName("filter_widget");
        filter_widget->setGeometry(QRect(1670, 0, 280, 1080));
        filter_widget->setStyleSheet(QString::fromUtf8("background-color:rgb(40, 40, 43);\n"
""));
        apply_filter_btn = new QPushButton(filter_widget);
        apply_filter_btn->setObjectName("apply_filter_btn");
        apply_filter_btn->setGeometry(QRect(55, 950, 160, 48));
        apply_filter_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgb(27, 104, 87);\n"
"border-radius:24px;\n"
"border:1px solid rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgb(7, 84, 67);\n"
"}"));
        filter_pic = new QLabel(filter_widget);
        filter_pic->setObjectName("filter_pic");
        filter_pic->setGeometry(QRect(40, 40, 200, 200));
        layoutWidget_2 = new QWidget(filter_widget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 270, 241, 381));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout_7->addWidget(label_6);

        sort_by_comboBox = new QComboBox(layoutWidget_2);
        sort_by_comboBox->addItem(QString());
        sort_by_comboBox->addItem(QString());
        sort_by_comboBox->addItem(QString());
        sort_by_comboBox->addItem(QString());
        sort_by_comboBox->setObjectName("sort_by_comboBox");
        sort_by_comboBox->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0.4);\n"
"background-color:rgba(255, 255, 255, 0.1);"));

        verticalLayout_7->addWidget(sort_by_comboBox);


        verticalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout_8->addWidget(label_7);

        tariffs_comboBox = new QComboBox(layoutWidget_2);
        tariffs_comboBox->addItem(QString());
        tariffs_comboBox->addItem(QString());
        tariffs_comboBox->addItem(QString());
        tariffs_comboBox->setObjectName("tariffs_comboBox");
        tariffs_comboBox->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0.4);\n"
"background-color:rgba(255, 255, 255, 0.1);"));

        verticalLayout_8->addWidget(tariffs_comboBox);


        verticalLayout_6->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout_9->addWidget(label_8);

        employees_comboBox = new QComboBox(layoutWidget_2);
        employees_comboBox->addItem(QString());
        employees_comboBox->addItem(QString());
        employees_comboBox->addItem(QString());
        employees_comboBox->setObjectName("employees_comboBox");
        employees_comboBox->setMaximumSize(QSize(16777215, 240));
        employees_comboBox->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0.4);\n"
"background-color:rgba(255, 255, 255, 0.1);"));
        employees_comboBox->setMaxVisibleItems(5);

        verticalLayout_9->addWidget(employees_comboBox);


        verticalLayout_6->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout_10->addWidget(label_9);

        number_comboBox = new QComboBox(layoutWidget_2);
        number_comboBox->addItem(QString());
        number_comboBox->addItem(QString());
        number_comboBox->addItem(QString());
        number_comboBox->setObjectName("number_comboBox");
        number_comboBox->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0.4);\n"
"background-color:rgba(255, 255, 255, 0.1);"));

        verticalLayout_10->addWidget(number_comboBox);


        verticalLayout_6->addLayout(verticalLayout_10);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        active_btn = new QPushButton(layoutWidget_2);
        active_btn->setObjectName("active_btn");
        active_btn->setStyleSheet(QString::fromUtf8("border-top-left-radius:4px;\n"
"border-bottom-left-radius:4px;\n"
"background-color:transparent;\n"
"border:1px solid white;\n"
"color:white;\n"
"height:30px;"));

        horizontalLayout_2->addWidget(active_btn);

        all_by_activity_btn = new QPushButton(layoutWidget_2);
        all_by_activity_btn->setObjectName("all_by_activity_btn");
        all_by_activity_btn->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"background-color:transparent;\n"
"border:1px solid white;\n"
"color:black;\n"
"height:30px;\n"
"color:white;"));

        horizontalLayout_2->addWidget(all_by_activity_btn);

        inactive_btn = new QPushButton(layoutWidget_2);
        inactive_btn->setObjectName("inactive_btn");
        inactive_btn->setStyleSheet(QString::fromUtf8("border-top-right-radius:4px;\n"
"border-bottom-right-radius:4px;\n"
"background-color:white;\n"
"border:1px solid white;\n"
"color:black;\n"
"height:30px;"));

        horizontalLayout_2->addWidget(inactive_btn);


        verticalLayout_6->addLayout(horizontalLayout_2);


        retranslateUi(EmployeesPage);

        QMetaObject::connectSlotsByName(EmployeesPage);
    } // setupUi

    void retranslateUi(QWidget *EmployeesPage)
    {
        EmployeesPage->setWindowTitle(QCoreApplication::translate("EmployeesPage", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("EmployeesPage", "Search Employee by name or id", nullptr));
        add_empl_btn->setText(QCoreApplication::translate("EmployeesPage", "Add Employee", nullptr));
        label->setText(QCoreApplication::translate("EmployeesPage", "Employees list page", nullptr));
        close_open_filter_btn->setText(QString());
        apply_filter_btn->setText(QCoreApplication::translate("EmployeesPage", "Apply filters", nullptr));
        filter_pic->setText(QString());
        label_6->setText(QCoreApplication::translate("EmployeesPage", "Order by", nullptr));
        sort_by_comboBox->setItemText(0, QCoreApplication::translate("EmployeesPage", "By date (newest)", nullptr));
        sort_by_comboBox->setItemText(1, QCoreApplication::translate("EmployeesPage", "By name (a-z)", nullptr));
        sort_by_comboBox->setItemText(2, QCoreApplication::translate("EmployeesPage", "By name (z-a)", nullptr));
        sort_by_comboBox->setItemText(3, QCoreApplication::translate("EmployeesPage", "By date (oldest)", nullptr));

        label_7->setText(QCoreApplication::translate("EmployeesPage", "Tariff", nullptr));
        tariffs_comboBox->setItemText(0, QCoreApplication::translate("EmployeesPage", "All", nullptr));
        tariffs_comboBox->setItemText(1, QCoreApplication::translate("EmployeesPage", "+38099", nullptr));
        tariffs_comboBox->setItemText(2, QCoreApplication::translate("EmployeesPage", "+38066", nullptr));

        label_8->setText(QCoreApplication::translate("EmployeesPage", "Added by", nullptr));
        employees_comboBox->setItemText(0, QCoreApplication::translate("EmployeesPage", "All", nullptr));
        employees_comboBox->setItemText(1, QCoreApplication::translate("EmployeesPage", "+38099", nullptr));
        employees_comboBox->setItemText(2, QCoreApplication::translate("EmployeesPage", "+38066", nullptr));

        label_9->setText(QCoreApplication::translate("EmployeesPage", "Numbers", nullptr));
        number_comboBox->setItemText(0, QCoreApplication::translate("EmployeesPage", "All", nullptr));
        number_comboBox->setItemText(1, QCoreApplication::translate("EmployeesPage", "+38099", nullptr));
        number_comboBox->setItemText(2, QCoreApplication::translate("EmployeesPage", "+38066", nullptr));

        active_btn->setText(QCoreApplication::translate("EmployeesPage", "Active", nullptr));
        all_by_activity_btn->setText(QCoreApplication::translate("EmployeesPage", "All", nullptr));
        inactive_btn->setText(QCoreApplication::translate("EmployeesPage", "Inactive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeesPage: public Ui_EmployeesPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEESPAGE_H
