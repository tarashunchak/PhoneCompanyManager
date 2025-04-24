#ifndef REQUESTSPAGE_H
#define REQUESTSPAGE_H

#include <QWidget>

#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class RequestsPage;
}

class RequestsPage : public QWidget
{
    Q_OBJECT

public:
    explicit RequestsPage(QWidget *parent = nullptr);
    ~RequestsPage();
    void setTableView();
    void setCurrentUser();

signals:
    void on_dashboard_btn_clicked();
    void on_customers_btn_clicked();
    void on_employees_btn_clicked();
    void on_tariffs_btn_clicked();
    void on_requests_btn_clicked();
    void on_log_out_btn_clicked();

private:
    Ui::RequestsPage *ui;

    QSqlDatabase* db;
    QSqlTableModel* qmodel;

};

#endif // REQUESTSPAGE_H
