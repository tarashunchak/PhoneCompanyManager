#include "includes/dashboard.h"
#include "ui_dashboard.h"

#include <QSqlQuery>
#include <QSqlError>
#include "includes/databasemanager.h"
#include "includes/buttonsstylemanager.h"
#include "includes/currentuser.h"

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
    , db(&DatabaseManager::instance().getDatabase())
    , cust_qmodel(new QSqlTableModel(this))
    , req_qmodel(new QSqlTableModel(this))
    , cust_bar_chart(new BarChart{})
    , req_bar_chart(new BarChart{})
    , tariff_pie_chart(new PieChart{})
    , chat(new ChatUI{})
{
    ui->setupUi(this);

    if(!is_empty_label){
        is_empty_label = new QLabel{"No Info"};
        is_empty_label->setStyleSheet("color: black; font-size: 40px;");
        is_empty_label->setAlignment(Qt::AlignCenter);
    }

    req_bar_chart->setParent(ui->requests_statistic);
    cust_bar_chart->setParent(ui->customers_statistic);
    tariff_pie_chart->setParent(ui->tariff_statistics);

    ui->close_open_chat_btn->setIcon(QIcon{"./img/chat.svg"});

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });

    setTableViewConnection();
    setCustomersStatistics();
    setRequestsStatistics();
    setTariffsStatistics();
    setRequestsHistory();

    ui->profile_pic->setPixmap(QPixmap{"./img/profile_photo.svg"});
    ui->name_label->setAlignment(Qt::AlignCenter);
    chat->setStyleSheet("border-radius:8px;");
    chat->setParent(this);
    chat->setVisible(false);
    chat->setGeometry(this->size().width()-60 - chat->size().width()
                      ,this->size().height()-60 - chat->size().height()
                      ,chat->size().width(), chat->size().height());

    connect(ui->req_date_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setRequestsStatistics);
    connect(ui->cust_date_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setCustomersStatistics);
    connect(ui->close_open_chat_btn, &QPushButton::clicked, this, [this](){
        chat->setVisible(!chat->isVisible());
    });
}

QLabel* Dashboard::is_empty_label = nullptr;

Dashboard::~Dashboard()
{
    is_empty_label->setParent(nullptr);
    db = nullptr;
    delete ui;
}

void Dashboard::setCurrentUser(){
    QSqlQuery query;
    query.prepare("SELECT *FROM Employees WHERE id = :empl_id;");
    const int empl_id = CurrentUser::getCurrentUserID();
    query.bindValue(":empl_id", empl_id);
    if(query.exec() && query.next()){
        ui->name_label->setText(query.value("full_name").toString());
    }else{
        qDebug() << "setCurrentUser Dashboard Page fault!" << query.lastError();
        return;
    }
}

void Dashboard::setTableViewConnection(){
    cust_qmodel->setQuery("SELECT *FROM Customers ORDER BY date DESC LIMIT 10;");
    ui->tableView->setModel(cust_qmodel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setStyleSheet("background-color:rgb(50,50,50);");
}
