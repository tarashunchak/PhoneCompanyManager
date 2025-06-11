/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QWidget *last_reg_cust;
    QTableView *tableView;
    QLabel *label_2;
    QComboBox *customers_period_comboBox;
    QWidget *request_history_box;
    QLabel *label;
    QTableView *requests_statistic_tableView;
    QComboBox *requests_period_comboBox;
    QWidget *requests_statistic_box;
    QWidget *requests_statistic;
    QComboBox *req_date_comboBox;
    QLabel *label_5;
    QWidget *customers_statistic_box;
    QWidget *customers_statistic;
    QComboBox *cust_date_comboBox;
    QLabel *label_4;
    QWidget *tariffs_statistic_box;
    QWidget *tariff_statistics;
    QLabel *label_3;
    QComboBox *tariff_comboBox;
    QLabel *empty_req_stat;
    QLabel *empty_cust_stat;
    QLabel *empty_cust_model;

    void setupUi(QWidget *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(1680, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dashboard->sizePolicy().hasHeightForWidth());
        Dashboard->setSizePolicy(sizePolicy);
        Dashboard->setMaximumSize(QSize(16777215, 16777215));
        Dashboard->setStyleSheet(QString::fromUtf8("font-family:Lato, Arial, Consolas;\n"
"background-color:rgba(150, 150, 150, 1);"));
        last_reg_cust = new QWidget(Dashboard);
        last_reg_cust->setObjectName("last_reg_cust");
        last_reg_cust->setGeometry(QRect(40, 520, 1050, 520));
        last_reg_cust->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:#73819C;"));
        tableView = new QTableView(last_reg_cust);
        tableView->setObjectName("tableView");
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(20, 50, 1010, 450));
        tableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
"	font-family:Lato;\n"
"	font-size:16px;\n"
"	background-color: white;\n"
"	color:black;\n"
"	border:none;\n"
"	border-top-left-radius:10px;\n"
"	border-top-right-radius:10px;\n"
"}\n"
"\n"
""));
        label_2 = new QLabel(last_reg_cust);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 15, 141, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        font.setPointSize(14);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family: Lato, Arial, Consolas;\n"
"background-color:transparent;"));
        customers_period_comboBox = new QComboBox(last_reg_cust);
        customers_period_comboBox->addItem(QString());
        customers_period_comboBox->addItem(QString());
        customers_period_comboBox->addItem(QString());
        customers_period_comboBox->setObjectName("customers_period_comboBox");
        customers_period_comboBox->setGeometry(QRect(906, 10, 121, 27));
        customers_period_comboBox->setStyleSheet(QString::fromUtf8("padding-left:10px;\n"
"font-family:Robotic;\n"
"font-size:16px;\n"
"color:black;\n"
"background-color:white;\n"
"border-radius:4px;"));
        request_history_box = new QWidget(Dashboard);
        request_history_box->setObjectName("request_history_box");
        request_history_box->setGeometry(QRect(1120, 520, 511, 520));
        request_history_box->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:#73819C;"));
        label = new QLabel(request_history_box);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 15, 126, 25));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family: Lato, Arial, Consolas;\n"
"background-color:transparent;"));
        requests_statistic_tableView = new QTableView(request_history_box);
        requests_statistic_tableView->setObjectName("requests_statistic_tableView");
        requests_statistic_tableView->setGeometry(QRect(20, 50, 470, 450));
        requests_statistic_tableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
