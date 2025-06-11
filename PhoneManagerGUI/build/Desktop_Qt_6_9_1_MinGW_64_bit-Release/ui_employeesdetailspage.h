/********************************************************************************
** Form generated from reading UI file 'employeesdetailspage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEESDETAILSPAGE_H
#define UI_EMPLOYEESDETAILSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeDetailsPage
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLabel *full_name_Label;
    QLabel *phone_Label;
    QLabel *email_Label;
    QLabel *cust_profile_pic;
    QPushButton *return_btn;
    QWidget *tariffs_history;
    QLabel *label_4;
    QPushButton *delete_employee_btn;
    QListWidget *listWidget;
    QLabel *hire_date_Label;
    QLabel *empl_id_Label;
    QPlainTextEdit *comment_textEdit;
    QLabel *label;
    QPushButton *save_comment_btn;
    QWidget *delete_employee_widget;
    QLabel *label_2;
    QPushButton *confirm_btn;
    QPushButton *cancel_btn;
    QLabel *department_Label;
    QWidget *request_history_box;
    QLabel *label_3;
    QTableView *requests_statistic_tableView2;
    QLabel *no_payments_label;
    QWidget *payment_history_box;
    QLabel *label_5;
    QTableView *requests_statistic_tableView;
    QLabel *no_requests_label;
    QLabel *position_Label;

    void setupUi(QWidget *EmployeeDetailsPage)
    {
        if (EmployeeDetailsPage->objectName().isEmpty())
            EmployeeDetailsPage->setObjectName("EmployeeDetailsPage");
        EmployeeDetailsPage->resize(1670, 1080);
        widget = new QWidget(EmployeeDetailsPage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1670, 1080));
        widget->setStyleSheet(QString::fromUtf8("background-color:white;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(40, 30, 1591, 1011));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0.2);"));
        full_name_Label = new QLabel(widget_2);
        full_name_Label->setObjectName("full_name_Label");
        full_name_Label->setGeometry(QRect(301, 269, 300, 22));
        full_name_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:20px;"));
        phone_Label = new QLabel(widget_2);
        phone_Label->setObjectName("phone_Label");
        phone_Label->setGeometry(QRect(301, 295, 300, 22));
        phone_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:20px;"));
        email_Label = new QLabel(widget_2);
        email_Label->setObjectName("email_Label");
        email_Label->setGeometry(QRect(301, 322, 300, 22));
        email_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:20px;"));
        cust_profile_pic = new QLabel(widget_2);
        cust_profile_pic->setObjectName("cust_profile_pic");
        cust_profile_pic->setGeometry(QRect(57, 50, 180, 180));
        cust_profile_pic->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;"));
        cust_profile_pic->setTextFormat(Qt::TextFormat::PlainText);
        return_btn = new QPushButton(widget_2);
        return_btn->setObjectName("return_btn");
        return_btn->setGeometry(QRect(1529, 20, 40, 40));
        return_btn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:4px;\n"
"background-color:transparent;"));
        return_btn->setIconSize(QSize(80, 80));
        tariffs_history = new QWidget(widget_2);
        tariffs_history->setObjectName("tariffs_history");
        tariffs_history->setGeometry(QRect(1020, 530, 450, 450));
        tariffs_history->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1020, 490, 450, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        font.setPointSize(20);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:transparent;\n"
"font-family: Lato;\n"
""));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        delete_employee_btn = new QPushButton(widget_2);
        delete_employee_btn->setObjectName("delete_employee_btn");
        delete_employee_btn->setGeometry(QRect(1480, 20, 40, 40));
        delete_employee_btn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:4px;"));
        delete_employee_btn->setIconSize(QSize(80, 80));
        listWidget = new QListWidget(widget_2);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setEnabled(false);
        listWidget->setGeometry(QRect(50, 240, 245, 201));
        listWidget->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Consolas;\n"
"font-size:22px;\n"
"border:none;\n"
"padding-left:0px;"));
        hire_date_Label = new QLabel(widget_2);
        hire_date_Label->setObjectName("hire_date_Label");
        hire_date_Label->setGeometry(QRect(301, 348, 300, 22));
        hire_date_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:20px;"));
        empl_id_Label = new QLabel(widget_2);
        empl_id_Label->setObjectName("empl_id_Label");
        empl_id_Label->setGeometry(QRect(301, 242, 300, 22));
        empl_id_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:20px;"));
        comment_textEdit = new QPlainTextEdit(widget_2);
        comment_textEdit->setObjectName("comment_textEdit");
        comment_textEdit->setGeometry(QRect(650, 65, 330, 375));
        comment_textEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border:1px solid rgba(0,0,0,0.4);\n"
"\n"
"color:black;\n"
"font-family:Lato, Consolas;\n"
"font-size:20px;\n"
"padding-top:10px;"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(651, 30, 328, 35));
        label->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:24px;\n"
"font-family:Lato, Consolas;\n"
"background-color:rgba(0, 0, 0, 0.2);\n"
"border:1px solid rgba(0, 0, 0, 0.4);\n"
"border-top-right-radius:6px;\n"
"border-top-left-radius:6px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        save_comment_btn = new QPushButton(widget_2);
        save_comment_btn->setObjectName("save_comment_btn");
        save_comment_btn->setGeometry(QRect(651, 440, 329, 40));
        save_comment_btn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-color:rgb(27, 104, 87);\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:20px;\n"
"border-bottom-left-radius:6px;\n"
"border-bottom-right-radius:6px;\n"
"}QPushButton:hover{\n"
"background-color:rgb(7, 84, 67);\n"
"}"));
        delete_employee_widget = new QWidget(widget_2);
        delete_employee_widget->setObjectName("delete_employee_widget");
        delete_employee_widget->setGeometry(QRect(560, 450, 300, 180));
        delete_employee_widget->setStyleSheet(QString::fromUtf8("background-color:rgb(155,160, 165);\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"border:1px solid black;\n"
"border-radius:5px;"));
        label_2 = new QLabel(delete_employee_widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1, 1, 298, 139));
        label_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-size:36px;\n"
"border-radius:4px;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        confirm_btn = new QPushButton(delete_employee_widget);
        confirm_btn->setObjectName("confirm_btn");
        confirm_btn->setGeometry(QRect(41, 143, 111, 29));
        confirm_btn->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font-size:16px;\n"
"border:1px solid black;\n"
"padding-top:5px;\n"
"padding-bottom:5px;\n"
"border-radius:4px;"));
        cancel_btn = new QPushButton(delete_employee_widget);
        cancel_btn->setObjectName("cancel_btn");
        cancel_btn->setGeometry(QRect(159, 143, 101, 29));
        cancel_btn->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font-size:16px;\n"
"border:1px solid black;\n"
"padding-top:5px;\n"
"padding-bottom:5px;\n"
"border-radius:4px;"));
        confirm_btn->raise();
        cancel_btn->raise();
        label_2->raise();
        department_Label = new QLabel(widget_2);
        department_Label->setObjectName("department_Label");
        department_Label->setGeometry(QRect(301, 375, 300, 22));
        department_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:20px;"));
        request_history_box = new QWidget(widget_2);
        request_history_box->setObjectName("request_history_box");
        request_history_box->setGeometry(QRect(1020, 30, 450, 450));
        request_history_box->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:#73819C;"));
        label_3 = new QLabel(request_history_box);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 15, 411, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lato")});
        font1.setPointSize(14);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family: Lato, Arial, Consolas;\n"
"background-color:transparent;"));
        requests_statistic_tableView2 = new QTableView(request_history_box);
        requests_statistic_tableView2->setObjectName("requests_statistic_tableView2");
        requests_statistic_tableView2->setGeometry(QRect(10, 50, 431, 391));
        requests_statistic_tableView2->setStyleSheet(QString::fromUtf8("QTableView{\n"
"	font-family:Lato, Arial, Consolas;\n"
"	font-size:16px;\n"
"	background-color: white;\n"
"	color:black;\n"
"	border:none;\n"
"}\n"
"\n"
""));
        requests_statistic_tableView2->verticalHeader()->setVisible(false);
        no_payments_label = new QLabel(request_history_box);
        no_payments_label->setObjectName("no_payments_label");
        no_payments_label->setGeometry(QRect(10, 50, 430, 390));
        no_payments_label->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:50px;"));
        no_payments_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        payment_history_box = new QWidget(widget_2);
        payment_history_box->setObjectName("payment_history_box");
        payment_history_box->setGeometry(QRect(40, 530, 941, 450));
        payment_history_box->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:#73819C;"));
        label_5 = new QLabel(payment_history_box);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 15, 241, 25));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family: Lato, Arial, Consolas;\n"
"background-color:transparent;"));
        requests_statistic_tableView = new QTableView(payment_history_box);
        requests_statistic_tableView->setObjectName("requests_statistic_tableView");
        requests_statistic_tableView->setGeometry(QRect(10, 50, 921, 391));
        requests_statistic_tableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
"	font-family:Lato, Arial, Consolas;\n"
"	font-size:16px;\n"
"	background-color: white;\n"
"	color:black;\n"
"	border:none;\n"
"}\n"
"\n"
""));
        requests_statistic_tableView->verticalHeader()->setVisible(false);
        no_requests_label = new QLabel(payment_history_box);
        no_requests_label->setObjectName("no_requests_label");
        no_requests_label->setGeometry(QRect(10, 50, 921, 390));
        no_requests_label->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:50px;"));
        no_requests_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        position_Label = new QLabel(widget_2);
        position_Label->setObjectName("position_Label");
        position_Label->setGeometry(QRect(301, 400, 300, 22));
        position_Label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:black;\n"
"font-family:Lato, Arial, Consolas;\n"
"font-size:20px;"));
        payment_history_box->raise();
        full_name_Label->raise();
        phone_Label->raise();
        email_Label->raise();
        cust_profile_pic->raise();
        return_btn->raise();
        tariffs_history->raise();
        label_4->raise();
        delete_employee_btn->raise();
        listWidget->raise();
        hire_date_Label->raise();
        empl_id_Label->raise();
        comment_textEdit->raise();
        label->raise();
        save_comment_btn->raise();
        delete_employee_widget->raise();
        department_Label->raise();
        request_history_box->raise();
        position_Label->raise();

        retranslateUi(EmployeeDetailsPage);

        QMetaObject::connectSlotsByName(EmployeeDetailsPage);
    } // setupUi

    void retranslateUi(QWidget *EmployeeDetailsPage)
    {
        EmployeeDetailsPage->setWindowTitle(QCoreApplication::translate("EmployeeDetailsPage", "Form", nullptr));
        full_name_Label->setText(QCoreApplication::translate("EmployeeDetailsPage", "TextLabel", nullptr));
        phone_Label->setText(QCoreApplication::translate("EmployeeDetailsPage", "TextLabel", nullptr));
        email_Label->setText(QCoreApplication::translate("EmployeeDetailsPage", "TextLabel", nullptr));
        cust_profile_pic->setText(QString());
        return_btn->setText(QString());
        label_4->setText(QCoreApplication::translate("EmployeeDetailsPage", "Tariffs History For Last Year", nullptr));
        delete_employee_btn->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("EmployeeDetailsPage", "ID               :", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("EmployeeDetailsPage", "Full name        :", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("EmployeeDetailsPage", "Phone            :", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("EmployeeDetailsPage", "Email            :", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("EmployeeDetailsPage", "Hire date        :", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("EmployeeDetailsPage", "Department       :", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("EmployeeDetailsPage", "Position         :", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        hire_date_Label->setText(QCoreApplication::translate("EmployeeDetailsPage", "TextLabel", nullptr));
        empl_id_Label->setText(QCoreApplication::translate("EmployeeDetailsPage", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("EmployeeDetailsPage", "Comment", nullptr));
        save_comment_btn->setText(QCoreApplication::translate("EmployeeDetailsPage", "Save comment", nullptr));
        label_2->setText(QCoreApplication::translate("EmployeeDetailsPage", "Are you sure?", nullptr));
        confirm_btn->setText(QCoreApplication::translate("EmployeeDetailsPage", "Confirm", nullptr));
        cancel_btn->setText(QCoreApplication::translate("EmployeeDetailsPage", "Cancel", nullptr));
        department_Label->setText(QCoreApplication::translate("EmployeeDetailsPage", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("EmployeeDetailsPage", "Handled requests history", nullptr));
        no_payments_label->setText(QCoreApplication::translate("EmployeeDetailsPage", "No Info", nullptr));
        label_5->setText(QCoreApplication::translate("EmployeeDetailsPage", "Handled requests history", nullptr));
        no_requests_label->setText(QCoreApplication::translate("EmployeeDetailsPage", "No Info", nullptr));
        position_Label->setText(QCoreApplication::translate("EmployeeDetailsPage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeDetailsPage: public Ui_EmployeeDetailsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEESDETAILSPAGE_H
