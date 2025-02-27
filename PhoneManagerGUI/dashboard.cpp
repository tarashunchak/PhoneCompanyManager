#include "dashboard.h"
#include "ui_dashboard.h"

#include "buttonsshadowmanager.h"

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    ButtonsShadowManager::setSideBarButtonsShadow({
       ui->dashboard_btn,
       ui->customers_btn,
       ui->employees_btn,
       ui->tariffs_btn,
       ui->requests_btn,
       ui->log_out_btn
    });

}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::setSideBarButtonsShadow(){

}
