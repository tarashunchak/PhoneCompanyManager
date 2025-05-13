#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "includes/currentuser.h"
#include <QSqlError>
#include "customersreport.h"

#include <QTextEdit>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
    , chat(new Chat{})
    , calculator(new Calculator{})
{
    ui->setupUi(this);
    ui->close_open_chat_btn->setIcon(QIcon{"./img/chat.svg"});
    ui->close_open_calc_btn->setIcon(QIcon{"./img/calculator.svg"});
    ui->profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});
    navigation_manager = new NavigationManager{ui->stackedWidget, this, ui->side_bar_menu};
    QList<QPushButton*>* buttons = new QList<QPushButton*>{
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn,
        ui->tasks_btn
    };
    buttons_style_manager = new ButtonsStyleManager{buttons};
    SetupConnections();
    ui->side_bar_menu->setVisible(false);
    ui->stackedWidget->setGeometry(0, 0, 1920, 1080);
    //navigation_manager->showLoginPage();
    ui->close_open_chat_btn->setVisible(false);
    ui->close_open_calc_btn->setVisible(false);
    chat->setStyleSheet("border-radius:8px;");
    chat->setVisible(false);
    chat->setGeometry(this->size().width()-60 - chat->size().width()
                      ,this->size().height()-60 - chat->size().height()
                      ,chat->size().width(), chat->size().height());
    calculator->setVisible(false);
    connect(ui->close_open_calc_btn, &QPushButton::clicked, this, [this](){calculator->setVisible(!calculator->isVisible());});
    /*CustomersReport* report = new CustomersReport{};
    report->generate();
    QTextEdit* textEdit = new QTextEdit{};
    textEdit->setHtml(report->getHtml());
    textEdit->setStyleSheet("color:black;");
    ui->stackedWidget->addWidget(textEdit);
    ui->stackedWidget->setCurrentWidget(textEdit);
    textEdit = nullptr;*/
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::SetCurrentUserInfo(){
    QSqlQuery query;
    query.prepare("SELECT * FROM Employees WHERE id = :id;");
    query.bindValue(":id", CurrentUser::getCurrentUserID());
    if(!query.exec() || !query.next()){
        qDebug() << "MainWidget::SetCurrentUserInfo() query fault!: " << query.lastError();
    }
    ui->name_label->setText(query.value("first_name").toString()
                            + " " + query.value("last_name").toString());
}

void MainWidget::SetupConnections(){
    connect(ui->close_open_chat_btn, &QPushButton::clicked, this, [this](){
        chat->setVisible(!chat->isVisible());
    });
    connect(this, &MainWidget::on_dashboard_btn_clicked, this, [this](){
        SetCurrentUserInfo();
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::DASHBOARD_BTN);
        navigation_manager->showDashboardPage();
    });
    connect(this, &MainWidget::on_customers_btn_clicked, this, [this](){
        SetCurrentUserInfo();
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::CUSTOMERS_BTN);
        navigation_manager->showCustomersPage();
    });
    connect(this, &MainWidget::on_employees_btn_clicked, this, [this](){
        SetCurrentUserInfo();
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::EMPLOYEES_BTN);
        navigation_manager->showEmployeesPage();
    });
    connect(this, &MainWidget::on_tariffs_btn_clicked, this, [this](){
        SetCurrentUserInfo();
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::TARIFFS_BTN);
        navigation_manager->showTariffsPage();
    });
    connect(this, &MainWidget::on_requests_btn_clicked, this, [this](){
        SetCurrentUserInfo();
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::REQUESTS_BTN);
        navigation_manager->showRequestsPage();
    });
    connect(this, &MainWidget::on_tasks_btn_clicked, this, [this](){
        //SetCurrentUserInfo();
        buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::TASKS_BTN);
        navigation_manager->showTasksPage();
    });
    connect(this, &MainWidget::on_log_out_btn_clicked, this, [this](){
        navigation_manager->showLoginPage();
    });
    connect(navigation_manager, &NavigationManager::show_small_buttons, ui->close_open_chat_btn, [this](){
        SetCurrentUserInfo();
        ui->close_open_chat_btn->setVisible(true);
        ui->close_open_calc_btn->setVisible(true);
    });
    connect(navigation_manager, &NavigationManager::hide_small_buttons, ui->close_open_chat_btn, [this](){
        ui->close_open_chat_btn->setVisible(false);
        ui->close_open_calc_btn->setVisible(false);
    });
}
