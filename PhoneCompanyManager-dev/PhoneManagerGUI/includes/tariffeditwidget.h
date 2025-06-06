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
    void saveChanges();
    void discardChanges();
    void setTariffInformation(const uint);

private:
    Ui::TariffEditWidget *ui;
    uint tariff_id;
};

#endif // TARIFFEDITWIDGET_H
