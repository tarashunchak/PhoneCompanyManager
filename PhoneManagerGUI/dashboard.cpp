#include "includes/dashboard.h"
#include "ui_dashboard.h"

#include <QSqlQuery>
#include <QSqlError>
#include "includes/databasemanager.h"
#include "includes/buttonsstylemanager.h"
#include "includes/currentuser.h"
#include "chatui.h"

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

    req_bar_chart->setParent(ui->requests_statistic);
    cust_bar_chart->setParent(ui->customers_statistic);
    tariff_pie_chart->setParent(ui->tariff_statistics);

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

    chat->setParent(this);
    chat->setGeometry(this->size().width() - chat->size().width()
                      ,this->size().height() - chat->size().height()
                      ,chat->size().width(), chat->size().height());

    connect(ui->req_date_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setRequestsStatistics);
    connect(ui->cust_date_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setCustomersStatistics);
    connect(ui->close_open_chat_btn, &QPushButton::clicked, this, [this](){
        chat->setVisible(!chat->isVisible());
    });
}

Dashboard::~Dashboard()
{
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
