#include "tariffcard.h"
#include "ui_tariffcard.h"

TariffCard::TariffCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffCard)
{
    ui->setupUi(this);
    qDebug() << "Tariff card is constructed!";

}

TariffCard::~TariffCard()
{
    delete ui;
}
