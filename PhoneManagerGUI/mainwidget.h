#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "includes/navigationmanager.h"
#include "includes/buttonsstylemanager.h"
#include "includes/chat.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void SetupConnections();

signals:
    void on_dashboard_btn_clicked();
    void on_customers_btn_clicked();
    void on_employees_btn_clicked();
    void on_tariffs_btn_clicked();
    void on_requests_btn_clicked();
    void on_log_out_btn_clicked();

private:
    Ui::MainWidget *ui;
    Chat* chat;
    NavigationManager* navigation_manager;
    ButtonsStyleManager* buttons_style_manager;
};

#endif // MAINWIDGET_H