"	font-family:Lato;\n"
"	font-size:16px;\n"
"	background-color: white;\n"
"	color:black;\n"
"	border:none;\n"
"	border-top-left-radius:10px;\n"
"	border-top-right-radius:10px;\n"
"}\n"
"\n"
""));
        requests_period_comboBox = new QComboBox(request_history_box);
        requests_period_comboBox->addItem(QString());
        requests_period_comboBox->addItem(QString());
        requests_period_comboBox->addItem(QString());
        requests_period_comboBox->setObjectName("requests_period_comboBox");
        requests_period_comboBox->setGeometry(QRect(370, 10, 121, 27));
        requests_period_comboBox->setStyleSheet(QString::fromUtf8("padding-left:30px;\n"
"font-family:Robotic;\n"
"font-size:16px;\n"
"color:black;\n"
"background-color:white;\n"
"border-radius:4px;"));
        requests_statistic_box = new QWidget(Dashboard);
        requests_statistic_box->setObjectName("requests_statistic_box");
        requests_statistic_box->setGeometry(QRect(39, 30, 511, 461));
        requests_statistic_box->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color:#73819C;"));
        requests_statistic = new QWidget(requests_statistic_box);
        requests_statistic->setObjectName("requests_statistic");
        requests_statistic->setGeometry(QRect(0, 50, 511, 411));
        requests_statistic->setStyleSheet(QString::fromUtf8("font-family:Lato;\n"
"border-radius: 0px;\n"
"background-color:transparent;"));
        req_date_comboBox = new QComboBox(requests_statistic_box);
        req_date_comboBox->addItem(QString());
        req_date_comboBox->addItem(QString());
        req_date_comboBox->addItem(QString());
        req_date_comboBox->setObjectName("req_date_comboBox");
        req_date_comboBox->setGeometry(QRect(370, 10, 121, 26));
        req_date_comboBox->setStyleSheet(QString::fromUtf8("padding-left:30px;\n"
"font-family:Robotic;\n"
"font-size:16px;\n"
"color:black;\n"
"background-color:white;\n"
"border-radius:4px;"));
        label_5 = new QLabel(requests_statistic_box);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 10, 511, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lato")});
        font1.setPointSize(16);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family: Lato, Arial, Consolas;\n"
"background-color:transparent;"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5->raise();
        requests_statistic->raise();
        req_date_comboBox->raise();
        customers_statistic_box = new QWidget(Dashboard);
        customers_statistic_box->setObjectName("customers_statistic_box");
        customers_statistic_box->setGeometry(QRect(580, 30, 510, 461));
        customers_statistic_box->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color:#73819C;"));
        customers_statistic = new QWidget(customers_statistic_box);
        customers_statistic->setObjectName("customers_statistic");
        customers_statistic->setGeometry(QRect(0, 50, 510, 410));
        customers_statistic->setStyleSheet(QString::fromUtf8("font-family:Lato;\n"
"border-radius: 0px;\n"
"background-color:transparent;"));
        cust_date_comboBox = new QComboBox(customers_statistic_box);
        cust_date_comboBox->addItem(QString());
        cust_date_comboBox->addItem(QString());
        cust_date_comboBox->addItem(QString());
        cust_date_comboBox->setObjectName("cust_date_comboBox");
        cust_date_comboBox->setGeometry(QRect(370, 10, 121, 26));
        cust_date_comboBox->setStyleSheet(QString::fromUtf8("padding-left:30px;\n"
"font-family:Robotic;\n"
"font-size:16px;\n"
"color:black;\n"
"background-color:white;\n"
"border-radius:4px;"));
        label_4 = new QLabel(customers_statistic_box);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 10, 510, 30));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color:white;\n"
"padding-left:100px;\n"
"font-family: Lato, Arial, Consolas;\n"
"background-color:transparent;"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_4->raise();
        customers_statistic->raise();
        cust_date_comboBox->raise();
        tariffs_statistic_box = new QWidget(Dashboard);
        tariffs_statistic_box->setObjectName("tariffs_statistic_box");
        tariffs_statistic_box->setGeometry(QRect(1120, 30, 511, 461));
        tariffs_statistic_box->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color:#73819C;"));
        tariff_statistics = new QWidget(tariffs_statistic_box);
        tariff_statistics->setObjectName("tariff_statistics");
        tariff_statistics->setGeometry(QRect(0, 50, 511, 411));
        tariff_statistics->setStyleSheet(QString::fromUtf8("font-family:Lato, Consolas;\n"
"font-size:12px;\n"
"border-radius: 0px;\n"
"background-color:transparent;"));
        label_3 = new QLabel(tariffs_statistic_box);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 10, 510, 30));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-family: Lato, Arial, Consolas;\n"
