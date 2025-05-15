#ifndef TARIFFEDITWIDGET_H
#define TARIFFEDITWIDGET_H

#include <QWidget>

namespace Ui {
class TariffEditWidget;
}

class TariffEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TariffEditWidget(QWidget *parent = nullptr);
    ~TariffEditWidget();

private:
    Ui::TariffEditWidget *ui;
};

#endif // TARIFFEDITWIDGET_H
