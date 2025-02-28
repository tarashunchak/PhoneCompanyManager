#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

signals:
    void on_customers_btn_clicked();
    void on_employees_btn_clicked();
    void on_tariffs_btn_clicked();
    void on_requests_btn_clicked();

private:/*Methods*/
    void setTableViewConnection();

private:
    Ui::Dashboard *ui;
    QSqlDatabase* db;
    QSqlQueryModel* qmodel;

};

#endif // DASHBOARD_H
