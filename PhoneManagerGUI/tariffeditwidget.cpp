#include "includes/tariffeditwidget.h"
#include "ui_tariffeditwidget.h"

TariffEditWidget::TariffEditWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffEditWidget)
{
    ui->setupUi(this);
}

TariffEditWidget::~TariffEditWidget()
{
    delete ui;
}
