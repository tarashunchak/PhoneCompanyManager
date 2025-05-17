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
    //, chat(new Chat{})
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

    setTableViewConnection();
    setCustomersStatistics();
    setRequestsStatistics();
    setTariffsStatistics();
    setRequestsHistory();

    //chat->setStyleSheet("border-radius:8px;");
    //chat->setParent(this);
    //chat->setVisible(false);
    //chat->setGeometry(this->size().width()-60 - chat->size().width()
    //                  ,this->size().height()-60 - chat->size().height()
    //                  ,chat->size().width(), chat->size().height());

    connect(ui->req_date_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setRequestsStatistics);
    connect(ui->cust_date_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setCustomersStatistics);
    connect(ui->customers_period_comboBox, &QComboBox::currentIndexChanged, this, &Dashboard::setTableViewConnection);
}

Dashboard::~Dashboard(){
    delete ui;
}

QLabel* Dashboard::is_empty_label = nullptr;

void Dashboard::setTableViewConnection(){
    cust_qmodel->setQuery("SELECT * FROM Customers ORDER BY date DESC LIMIT " +
                          QString{std::to_string((ui->customers_period_comboBox->currentIndex()+1)*10).c_str()} + ";");
    ui->tableView->setModel(cust_qmodel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setStyleSheet("border-top-right-radius:10px;background-color:rgb(50,50,50);");
}
