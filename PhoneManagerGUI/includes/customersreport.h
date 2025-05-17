#ifndef CUSTOMERSREPORT_H
#define CUSTOMERSREPORT_H

#include "report.h"
#include <QSqlQuery>
#include <QDateTime>
#include <QDate>
#include <QPrinter>
#include <QFileDialog>

class CustomersReport : public Report
{
public:
    CustomersReport();
    //template <typename... Args>
    void generate(/*report_filters<Args...> filters*/){
        QSqlQuery query{};
        query.prepare("SELECT * FROM Customers;");
        if(!query.exec()){
            qDebug() << "CustomersReport::generate(T) query fault!";
            return;
        }
        QString buff{"<h1 style='font-size:12pt;"
                     "color:black;"
                     "font-family:Consolas;"
                     "white-space: pre;'>"
                     "Customers Report : " + QDate::currentDate().toString() + "</h1><br>"
                                                         "Customers quantity: " + query.value("count").toString()};

        buff += "<h2 style='font-size:14pt;"
                "color:black;"
                "font-family:Consolas;"
                "white-space: pre;'>";
        buff += "</h2><table border='1' cellpadding='5' cellspacing='0' style='border-collapse: collapse;'>";
        buff += "<tr style='background-color: #a2a2a2; border: 1px solid black;'>"
                "<th style='font-size:14pt; text-align: left; border: 1px solid black;'>ID </th>"
                "<th style='font-size:14pt; text-align: left; border: 1px solid black;'>Phone</th>"
                "<th style='font-size:14pt; text-align: left; border: 1px solid black;'>Tariff ID</th>"
                "<th style='font-size:14pt; text-align: left; border: 1px solid black;'>Reg. date</th>"
                "</tr>";
        QString id;
        QString phone;
        QString tariff_id;
        QString registration_date;

        while(query.next()){
            id = query.value("id").toString();
            phone = query.value("phone").toString();
            tariff_id = query.value("tariff_id").toString();
            registration_date = query.value("date").toString().left(10);
            id += QString{" "}.repeated(8 - id.length());
            buff += "<tr>"
                    "<td style='font-size:10pt; padding: 5px; border: 1px solid black;'>" + id + "</td>"
                           "<td style='font-size:10pt; padding: 5px; border: 1px solid black;'>" + phone + "</td>"
                                "<td style='font-size:10pt; padding: 5px; border: 1px solid black;'>" + tariff_id + "</td>"
                                    "<td style='font-size:10pt; padding: 5px; border: 1px solid black;'>" + registration_date + "</td>"
                              "</tr>";
        }

        buff += "</table>";

        report_document->setHtml(buff);
        QFileDialog file_dialog{};
        QString file = file_dialog.getSaveFileName();
        QPrinter printer{};
        printer.setOutputFileName(file);
        report_document->print(&printer);
    }
    QString getHtml(){
        return report_document->toHtml();
    }
};

#endif // CUSTOMERSREPORT_H
