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
    static void setEditable(const bool);
    static bool isEditable();

private slots:
    void setConnections()const;

signals:
    void on_edit_btn_clicked();

private:
    void SetActiveButtonStatement(bool);

private:
    Ui::TariffCard *ui;
    static bool is_editable;
};

#endif // TARIFFCARD_H
