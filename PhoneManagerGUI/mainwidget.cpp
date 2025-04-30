#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->close_open_chat_btn->setIcon(QIcon{"./img/chat.svg"});
    ui->profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});
    navigation_manager = new NavigationManager{ui->stackedWidget, this, ui->side_bar_menu};
    buttons_style_manager = new ButtonsStyleManager(
        {
         ui->dashboard_btn,
         ui->customers_btn,
         ui->employees_btn,
         ui->tariffs_btn,
         ui->requests_btn
        }
    );
    SetupConnections();
    ui->side_bar_menu->setVisible(false);
    ui->stackedWidget->setGeometry(0, 0, 1920, 1080);
    navigation_manager->showLoginPage();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::SetupConnections(){
    connect(this, &MainWidget::on_dashboard_btn_clicked, this, [this](){
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::DASHBOARD_BTN);
        navigation_manager->showDashboardPage();
    });
    connect(this, &MainWidget::on_customers_btn_clicked, this, [this](){
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::CUSTOMERS_BTN);
        navigation_manager->showCustomersPage();
    });
    connect(this, &MainWidget::on_employees_btn_clicked, this, [this](){
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::EMPLOYEES_BTN);
        navigation_manager->showEmployeesPage();
    });
    connect(this, &MainWidget::on_tariffs_btn_clicked, this, [this](){
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::TARIFFS_BTN);
        navigation_manager->showTariffsPage();
    });
    connect(this, &MainWidget::on_requests_btn_clicked, this, [this](){
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::REQUESTS_BTN);
        navigation_manager->showRequestsPage();
    });
    connect(this, &MainWidget::on_log_out_btn_clicked, this, [this](){
        navigation_manager->showLoginPage();
    });
}
