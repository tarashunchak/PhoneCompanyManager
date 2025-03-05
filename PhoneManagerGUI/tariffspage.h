#ifndef TARIFFSPAGE_H
#define TARIFFSPAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include "inserttariffdialog.h"

namespace Ui {
class TariffsPage;
}

class TariffsPage : public QWidget
{
    Q_OBJECT

public:
    explicit TariffsPage(QWidget *parent = nullptr);
    ~TariffsPage();

signals:
    void on_dashboard_btn_clicked();
    void on_customers_btn_clicked();
    void on_employees_btn_clicked();
    void on_requests_btn_clicked();

private slots:
    void FindTariffInDB();

private:/*Methods*/
    void SetTariffsCards(QSqlQuery);
    void SetConnections()const;

private:
    Ui::TariffsPage *ui;

    QSqlDatabase* db;
    InsertTariffDialog* insertT_Dialog;
};

#endif // TARIFFSPAGE_H
