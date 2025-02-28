#ifndef TARIFFCARD_H
#define TARIFFCARD_H

#include <QWidget>

namespace Ui {
class TariffCard;
}

class TariffCard : public QWidget
{
    Q_OBJECT

public:
    explicit TariffCard(QWidget *parent = nullptr);
    ~TariffCard();

private:
    Ui::TariffCard *ui;
};

#endif // TARIFFCARD_H
