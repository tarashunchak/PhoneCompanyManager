#include "piechart.h"
#include <QSqlError>

PieChart::PieChart()
    : chart_view(new QChartView{})
    , pie_series(new QPieSeries{})
    , chart(new QChart{})
{
    chart->setTheme(QChart::ChartThemeHighContrast);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart_view->setChart(chart);
    chart_view->setParent(this);
    chart->addSeries(pie_series);
}

PieChart::PieChart(QWidget* parent)
    : QWidget(parent)
    , chart_view(new QChartView{})
    , pie_series(new QPieSeries{})
    , chart(new QChart{})
{
    chart->setTheme(QChart::ChartThemeHighContrast);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart_view->setChart(chart);
    chart_view->setParent(this);
    chart->addSeries(pie_series);
}

PieChart::~PieChart(){
    chart->removeSeries(pie_series);
    delete pie_series;
    delete chart;
    delete chart_view;
}

void PieChart::resize(const QSize& size){
    chart_view->resize(size);
}

void PieChart::setQuery(QSqlQuery query, QString label_for_query, QString value_for_query){
    if(!query.exec()){
        qDebug() << "in PieChart::setQuery() fault: " << query.lastError();
        return;
    }
    pie_series->clear();
    QString tmp_label;
    qreal tmp_value;
    while(query.next()){
        tmp_label = query.value(label_for_query).toString();
        tmp_value = query.value(value_for_query).toInt();
        QPieSlice* slice = new QPieSlice{tmp_label, tmp_value};
        connect(slice, &QPieSlice::hovered, this, [slice](bool is_hovered){
            QColor color = slice->color();
            slice->setColor(is_hovered ? QColor(color.red() + 30, color.blue() + 30, color.green() + 30)
                                       : QColor(color.red() - 30, color.blue() - 30, color.green() - 30));
        });
        slice->setBorderColor("");
        if(!pie_series->append(slice)){
            qDebug() << "pie_series cannot append slice!";
        }
        slice = nullptr;
    }
    chart->removeSeries(pie_series);
    chart->addSeries(pie_series);
    chart_view->setChart(chart);
}
