/********************************************************************************
** Form generated from reading UI file 'customerspage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERSPAGE_H
#define UI_CUSTOMERSPAGE_H

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

class Ui_CustomersPage
{
public:
    QWidget *widget;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *add_cust_btn;
    QPushButton *close_open_filter_btn;
    QFrame *frame;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *filter_widget;
    QPushButton *apply_filter_btn;
    QLabel *filter_pic;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QComboBox *sort_by_comboBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QComboBox *tariffs_comboBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QComboBox *employees_comboBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QComboBox *number_comboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *active_btn;
    QPushButton *all_by_activity_btn;
    QPushButton *inactive_btn;

    void setupUi(QWidget *CustomersPage)
    {
        if (CustomersPage->objectName().isEmpty())
            CustomersPage->setObjectName("CustomersPage");
        CustomersPage->resize(1670, 1080);
        CustomersPage->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        CustomersPage->setStyleSheet(QString::fromUtf8("font-family:Lato;\n"
"background-color:white;"));
        widget = new QWidget(CustomersPage);
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
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 351, 70));
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
"font-family:Lato, Arial, Consolas;\n"
"border:none;\n"
"border-radius:4px;\n"
"font-size:16px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(220, 220, 220);\n"
"}"));
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
        frame = new QFrame(CustomersPage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 1030, 1670, 50));
        frame->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgba(42, 42, 42, 0.3);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        scrollArea = new QScrollArea(CustomersPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 80, 1670, 981));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1668, 979));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(-20, 0, 1691, 991));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        filter_widget = new QWidget(CustomersPage);
        filter_widget->setObjectName("filter_widget");
        filter_widget->setGeometry(QRect(1670, 0, 280, 1080));
        filter_widget->setStyleSheet(QString::fromUtf8("background-color:rgb(40, 40, 43);\n"
"color:white;\n"
"font-family:Lato, Arial, Consolas;\n"
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
        layoutWidget = new QWidget(filter_widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 270, 261, 381));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;\n"
"font-family:Lato, Arial, Consolas;"));

        verticalLayout->addWidget(label_2);

        sort_by_comboBox = new QComboBox(layoutWidget);
        sort_by_comboBox->addItem(QString());
        sort_by_comboBox->addItem(QString());
        sort_by_comboBox->addItem(QString());
        sort_by_comboBox->addItem(QString());
        sort_by_comboBox->setObjectName("sort_by_comboBox");
        sort_by_comboBox->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0.4);\n"
"background-color:rgba(255, 255, 255, 0.1);\n"
"color:white;\n"
"font-size:24px;\n"
"font-family:Lato, Arial, Consolas;"));

        verticalLayout->addWidget(sort_by_comboBox);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;\n"
"font-family:Lato, Arial, Consolas;"));

        verticalLayout_2->addWidget(label_3);

        tariffs_comboBox = new QComboBox(layoutWidget);
        tariffs_comboBox->addItem(QString());
        tariffs_comboBox->addItem(QString());
        tariffs_comboBox->addItem(QString());
        tariffs_comboBox->setObjectName("tariffs_comboBox");
        tariffs_comboBox->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0.4);\n"
"background-color:rgba(255, 255, 255, 0.1);\n"
"color:white;\n"
"font-size:24px;\n"
"font-family:Lato, Arial, Consolas;"));

        verticalLayout_2->addWidget(tariffs_comboBox);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;\n"
"font-family:Lato, Arial, Consolas;"));

        verticalLayout_3->addWidget(label_4);

        employees_comboBox = new QComboBox(layoutWidget);
        employees_comboBox->addItem(QString());
        employees_comboBox->addItem(QString());
        employees_comboBox->addItem(QString());
        employees_comboBox->setObjectName("employees_comboBox");
        employees_comboBox->setMaximumSize(QSize(16777215, 240));
        employees_comboBox->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0.4);\n"
"background-color:rgba(255, 255, 255, 0.1);\n"
"color:white;\n"
"font-size:24px;\n"
"font-family:Lato, Arial, Consolas;"));
        employees_comboBox->setMaxVisibleItems(5);

        verticalLayout_3->addWidget(employees_comboBox);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:18px;\n"
"font-family:Lato, Arial, Consolas;"));

        verticalLayout_4->addWidget(label_5);

        number_comboBox = new QComboBox(layoutWidget);
        number_comboBox->addItem(QString());
        number_comboBox->addItem(QString());
        number_comboBox->addItem(QString());
        number_comboBox->setObjectName("number_comboBox");
        number_comboBox->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0.4);\n"
"background-color:rgba(255, 255, 255, 0.1);\n"
"color:white;\n"
"font-size:24px;\n"
"font-family:Lato, Arial, Consolas;"));

        verticalLayout_4->addWidget(number_comboBox);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        active_btn = new QPushButton(layoutWidget);
        active_btn->setObjectName("active_btn");
        active_btn->setStyleSheet(QString::fromUtf8("border-top-left-radius:4px;\n"
"border-bottom-left-radius:4px;\n"
"background-color:transparent;\n"
"border:1px solid white;\n"
"color:white;\n"
"height:30px;\n"
"font-size:16px;"));

        horizontalLayout->addWidget(active_btn);

        all_by_activity_btn = new QPushButton(layoutWidget);
        all_by_activity_btn->setObjectName("all_by_activity_btn");
        all_by_activity_btn->setStyleSheet(QString::fromUtf8("border-radius:0px;\n"
"background-color:transparent;\n"
"border:1px solid white;\n"
"color:black;\n"
"height:30px;\n"
"color:white;\n"
"font-size:16px;"));

        horizontalLayout->addWidget(all_by_activity_btn);

        inactive_btn = new QPushButton(layoutWidget);
        inactive_btn->setObjectName("inactive_btn");
        inactive_btn->setStyleSheet(QString::fromUtf8("border-top-right-radius:4px;\n"
"border-bottom-right-radius:4px;\n"
"background-color:white;\n"
"border:1px solid white;\n"
"color:black;\n"
"height:30px;\n"
"font-size:16px;"));

        horizontalLayout->addWidget(inactive_btn);


        verticalLayout_5->addLayout(horizontalLayout);

        widget->raise();
        scrollArea->raise();
        frame->raise();
        filter_widget->raise();

        retranslateUi(CustomersPage);

        QMetaObject::connectSlotsByName(CustomersPage);
    } // setupUi

    void retranslateUi(QWidget *CustomersPage)
    {
        CustomersPage->setWindowTitle(QCoreApplication::translate("CustomersPage", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("CustomersPage", "Search Customers by name or phone", nullptr));
        label->setText(QCoreApplication::translate("CustomersPage", "Customers list page", nullptr));
        add_cust_btn->setText(QCoreApplication::translate("CustomersPage", "Add Customer", nullptr));
        close_open_filter_btn->setText(QString());
        apply_filter_btn->setText(QCoreApplication::translate("CustomersPage", "Apply filters", nullptr));
        filter_pic->setText(QString());
        label_2->setText(QCoreApplication::translate("CustomersPage", "Order by", nullptr));
        sort_by_comboBox->setItemText(0, QCoreApplication::translate("CustomersPage", "By date (newest)", nullptr));
        sort_by_comboBox->setItemText(1, QCoreApplication::translate("CustomersPage", "By name (a-z)", nullptr));
        sort_by_comboBox->setItemText(2, QCoreApplication::translate("CustomersPage", "By name (z-a)", nullptr));
        sort_by_comboBox->setItemText(3, QCoreApplication::translate("CustomersPage", "By date (oldest)", nullptr));

        label_3->setText(QCoreApplication::translate("CustomersPage", "Tariff", nullptr));
        tariffs_comboBox->setItemText(0, QCoreApplication::translate("CustomersPage", "All", nullptr));
        tariffs_comboBox->setItemText(1, QCoreApplication::translate("CustomersPage", "+38099", nullptr));
        tariffs_comboBox->setItemText(2, QCoreApplication::translate("CustomersPage", "+38066", nullptr));

        label_4->setText(QCoreApplication::translate("CustomersPage", "Added by", nullptr));
        employees_comboBox->setItemText(0, QCoreApplication::translate("CustomersPage", "All", nullptr));
        employees_comboBox->setItemText(1, QCoreApplication::translate("CustomersPage", "+38099", nullptr));
        employees_comboBox->setItemText(2, QCoreApplication::translate("CustomersPage", "+38066", nullptr));

        label_5->setText(QCoreApplication::translate("CustomersPage", "Numbers", nullptr));
        number_comboBox->setItemText(0, QCoreApplication::translate("CustomersPage", "All", nullptr));
        number_comboBox->setItemText(1, QCoreApplication::translate("CustomersPage", "+38099", nullptr));
        number_comboBox->setItemText(2, QCoreApplication::translate("CustomersPage", "+38066", nullptr));

        active_btn->setText(QCoreApplication::translate("CustomersPage", "Active", nullptr));
        all_by_activity_btn->setText(QCoreApplication::translate("CustomersPage", "All", nullptr));
        inactive_btn->setText(QCoreApplication::translate("CustomersPage", "Inactive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomersPage: public Ui_CustomersPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERSPAGE_H
