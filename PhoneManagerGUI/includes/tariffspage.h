#ifndef TARIFFSPAGE_H
#define TARIFFSPAGE_H

#include <QWidget>
#include "inserttariffdialog.h"
#include <QSqlQuery>
#include "tariffeditwidget.h"

namespace Ui {
class TariffsPage;
}

class TariffsPage : public QWidget
{
    Q_OBJECT

public:
    explicit TariffsPage(QWidget *parent = nullptr);
    ~TariffsPage();
    void setTariffsCards(QSqlQuery query = QSqlQuery{QSqlDatabase::database("remote")});
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
    TariffEditWidget* tariff_edit_widget;
};

#endif // TARIFFSPAGE_H