"background-color:transparent;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tariff_comboBox = new QComboBox(tariffs_statistic_box);
        tariff_comboBox->addItem(QString());
        tariff_comboBox->addItem(QString());
        tariff_comboBox->addItem(QString());
        tariff_comboBox->setObjectName("tariff_comboBox");
        tariff_comboBox->setGeometry(QRect(370, 10, 121, 27));
        tariff_comboBox->setStyleSheet(QString::fromUtf8("padding-left:30px;\n"
"font-family:Robotic;\n"
"font-size:16px;\n"
"color:black;\n"
"background-color:white;\n"
"border-radius:4px;"));
        empty_req_stat = new QLabel(Dashboard);
        empty_req_stat->setObjectName("empty_req_stat");
        empty_req_stat->setGeometry(QRect(40, 80, 511, 391));
        empty_req_stat->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:50px;\n"
"background-color:transparent;"));
        empty_req_stat->setAlignment(Qt::AlignmentFlag::AlignCenter);
        empty_cust_stat = new QLabel(Dashboard);
        empty_cust_stat->setObjectName("empty_cust_stat");
        empty_cust_stat->setGeometry(QRect(580, 80, 511, 391));
        empty_cust_stat->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:50px;\n"
"background-color:transparent;"));
        empty_cust_stat->setAlignment(Qt::AlignmentFlag::AlignCenter);
        empty_cust_model = new QLabel(Dashboard);
        empty_cust_model->setObjectName("empty_cust_model");
        empty_cust_model->setGeometry(QRect(60, 570, 1010, 450));
        empty_cust_model->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-size:50px;\n"
"background-color:transparent;"));
        empty_cust_model->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QWidget *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Dashboard", "Last Customers", nullptr));
        customers_period_comboBox->setItemText(0, QCoreApplication::translate("Dashboard", "Last 10 days", nullptr));
        customers_period_comboBox->setItemText(1, QCoreApplication::translate("Dashboard", "Last 20 days", nullptr));
        customers_period_comboBox->setItemText(2, QCoreApplication::translate("Dashboard", "Last 30 days", nullptr));

        label->setText(QCoreApplication::translate("Dashboard", "Last Requests", nullptr));
        requests_period_comboBox->setItemText(0, QCoreApplication::translate("Dashboard", "Last 10", nullptr));
        requests_period_comboBox->setItemText(1, QCoreApplication::translate("Dashboard", "Last 20", nullptr));
        requests_period_comboBox->setItemText(2, QCoreApplication::translate("Dashboard", "Last 30", nullptr));

        req_date_comboBox->setItemText(0, QCoreApplication::translate("Dashboard", "Today", nullptr));
        req_date_comboBox->setItemText(1, QCoreApplication::translate("Dashboard", "3 days", nullptr));
        req_date_comboBox->setItemText(2, QCoreApplication::translate("Dashboard", "7 days", nullptr));

        label_5->setText(QCoreApplication::translate("Dashboard", "Request Activity", nullptr));
        cust_date_comboBox->setItemText(0, QCoreApplication::translate("Dashboard", "Today", nullptr));
        cust_date_comboBox->setItemText(1, QCoreApplication::translate("Dashboard", "3 days", nullptr));
        cust_date_comboBox->setItemText(2, QCoreApplication::translate("Dashboard", "7 days", nullptr));

        label_4->setText(QCoreApplication::translate("Dashboard", "New Customers Overview", nullptr));
        label_3->setText(QCoreApplication::translate("Dashboard", "Top Tariff By Usage", nullptr));
        tariff_comboBox->setItemText(0, QCoreApplication::translate("Dashboard", "Top 3", nullptr));
        tariff_comboBox->setItemText(1, QCoreApplication::translate("Dashboard", "Top 5", nullptr));
        tariff_comboBox->setItemText(2, QCoreApplication::translate("Dashboard", "Top 10", nullptr));

        empty_req_stat->setText(QCoreApplication::translate("Dashboard", "No Info", nullptr));
        empty_cust_stat->setText(QCoreApplication::translate("Dashboard", "No Info", nullptr));
        empty_cust_model->setText(QCoreApplication::translate("Dashboard", "No Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
