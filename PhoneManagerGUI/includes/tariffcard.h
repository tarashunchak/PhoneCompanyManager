#ifndef TARIFFCARD_H
#define TARIFFCARD_H

#include <QFrame>
#include <QSqlRecord>

namespace Ui {
class TariffCard;
}

class TariffCard : public QFrame
{
    Q_OBJECT

public:
    explicit TariffCard(QFrame *parent = nullptr);
    ~TariffCard();
    void setTariffInfoFromQuery(QSqlRecord);

private slots:
    void setConnections()const;

signals:
    void on_edit_btn_clicked();

private:
    Ui::TariffCard *ui;
};

#endif // TARIFFCARD_H
