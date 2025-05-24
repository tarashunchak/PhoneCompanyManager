#ifndef BARCHART_H
#define BARCHART_H

#include <QWidget>
#include <QSqlQuery>
#include <QChartView>
#include <QBarSeries>

class BarChart : public QWidget
{
    Q_OBJECT
public:
    [[nodiscard]] BarChart(QWidget*);
    [[nodiscard]] BarChart();
    ~BarChart();
    void resize(const QSize&);
    [[nodiscard]] bool setQuery(QSqlQuery&, const QString&, const QString& label = "");
private:
    QChartView* chart_view = nullptr;
    QBarSeries* bar_series = nullptr;
    QChart* chart = nullptr;
};

#endif // BARCHART_H
