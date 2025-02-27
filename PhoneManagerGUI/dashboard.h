#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

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

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
