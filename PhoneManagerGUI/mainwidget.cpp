#include "includes/mainwidget.h"
#include "ui_mainwidget.h"
#include "includes/currentuser.h"
#include <QSqlError>
#include <QTextEdit>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
    , chat(new SupportChat{})
{
    ui->setupUi(this);
    ui->close_open_chat_btn->setIcon(QIcon{"./img/chat.svg"});
    ui->logo_label->setPixmap({"./img/NeoCom.svg"});
    ui->close_open_calc_btn->setIcon(QIcon{"./img/calculator.svg"});
    ui->profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});
    navigation_manager = new NavigationManager{ui->stackedWidget, this, ui->side_bar_menu};
    QList<QPushButton*>* buttons = new QList<QPushButton*>{
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn,
        ui->chats_btn
    };
    buttons_style_manager = new ButtonsStyleManager{buttons};
    SetupConnections();
    ui->side_bar_menu->setVisible(false);
    ui->stackedWidget->setGeometry(0, 0, 1920, 1080);
    ui->close_open_chat_btn->setVisible(false);
    ui->close_open_calc_btn->setVisible(false);
    chat->setStyleSheet("border-radius:8px;");
    chat->setVisible(false);
    chat->setGeometry(this->size().width() - 80 - chat->size().width()
                      ,this->size().height() - 80 - chat->size().height()
                      ,chat->size().width(), chat->size().height());
    ui->leave_session_btn->setIcon(QIcon{"./img/quit_icon.svg"});
    ui->leave_session_btn->setIconSize(QSize{50, 50});
    ui->not_read_message_label->setVisible(false);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::SetCurrentUserInfo(){
    QSqlQuery query(QSqlDatabase::database("local"));
    query.prepare("SELECT e.photo AS profile_pic, "
                  "(COALESCE(e.first_name, '') "
                  "|| ' ' || COALESCE(e.last_name, '')) AS full_name "
                  "FROM users u "
                  "JOIN employees e ON e.id = u.empl_id "
                  "WHERE u.id = :id;");
    query.bindValue(":id", CurrentUser::getCurrentUserID());
    if(!query.exec() || !query.next()){
        qDebug() << "MainWidget::SetCurrentUserInfo() query fault!: " << query.lastError();
    }
    QByteArray byteArr{query.value("profile_pic").toByteArray()};
    QPixmap pixmap{};
    pixmap.loadFromData(byteArr);
    ui->profile_pic->setPixmap(pixmap.isNull() ? QPixmap{"./img/profile_photo.svg"} : pixmap);
    ui->name_label->setText(query.value("full_name").toString());
}

void MainWidget::SetupConnections(){
    connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, &MainWidget::SetCurrentUserInfo);
    connect(ui->close_open_chat_btn, &QPushButton::clicked, this, [this](){
        chat->setVisible(!chat->isVisible());
    });
    connect(this, &MainWidget::on_dashboard_btn_clicked, this, [this](){
        //buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::DASHBOARD_BTN);
        NavigationManager::is_chat_page = false;
        navigation_manager->showDashboardPage();
    });
    connect(this, &MainWidget::on_customers_btn_clicked, this, [this](){
        //buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::CUSTOMERS_BTN);
        navigation_manager->showCustomersPage();
    });
    connect(this, &MainWidget::on_employees_btn_clicked, this, [this](){
        //buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::EMPLOYEES_BTN);
        navigation_manager->showEmployeesPage();
    });
    connect(this, &MainWidget::on_tariffs_btn_clicked, this, [this](){
        //buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::TARIFFS_BTN);
        navigation_manager->showTariffsPage();
    });
    connect(this, &MainWidget::on_requests_btn_clicked, this, [this](){
        //buttons_style_manager->SetActiveButton(ButtonsStyleManager::LEFT_SIDE_MENU::REQUESTS_BTN);
        navigation_manager->showRequestsPage();
    });
    connect(this, &MainWidget::on_log_out_btn_clicked, this, [this](){
        navigation_manager->showLoginPage();
    });
    connect(ui->chats_btn, &QPushButton::clicked, this, [this](){
        navigation_manager->showChatsPage();
    });
    connect(navigation_manager, &NavigationManager::show_small_buttons, ui->close_open_chat_btn, [this](){
        ui->leave_session_btn->setVisible(false);
        ui->close_open_chat_btn->setVisible(true);
    });
    connect(navigation_manager, &NavigationManager::hide_small_buttons, ui->close_open_chat_btn, [this](){
        ui->leave_session_btn->setVisible(true);
        chat->close();
        ui->close_open_chat_btn->setVisible(false);
    });
    connect(navigation_manager, &NavigationManager::open_chat, this, [this](const QString& phone){
        chat->show();
        chat->SetPhoneNumber(phone);
    });
    connect(navigation_manager, &NavigationManager::notify_employee, this, [this](){
        ui->not_read_message_label->setVisible(!NavigationManager::is_chat_page);
    });
}

void MainWidget::on_leave_session_btn_clicked()
{
    QCoreApplication::quit();
}
