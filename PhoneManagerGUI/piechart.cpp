#include "includes/piechart.h"
#include <QSqlError>

PieChart::PieChart()
    : chart_view(new QChartView{})
    , pie_series(new QPieSeries{})
    , chart(new QChart{})
{
    chart->setTheme(QChart::ChartThemeLight);
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
    chart->setTheme(QChart::ChartThemeLight);
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
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelInsideNormal);
        connect(slice, &QPieSlice::hovered, this, [slice](bool is_hovered){
            QColor color = slice->color();
            if(color.red() + 40 < 255 && color.green() + 40 < 255 && color.blue() + 40 < 255){
                slice->setColor(is_hovered ? QColor(color.red() + 20, color.green() + 20, color.blue() + 20)
                                       : QColor(color.red() - 20, color.green() - 20, color.blue() - 20));
            }else{
                slice->setColor(is_hovered ? QColor(color.red() - 10, color.green() - 10, color.blue() - 10)
                                       : QColor(color.red() + 10, color.green() + 10, color.blue() + 10));
            }
        });
        QColor color = slice->color();
        int brightness = qGray(color.rgb());

        QColor labelColor = (brightness < 128) ? Qt::white : Qt::black;
        slice->setLabelColor(labelColor);

        slice->setBorderColor(QColor{255, 255, 255});
        slice->setBorderWidth(0);
        slice->setExploded(true);
        slice->setExplodeDistanceFactor(0.01);
        QFont font = slice->labelFont();
        font.setBold(true);
        font.setPixelSize(14);
        slice->setLabelFont(font);
        if(!pie_series->append(slice)){
            qDebug() << "pie_series cannot append slice!";
        }
        slice = nullptr;
    }
    pie_series->setPieSize(80);
    chart->removeSeries(pie_series);
    chart->addSeries(pie_series);
    chart->legend()->hide();
    chart_view->setChart(chart);
}
