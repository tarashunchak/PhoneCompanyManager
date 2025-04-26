#include "includes/barchart.h"
#include <QChart>
#include <QSqlError>

BarChart::BarChart()
        : chart_view(new QChartView{})
        , bar_series(new QBarSeries{})
        , chart(new QChart{})
{
    bar_series->setBarWidth(1);
    chart->setTheme(QChart::ChartThemeHighContrast);
    chart->setAnimationOptions(QChart::AllAnimations);

    chart_view->setChart(chart);
    chart_view->setParent(this);
    chart->addSeries(bar_series);
}

BarChart::BarChart(QWidget* parent)
        : QWidget(parent)
        , chart_view(new QChartView{})
        , bar_series(new QBarSeries{})
        , chart(new QChart{})
{
    bar_series->setBarWidth(1);
    chart->setTheme(QChart::ChartThemeHighContrast);
    chart->setAnimationOptions(QChart::AllAnimations);

    chart_view->setChart(chart);
    chart_view->setParent(this);
    chart->addSeries(bar_series);
}

BarChart::~BarChart(){
    chart->removeSeries(bar_series);
    delete bar_series;
    delete chart;
    delete chart_view;
}

void BarChart::resize(const QSize& size){
    chart_view->resize(size);
}

bool BarChart::setQuery(QSqlQuery query, const QString& counter){
    if(!query.exec()){
        qDebug() << "Sql query error in BarChart(): " << query.lastError();
        return false;
    }

    bar_series->clear();

    while(query.next()){
        QBarSet* bar_set = new QBarSet{query.value(counter).toString()};

        /*connect(bar_set, &QBarSet::hovered, this, [bar_set](bool is_hovered){
            QColor color = bar_set->color();
            if(color.red() + 30 < 255){
                bar_set->setColor(is_hovered ? QColor(color.red() + 30, color.green() + 30, color.blue() + 30)
                                         : QColor(color.red() - 30, color.green() - 30, color.blue() - 30));
            }else{
                bar_set->setColor(is_hovered ? QColor(255 - 30, color.green() + 30, color.blue() + 30)
                                         : QColor(color.red() - 30, color.green() - 30, color.blue() - 30));
            }
        });*/
        bar_set->setBorderColor("");
        *bar_set << query.value(counter).toInt();
        if(!bar_series->append(bar_set)){
            qDebug() << "bar_series cannot append bar_set!";
        }
    }
    if(!bar_series->count()){
        return false;
    }
    chart->removeSeries(bar_series);
    chart->addSeries(bar_series);
    chart_view->setChart(chart);
    return true;
}
