#include "includes/piechart.h"
#include <QSqlError>

PieChart::PieChart()
    : chart_view(new QChartView{})
    , pie_series(new QPieSeries{})
    , chart(new QChart{})
{
    chart->setTheme(QChart::ChartThemeQt);
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
    chart->setTheme(QChart::ChartThemeQt);
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
    pie_series->clear();
    if(!query.exec()){
        qDebug() << "in PieChart::setQuery() fault: " << query.lastError();
        return;
    }
    QString tmp_label;
    qreal tmp_value;
    while(query.next()){
        tmp_label = query.value(label_for_query).toString();
        tmp_value = query.value(value_for_query).toInt();
        QPieSlice* slice = new QPieSlice{tmp_label, tmp_value};
        slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
        connect(slice, &QPieSlice::hovered, this, [slice](bool is_hovered){
            QColor color = slice->color();
            slice->setColor(is_hovered ? QColor(color.red() + 40, color.blue() + 40, color.green() + 40)
                                       : QColor(color.red() - 40, color.blue() - 40, color.green() - 40));
        });
        slice->setBorderColor(QColor{255, 255, 255});
        slice->setBorderWidth(0);
        if(!pie_series->append(slice)){
            qDebug() << "pie_series cannot append slice!";
        }
        slice = nullptr;
    }
    pie_series->setPieSize(100);
    chart->removeSeries(pie_series);
    chart->addSeries(pie_series);
    chart_view->setChart(chart);
}
