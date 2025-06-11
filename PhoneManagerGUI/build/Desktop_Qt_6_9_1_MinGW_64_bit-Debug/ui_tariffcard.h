/********************************************************************************
** Form generated from reading UI file 'tariffcard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARIFFCARD_H
#define UI_TARIFFCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TariffCard
{
public:
    QPushButton *monthly_btn;
    QPushButton *daily_btn;
    QLabel *tariff_name;
    QLabel *daily_price;
    QLabel *calls;
    QLabel *internet;
    QFrame *line;
    QLabel *money_pic;
    QLabel *calls_per_day;
    QLabel *internet_per_day;
    QLabel *id_label;
    QLabel *internet_2;
    QLabel *SMS;
    QWidget *widget;
    QLabel *SMS_label;
    QLabel *price_label;
    QLabel *internet_label;
    QLabel *calls_label;
    QPushButton *edit_btn;
    QPushButton *active_inactive_swithc_btn;
    QLabel *active_indicator;

    void setupUi(QWidget *TariffCard)
    {
        if (TariffCard->objectName().isEmpty())
            TariffCard->setObjectName("TariffCard");
        TariffCard->setEnabled(true);
        TariffCard->resize(300, 460);
        TariffCard->setAutoFillBackground(false);
        TariffCard->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"font-family:Lato, Arial, Consolas;\n"
"background-color:rgb(51, 51, 51);"));
        monthly_btn = new QPushButton(TariffCard);
        monthly_btn->setObjectName("monthly_btn");
        monthly_btn->setGeometry(QRect(16, 60, 135, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lato")});
        font.setPointSize(12);
        monthly_btn->setFont(font);
        monthly_btn->setAutoFillBackground(false);
        monthly_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-top-right-radius:0px;\n"
"border-bottom-right-radius:0px;\n"
"background-color:white;\n"
"border:1px solid rgb(255, 255, 255);\n"
"color:black;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(200, 200, 200);\n"
"}"));
        daily_btn = new QPushButton(TariffCard);
        daily_btn->setObjectName("daily_btn");
        daily_btn->setGeometry(QRect(151, 60, 131, 51));
        daily_btn->setFont(font);
        daily_btn->setAutoFillBackground(false);
        daily_btn->setStyleSheet(QString::fromUtf8("border-top-left-radius:0px;\n"
"border-bottom-left-radius:0px;\n"
"border:1px solid rgb(255, 255, 255);\n"
"color:white;"));
        tariff_name = new QLabel(TariffCard);
        tariff_name->setObjectName("tariff_name");
        tariff_name->setGeometry(QRect(20, 20, 251, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lato")});
        tariff_name->setFont(font1);
        tariff_name->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:16px;"));
        daily_price = new QLabel(TariffCard);
        daily_price->setObjectName("daily_price");
        daily_price->setGeometry(QRect(60, 155, 121, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Lato")});
        font2.setPointSize(11);
        daily_price->setFont(font2);
        daily_price->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:transparent;"));
        calls = new QLabel(TariffCard);
        calls->setObjectName("calls");
        calls->setGeometry(QRect(60, 200, 121, 50));
        calls->setFont(font2);
        calls->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:transparent;"));
        calls->setWordWrap(false);
        internet = new QLabel(TariffCard);
        internet->setObjectName("internet");
        internet->setGeometry(QRect(60, 260, 61, 50));
        internet->setFont(font2);
        internet->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:transparent;"));
        line = new QFrame(TariffCard);
        line->setObjectName("line");
        line->setGeometry(QRect(16, 120, 264, 1));
        line->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border:none;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        money_pic = new QLabel(TariffCard);
        money_pic->setObjectName("money_pic");
        money_pic->setGeometry(QRect(20, 150, 30, 30));
        money_pic->setStyleSheet(QString::fromUtf8("background-color:white;"));
        money_pic->setScaledContents(true);
        calls_per_day = new QLabel(TariffCard);
        calls_per_day->setObjectName("calls_per_day");
        calls_per_day->setGeometry(QRect(20, 210, 30, 30));
        calls_per_day->setStyleSheet(QString::fromUtf8("background-color:white;"));
        calls_per_day->setScaledContents(true);
        internet_per_day = new QLabel(TariffCard);
        internet_per_day->setObjectName("internet_per_day");
        internet_per_day->setGeometry(QRect(20, 270, 30, 30));
        internet_per_day->setStyleSheet(QString::fromUtf8("background-color:white;"));
        internet_per_day->setScaledContents(true);
        id_label = new QLabel(TariffCard);
        id_label->setObjectName("id_label");
        id_label->setGeometry(QRect(210, 20, 71, 31));
        id_label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color:white;\n"
"font-family:Lato, Consolas;\n"
"font-size:16px;"));
        internet_2 = new QLabel(TariffCard);
        internet_2->setObjectName("internet_2");
        internet_2->setGeometry(QRect(60, 320, 61, 50));
        internet_2->setFont(font2);
        internet_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:transparent;"));
        SMS = new QLabel(TariffCard);
        SMS->setObjectName("SMS");
        SMS->setGeometry(QRect(20, 330, 30, 30));
        SMS->setStyleSheet(QString::fromUtf8("background-color:white;"));
        SMS->setScaledContents(true);
        widget = new QWidget(TariffCard);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(180, 160, 111, 211));
        widget->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:Lato, Arial, Consolas;\n"
"background-color:transparent;"));
        SMS_label = new QLabel(widget);
        SMS_label->setObjectName("SMS_label");
        SMS_label->setGeometry(QRect(40, 180, 70, 20));
        SMS_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:transparent;"));
        price_label = new QLabel(widget);
        price_label->setObjectName("price_label");
        price_label->setGeometry(QRect(40, 0, 70, 20));
        price_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:transparent;"));
        internet_label = new QLabel(widget);
        internet_label->setObjectName("internet_label");
        internet_label->setGeometry(QRect(40, 120, 70, 20));
        internet_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:transparent;"));
        calls_label = new QLabel(widget);
        calls_label->setObjectName("calls_label");
        calls_label->setGeometry(QRect(40, 60, 70, 20));
        calls_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:transparent;"));
        edit_btn = new QPushButton(TariffCard);
        edit_btn->setObjectName("edit_btn");
        edit_btn->setGeometry(QRect(85, 400, 130, 30));
        edit_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:white;\n"
"color:black;\n"
"font-size:20px;\n"
"font-family:Lato, Arial, Consolas;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(200, 200, 200);\n"
"}"));
        active_inactive_swithc_btn = new QPushButton(TariffCard);
        active_inactive_swithc_btn->setObjectName("active_inactive_swithc_btn");
        active_inactive_swithc_btn->setGeometry(QRect(240, 405, 51, 23));
        active_inactive_swithc_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgba(200, 200, 200, 0.2);\n"
"	border-radius:4px;\n"
"	color:white;\n"
"	font-size:14px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgba(200, 200, 200, 0.3);\n"
"}"));
        active_indicator = new QLabel(TariffCard);
        active_indicator->setObjectName("active_indicator");
        active_indicator->setGeometry(QRect(220, 409, 16, 16));
        active_indicator->setStyleSheet(QString::fromUtf8("background-color:green;\n"
"border-radius:8;"));

        retranslateUi(TariffCard);

        QMetaObject::connectSlotsByName(TariffCard);
    } // setupUi

    void retranslateUi(QWidget *TariffCard)
    {
        TariffCard->setWindowTitle(QCoreApplication::translate("TariffCard", "Form", nullptr));
        monthly_btn->setText(QCoreApplication::translate("TariffCard", "Monthly", nullptr));
        daily_btn->setText(QCoreApplication::translate("TariffCard", "Daily", nullptr));
        tariff_name->setText(QCoreApplication::translate("TariffCard", "Tariff name", nullptr));
        daily_price->setText(QCoreApplication::translate("TariffCard", "Monthly price", nullptr));
        calls->setText(QCoreApplication::translate("TariffCard", "<html><head/><body><p>Calls in Neo Com</p></body></html>", nullptr));
        internet->setText(QCoreApplication::translate("TariffCard", "<html><head/><body><p>Internet</p></body></html>", nullptr));
        money_pic->setText(QString());
        calls_per_day->setText(QString());
        internet_per_day->setText(QString());
        id_label->setText(QCoreApplication::translate("TariffCard", "Id", nullptr));
        internet_2->setText(QCoreApplication::translate("TariffCard", "<html><head/><body><p>SMS</p></body></html>", nullptr));
        SMS->setText(QCoreApplication::translate("TariffCard", "<html><head/><body><p><br/></p></body></html>", nullptr));
        SMS_label->setText(QCoreApplication::translate("TariffCard", "<html><head/><body><p>SMS</p></body></html>", nullptr));
        price_label->setText(QCoreApplication::translate("TariffCard", "TextLabel", nullptr));
        internet_label->setText(QCoreApplication::translate("TariffCard", "TextLabel", nullptr));
        calls_label->setText(QCoreApplication::translate("TariffCard", "TextLabel", nullptr));
        edit_btn->setText(QCoreApplication::translate("TariffCard", "Edit data", nullptr));
        active_inactive_swithc_btn->setText(QCoreApplication::translate("TariffCard", "active", nullptr));
        active_indicator->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TariffCard: public Ui_TariffCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARIFFCARD_H
