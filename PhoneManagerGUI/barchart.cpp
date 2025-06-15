#include "includes/barchart.h"
#include <QChart>
#include <QSqlError>
#include <QList>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QDateTimeAxis>
#include <QDate>

BarChart::BarChart()
        : chart_view(new QChartView{this})
        , bar_series(new QBarSeries{})
        , chart(new QChart{})
{
    bar_series->setBarWidth(1);
    chart->setTheme(QChart::ChartThemeHighContrast);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart_view->setChart(chart);
    chart->addSeries(bar_series);
}

BarChart::BarChart(QWidget* parent)
        : QWidget(parent)
        , chart_view(new QChartView{this})
        , bar_series(new QBarSeries{})
        , chart(new QChart{})
{
    bar_series->setBarWidth(1);
    chart->setTheme(QChart::ChartThemeHighContrast);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart_view->setChart(chart);
    chart->addSeries(bar_series);
}

BarChart::~BarChart(){
}

void BarChart::resize(const QSize& size){
    chart_view->resize(size);
}

bool BarChart::setQuery(QSqlQuery query, const QString& field_name, const QString& label){
    if(!query.exec()){
        qDebug() << "Sql query error in BarChart(): " << query.lastError();
        if(chart->axes(Qt::Horizontal).contains(chart->axisX()))
        //chart->removeAxis(chart->axisX());
        //chart->removeAxis(chart->axisY());
        return false;
    }

    bar_series->clear();

    QStringList string_list;
    while(query.next()){
        QString raw_label{query.value(label == "" ? field_name : label).toString()};
        QDate date{QDate::fromString(raw_label, "yyyy-MM-dd")};
        QString formatted_label{date.toString("MM-dd")};

        QBarSet* bar_set = new QBarSet{query.value(field_name).toString()};
        string_list << formatted_label;

        connect(bar_set, &QBarSet::hovered, this, [bar_set](bool is_hovered){
            QColor color = bar_set->color();
            if(color.red() + 40 < 255 && color.green() + 40 < 255 && color.blue() + 40 < 255){
                bar_set->setColor(is_hovered ? QColor(color.red() + 20, color.green() + 20, color.blue() + 20)
                                         : QColor(color.red() - 20, color.green() - 20, color.blue() - 20));
            }else{
                bar_set->setColor(is_hovered ? QColor(color.red() - 10, color.green() - 10, color.blue() - 10)
                                         : QColor(color.red() + 10, color.green() + 10, color.blue() + 10));
            }
        });
        bar_set->setBorderColor("");
        *bar_set << query.value(field_name).toInt();
        if(!bar_series->append(bar_set)){
            qDebug() << "bar_series cannot append bar_set!";
        }
    }
    if(!bar_series->count()){
        chart->removeAxis(chart->axisX());
        chart->removeAxis(chart->axisY());
        return false;
    }

    chart->removeSeries(bar_series);
    chart->addSeries(bar_series);
    chart_view->setChart(chart);
    chart->createDefaultAxes();

    return true;
}
