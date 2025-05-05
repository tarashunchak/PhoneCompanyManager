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
        query.prepare("SELECT id, phone, COUNT(*) as count FROM Customers;");
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
        buff += "<h2 style='font-size:10pt;"
                "color:black;"
                "font-family:Consolas;"
                "white-space: pre;'>"
                "  id\tPhone"
                "</h2>";
        while(query.next()){
            for(int i = 0; i < 60; ++i){
                buff += '-';
            }
            QString phone = query.value("phone").toString();
            QString id = query.value("id").toString();
            id += QString{" "}.repeated(6 - id.length());
            buff += "<div style='font-size:8pt; color:black; font-family:Consolas; white-space: pre;'>"
                    "|" + id + "| " + phone + " |"
                             "</div><br>";
        }
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
