#ifndef TARIFFSPAGE_H
#define TARIFFSPAGE_H

#include <QWidget>
#include "inserttariffdialog.h"
#include <QSqlQuery>

namespace Ui {
class TariffsPage;
}

class TariffsPage : public QWidget
{
    Q_OBJECT

public:
    explicit TariffsPage(QWidget *parent = nullptr);
    ~TariffsPage();
    void setTariffsCards(QSqlQuery query = QSqlQuery());
    void setCurrentUser();

signals:
    void on_add_tariff_btn_clicked();

private slots:
    void FindTariffInDB();

private:/*Methods*/
    void setConnections()const;

private:
    Ui::TariffsPage *ui;

    InsertTariffDialog insertT_Dialog;
};

#endif // TARIFFSPAGE_H
