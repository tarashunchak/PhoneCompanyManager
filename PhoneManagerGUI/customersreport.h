#ifndef CUSTOMERSREPORT_H
#define CUSTOMERSREPORT_H

#include "report.h"
#include <QSqlQuery>
#include <QDateTime>
#include <QPrinter>

class CustomersReport : public Report
{
public:
    CustomersReport();
    //template <typename... Args>
    void generate(/*report_filters<Args...> filters*/){
        QSqlQuery query{};
        query.prepare("SELECT *FROM Customers;");
        if(!query.exec()){
            qDebug() << "CustomersReport::generate(T) query fault!";
            return;
        }
        QString buff{"<h1 style='font-size:16pt;"
                     "color:black;"
                     "font-family:Consolas;"
                     "white-space: pre;'>"
                     "Customers Report : " + QDateTime::currentDateTime().toString() + "</h1><br>"};
        buff += "<h2 style='font-size:14pt;"
                "color:black;"
                "font-family:Consolas;"
                "white-space: pre;'>"
                "  id\tFull Name"
                "</h2>";
        while(query.next()){
            for(int i = 0; i < 100; ++i){
                buff += '-';
            }
            QString name = query.value("full_name").toString();
            size_t len = name.length();
            name += QString(QString{" "}.repeated(30 - len));
            QString id = query.value("id").toString();
            id += QString{" "}.repeated(7 - id.length());
            buff += "<div style='font-size:10pt; color:black; font-family:Consolas; white-space: pre;'>"
                    "|" + id + "| " + name + " |"
                             "</div><br>";
        }
        report_document->setHtml(buff);
        QPrinter printer{};
        printer.setOutputFileName("MyFile");
        report_document->print(&printer);
    }
    QString getHtml(){
        return report_document->toHtml();
    }
};

#endif // CUSTOMERSREPORT_H
