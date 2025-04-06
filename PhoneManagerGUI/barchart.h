#ifndef BARCHART_H
#define BARCHART_H

#include <QWidget>
#include <QList>
#include <QBarSet>
#include <QSqlQuery>
#include <QChartView>
#include <QBarSeries>

class BarChart : public QWidget
{
    Q_OBJECT
public:
    [[nodiscard]] BarChart(QWidget* parent);
    [[nodiscard]] BarChart();
    ~BarChart();
    void resize(const QSize&);
    void setQuery(QSqlQuery, const QString&);
private:
    QChartView* chart_view;
    QBarSeries* bar_series;
};

#endif // BARCHART_H
