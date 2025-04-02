#include "includes/requestspage.h"
#include "ui_requestspage.h"

#include "includes/databasemanager.h"
#include "includes/buttonsstylemanager.h"

RequestsPage::RequestsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RequestsPage)
    , db(&DatabaseManager::instance().getDatabase())

{

    ui->setupUi(this);

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });
}

RequestsPage::~RequestsPage()
{
    db = nullptr;
    delete ui;
}
