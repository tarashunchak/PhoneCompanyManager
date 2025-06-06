#ifndef LINECHART_H
#define LINECHART_H

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QSplineSeries>
#include <QDateTimeAxis>
#include <QSqlQuery>

class LineChart : public QWidget
{
    Q_OBJECT
public:
    [[nodiscard]]LineChart(QWidget*);
    [[nodiscard]]LineChart();
    ~LineChart();
    void resize(const QSize&);
    void setQuery(QSqlQuery, QString, QString);

private:
    QChartView* chart_view;
    QSplineSeries* line_series;
    QChart* chart;
    QDateTimeAxis* axisX;
};

#endif // LINECHART_H
