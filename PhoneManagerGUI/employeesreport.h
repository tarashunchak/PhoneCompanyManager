#ifndef EMPLOYEESREPORT_H
#define EMPLOYEESREPORT_H

#include "report.h"
#include <QSqlQuery>

class EmployeesReport : public Report
{
public:
    EmployeesReport();
    //template <typename... Args>
    void generate(/*report_filters<Args...> filters*/){
        QSqlQuery query{};
        query.prepare("SELECT *FROM Employees;");
        if(!query.exec()){
            qDebug() << "EmployeesReport::generate(T) query fault!";
            return;
        }
        QString buff{"<h1>Employees Report</h1><br><br>"};
        while(query.next()){
            buff += ("<h2>" + query.value("full_name").toString() + "</h2><br>");
        }
        report_document->setHtml(buff);
    }
    QString getHtml(){
        return report_document->toHtml();
    }
};

#endif // EMPLOYEESREPORT_H
