#ifndef REPORT_H
#define REPORT_H

#include <QTextDocument>

template <typename... Args>
using report_filters = std::tuple<Args...>;

class Report
{
public:
    [[nodiscard]]Report();
    virtual ~Report();
    template <typename... Args>
    void generate(report_filters<Args...>) = delete;

protected:
    QTextDocument* report_document;
};

#endif // REPORT_H
