#include "linechart.h"
#include <QSqlError>
#include <QEasingCurve>
#include <QDateTime>

LineChart::LineChart(QWidget* parent)
    : QWidget(parent)
    , chart_view(new QChartView{})
    , line_series(new QSplineSeries{})
    , chart(new QChart{})
    , axisX(new QDateTimeAxis{})
{
    QPen pen{};
    pen.setWidth(5);
    pen.setColor(Qt::black);
    line_series->setPen(pen);
    chart_view->setParent(this);
    chart->setTheme(QChart::ChartThemeQt);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationEasingCurve(QEasingCurve::InOutQuad);
    chart->setAnimationDuration(500);
    chart_view->setChart(chart);
    chart->addSeries(line_series);
}


LineChart::LineChart()
    : chart_view(new QChartView{})
    , line_series(new QSplineSeries{})
    , chart(new QChart{})
    , axisX(new QDateTimeAxis{})
{
    QPen pen{};
    pen.setWidth(5);
    pen.setColor(Qt::black);
    line_series->setPen(pen);
    chart_view->setParent(this);
    chart->setTheme(QChart::ChartThemeQt);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationEasingCurve(QEasingCurve::InOutQuad);
    chart->setAnimationDuration(500);
    chart_view->setChart(chart);
    chart->addSeries(line_series);

}

LineChart::~LineChart(){
    chart->removeSeries(line_series);
    delete line_series;
    delete chart;
    delete chart_view;
}

void LineChart::resize(const QSize& size){
    chart_view->resize(size);
}

void LineChart::setQuery(QSqlQuery query, QString str, QString strY){
    line_series->clear();
    if(!query.exec()){
        qDebug() << "in LineChart::setQuery() fault: " << query.lastError();
        return;
    }

    //int x{0};
    int y{};
    while(query.next()){
        y = query.value(str).toInt();
        line_series->append(QDateTime::fromString(query.value(strY).toString()
                                                  , "yyyy-MM-dd").toMSecsSinceEpoch(), y);
    }
    axisX->setFormat("yyyy-MM-dd");
    axisX->setTitleText("Date");

    connect(line_series, &QSplineSeries::hovered, this, [this](const QPointF&, bool is_hovered){
        QPen pen{};
        pen.setWidth(5);
        pen.setColor(is_hovered ? Qt::lightGray : Qt::black);
        line_series->setPen(pen);
    });

    chart->removeSeries(line_series);
    chart->addSeries(line_series);
    chart->createDefaultAxes();
    chart_view->setChart(chart);
    chart_view->setContentsMargins(0, 0, 0, 0);
}
