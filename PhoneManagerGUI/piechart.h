#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include <QPieSeries>
#include <QChartView>
#include <QSqlQuery>

class PieChart : public QWidget
{
    Q_OBJECT
public:
    [[nodiscard]] PieChart(QWidget*);
    [[nodiscard]] PieChart();
    ~PieChart();
    void resize(const QSize&);
    void setQuery(QSqlQuery, QString, QString);
private:
    QChartView* chart_view;
    QPieSeries* pie_series;
    QChart* chart;
};

#endif // PIECHART_H
