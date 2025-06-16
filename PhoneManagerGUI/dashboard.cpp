#include "includes/dashboard.h"
#include "ui_dashboard.h"
#include <QSqlQuery>
#include <QSqlError>

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
    , cust_qmodel(new QSqlTableModel(this))
    , req_qmodel(new QSqlTableModel(this))
    , cust_bar_chart(new BarChart{})
    , req_bar_chart(new BarChart{})
    , tariff_pie_chart(new PieChart{})
{
    ui->setupUi(this);

    req_bar_chart->setParent(ui->requests_statistic);
    cust_bar_chart->setParent(ui->customers_statistic);
    tariff_pie_chart->setParent(ui->tariff_statistics);
    tariff_pie_chart->resize(ui->tariff_statistics->size());
    cust_bar_chart->resize(ui->customers_statistic->size());
    cust_bar_chart->setParent(ui->customers_statistic);

    setTableViewConnection();
    setCustomersStatistics();
    setRequestsStatistics();
    setTariffsStatistics();
    setRequestsHistory();
    setTableViewStyles();

    connect(ui->req_date_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setRequestsStatistics);
    connect(ui->cust_date_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setCustomersStatistics);
    connect(ui->customers_period_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setTableViewConnection);
    connect(ui->requests_period_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setRequestsHistory);
    connect(ui->tariff_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setTariffsStatistics);
}

Dashboard::~Dashboard(){
    delete ui;
}

void Dashboard::setTableViewStyles(){
    ui->tableView->setModel(cust_qmodel);
    ui->requests_statistic_tableView->setModel(req_qmodel);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->requests_statistic_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnWidth(0, 80);
    ui->tableView->setColumnWidth(1, 223);
    ui->tableView->setColumnWidth(2, 223);
    ui->tableView->setColumnWidth(3, 81);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 223);
    ui->tableView->setColumnWidth(6, 80);
    ui->tableView->horizontalHeader()->setFixedHeight(30);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->requests_statistic_tableView->verticalHeader()->setVisible(false);
    //ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->requests_statistic_tableView->setColumnWidth(0, 80);
    ui->requests_statistic_tableView->setColumnWidth(1, 190);
    ui->requests_statistic_tableView->setColumnWidth(2, 200);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->requests_statistic_tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    const static QString style{
        "	background-color:rgb(50, 40, 85);"
        "	border:none;"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:14px;"
       /* "QHeaderView:section:first{"
        "	background-color:rgb(50, 40, 85);"
        "	border:none;"
        "	border-top-left-radius:10px;"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:14px;"
        "}"
        "QHeaderView:section:last{"
        "	background-color:rgb(50, 40, 85);"
        "	border:none;"
        "	border-top-right-radius:10px;"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:14px;"
        "}"*/
    };
    ui->tableView->horizontalHeader()->setStyleSheet(style);
    ui->requests_statistic_tableView->horizontalHeader()->setStyleSheet(style);
}

void Dashboard::setTableViewConnection(){
    QSqlQuery query(QSqlDatabase::database("local"));
    query.prepare("SELECT c.id AS \"Cust. ID\", "
                  "(COALESCE(c.first_name, '') || ' ' || COALESCE(c.last_name, '')) AS \"Full Name\", "
                  "c.phone AS \"Phone\", "
                  "c.tariff_id  AS \"Tariff ID\", "
                  "c.date AS \"Reg. date\", "
                  "(COALESCE(e.first_name, '') || ' ' || COALESCE(e.last_name, '')) AS \"Added By\", "
                  "c.is_active AS \"Is Active\" "
                  "FROM customers c "
                  "LEFT JOIN employees e ON e.id = c.added_by_id "
                  "WHERE DATE(c.date) >= DATE(CURRENT_DATE, '-"
                  + QString::number((ui->customers_period_comboBox->currentIndex()+1)*10) + " days') "
                  "AND c.is_visible = true "
                  "ORDER BY DATE(c.date) DESC;"
        );
    if(!query.exec())
        qDebug() << "dashboard tableView fault" << query.lastError().text();
    cust_qmodel->setQuery(std::move(query));
    ui->empty_cust_model->setVisible(!cust_qmodel->rowCount());
}
