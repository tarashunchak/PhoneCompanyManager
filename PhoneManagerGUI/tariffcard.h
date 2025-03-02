#ifndef TARIFFCARD_H
#define TARIFFCARD_H

#include <QFrame>

namespace Ui {
class TariffCard;
}

class TariffCard : public QFrame
{
    Q_OBJECT

public:
    explicit TariffCard(QFrame *parent = nullptr);
    ~TariffCard();
    void setTariffNameLabelText(const QString&);

private slots:
    void setConnections()const;

private:
    Ui::TariffCard *ui;
};

#endif // TARIFFCARD_H
