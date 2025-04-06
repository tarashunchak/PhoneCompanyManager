#include "barchart.h"
#include <QChart>
#include <QSqlError>

BarChart::BarChart()
        : chart_view(new QChartView{}), bar_series(new QBarSeries{})
{
    bar_series->setBarWidth(1);
}

BarChart::BarChart(QWidget* parent)
        : QWidget(parent), chart_view(new QChartView{}), bar_series(new QBarSeries{})
{
    bar_series->setBarWidth(1);
}

BarChart::~BarChart(){
    delete bar_series;
    delete chart_view;
}

void BarChart::resize(const QSize& size){
    chart_view->resize(size);
}

void BarChart::setQuery(QSqlQuery query, const QString& counter){

    bar_series->clear();

    if(!query.exec()){
        qDebug() << "Sql query error in BarChart(): " << query.lastError();
        return;
    }

    while(query.next()){
        QBarSet* bar_set = new QBarSet{query.value(counter).toString()};

        connect(bar_set, &QBarSet::hovered, this, [bar_set](bool is_hovered){
            QColor color = bar_set->color();
            bar_set->setColor(is_hovered ? QColor(color.red() + 30, color.green() + 30, color.blue() + 30)
                                         : QColor(color.red() - 30, color.green() - 30, color.blue() - 30));
        });

        bar_set->setBorderColor("");
        *bar_set << query.value(counter).toInt();
        bar_series->append(bar_set);
        bar_set = nullptr;
    }

    QChart* chart  = new QChart{};
    chart->setTheme(QChart::ChartThemeHighContrast);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(bar_series);

    chart_view->setChart(chart);
    chart_view->setParent(this);

}
