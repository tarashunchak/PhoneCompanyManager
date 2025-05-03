#include "report.h"
#include <QSqlQuery>
#include <QSqlError>

Report::Report() : report_document(new QTextDocument{}){}

Report::~Report(){
    delete report_document;
}
