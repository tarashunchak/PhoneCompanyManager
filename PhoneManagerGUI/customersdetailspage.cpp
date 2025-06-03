#include "includes/customersdetailspage.h"
#include "ui_customersdetailspage.h"
#include "includes/currentuser.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QHeaderView>

CustomersDetailsPage::CustomersDetailsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersDetailsPage)
    , qmodel(new QSqlTableModel{})
    , tariff_pie_chart(new PieChart{})
    , tariff_bar_chart(new BarChart{})
    , usage_chart(new LineChart{})
{
    ui->setupUi(this);
    //ui->tableView->setGeometry(50, 530, 931, 450);
    //ui->tableView->resize(ui->details_widget->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->raise();

    tariff_pie_chart->setParent(ui->tariffs_history);
    tariff_pie_chart->resize(ui->tariffs_history->size());

    tariff_bar_chart->setParent(ui->tariffs_history);
    tariff_bar_chart->resize(ui->tariffs_history->size());

    usage_chart->setParent(ui->usage_history);
    usage_chart->resize(ui->usage_history->size());
    ui->no_usage_label->setVisible(false);

    ui->tableView->setModel(qmodel);
    SetTableViewStyle();

    ui->cust_profile_pic->setPixmap(QPixmap{"./img/profile_photo_cust.svg"});
    ui->return_btn->setIcon(QIcon{"./img/exit.png"});
    ui->delete_customer_btn->setIcon(QIcon{"./img/delete_can.png"});
    ui->delete_customer_btn->setStyleSheet("background-color:transparent;");

    SetConnections();
}

CustomersDetailsPage::~CustomersDetailsPage()
{
    delete ui;
}

uint CustomersDetailsPage::curr_cust_id = 0;

void CustomersDetailsPage::setCurrentUser(){
    QSqlQuery query;
    query.prepare("SELECT * FROM employees WHERE id = :empl_id;");
    const int empl_id = CurrentUser::getCurrentEmployeeID();
    query.bindValue(":empl_id", empl_id);
    if(!query.exec() || query.next())
        qDebug() << "setCurrentUser Dashboard Page fault!" << query.lastError();
}

void CustomersDetailsPage::SetConnections(){
    connect(ui->return_btn, &QPushButton::clicked, this, [this](){emit on_return_btn_clicked();});
    connect(ui->open_chat_btn, &QPushButton::clicked, this, [this](){
        emit on_open_chat_btn_clicked(ui->phone_Label->text());
    });
    connect(ui->charts_comboBox, &QComboBox::currentIndexChanged, this, &CustomersDetailsPage::SetCharts);
    connect(ui->save_comment_btn, &QPushButton::clicked, this, &CustomersDetailsPage::SaveCommentToDB);
}

void CustomersDetailsPage::SetCustomerInfo(const int id){
    this->curr_cust_id = id;
    QSqlQuery query;
    query.prepare("SELECT c.id AS \"Cust. ID\", "
                  "(COALESCE(first_name, '') || ' ' || COALESCE(last_name, '')) AS \"Full name\", "
                  "c.phone AS \"Phone\", "
                  "c.date AS \"Reg. date\", "
                  "t.tariff_name AS \"Tariff\", "
                  "cm.comment_text AS comment, "
                  "COALESCE(c.comment_id, -1) AS comm_id "
                  "FROM customers c "
                  "JOIN tariffs t ON t.id = c.tariff_id "
                  "LEFT JOIN comments cm ON cm.id = c.comment_id "
                  "WHERE c.id = :id;");
    query.bindValue(":id", this->curr_cust_id);

    if(!query.exec() || !query.next()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo fault!!!: " << query.lastError();
        return;
    }

    ui->cust_id_label->setText(query.value("Cust. ID").toString());
    ui->cust_id_label->setProperty("cust_id", query.value("Cust. ID"));
    ui->full_name_Label->setText(query.value("Full name").toString());
    ui->phone_Label->setText(query.value("Phone").toString());
    ui->reg_date_Label->setText(query.value("Reg. date").toString().left(10));
    ui->current_tariff_label->setText(query.value("Tariff").toString());
    ui->comment_textEdit->setPlainText(query.value("comment").toString());
    ui->comment_textEdit->setProperty("comment_id", query.value("comm_id"));
    if(!query.exec()){
        qDebug() << "customers details page qmodel";
    }
    qmodel->setQuery(std::move(query));

    SetCharts();
}

void CustomersDetailsPage::SetTableViewStyle(){
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setStyleSheet(
        "QTableView{"
        "background-color:white;"
        "color:black;"
        "font-size:16px;"
        "}"
    );
    /*ui->tableView->setColumnWidth(0, 133);
    ui->tableView->setColumnWidth(1, 133);
    ui->tableView->setColumnWidth(2, 133);
    ui->tableView->setColumnWidth(3, 133);
    ui->tableView->setColumnWidth(4, 133);
    ui->tableView->setColumnWidth(5, 133);
    ui->tableView->setColumnWidth(6, 133);*/
}

void CustomersDetailsPage::SetTariffsChart()const{
    QSqlQuery tariff_query;
    tariff_query.prepare("SELECT t.tariff_name AS name, t.id AS id "
                         "FROM customers c "
                         "JOIN tariffs t ON t.id = c.tariff_id "
                         "WHERE c.id = :id;");
    tariff_query.bindValue(":id", this->curr_cust_id);
    if(!tariff_query.exec()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo::tariff_query fault!!!: " << tariff_query.lastError();
        return;
    }

    bool is_pie_chart_active = ui->charts_comboBox->currentIndex();
    tariff_bar_chart->setVisible(!is_pie_chart_active);
    tariff_pie_chart->setVisible(is_pie_chart_active);

    if(is_pie_chart_active)
        tariff_pie_chart->setQuery(std::move(tariff_query), "name", "id");
    else
        tariff_bar_chart->setQuery(tariff_query, "id", "name");
}

void CustomersDetailsPage::SetUsageChart()const{
    QSqlQuery usage_query;
    usage_query.prepare("SELECT date AS usage_date, "
                        "COUNT(id) AS count "
                        "FROM usage "
                        "WHERE cust_id = :id "
                        "AND date >= (CURRENT_DATE - INTERVAL '7 days') "
                        "GROUP BY date ORDER BY date ASC;");

    usage_query.bindValue(":id", this->curr_cust_id);
    if(!usage_query.exec()){
        usage_chart->setVisible(false);
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo::usage_query fault!!!: " << usage_query.lastError();
        ui->no_usage_label->setVisible(true);
        return;
    }
    ui->no_usage_label->setVisible(false);
    usage_chart->setVisible(true);
    usage_chart->resize(ui->usage_history->size());
    usage_chart->setQuery(std::move(usage_query), "count", "usage_date");
}

void CustomersDetailsPage::SetCharts(){
    SetTariffsChart();
    SetUsageChart();
}

void CustomersDetailsPage::SaveCommentToDB(){
    static QSqlQuery query;
    int comment_id = ui->comment_textEdit->property("comment_id").toInt();
    if(comment_id == -1){
        query.prepare("INSERT INTO comments(comment_text, written_by_id) "
                      "VALUES(:text, :my_id) RETURNING id;");
        query.bindValue(":text", ui->comment_textEdit->toPlainText());
        query.bindValue(":my_id", CurrentUser::getCurrentUserID());

        if(!query.exec() || !query.next()){
            qDebug() << "insert into comment query fault: " << query.lastError();
            return;
        }
        comment_id = query.value("id").toInt();
        query.clear();
        query.prepare("UPDATE customers "
                      "SET comment_id = :comm_id "
                      "WHERE id = :cust_id;");
        query.bindValue(":comm_id", comment_id);
        query.bindValue(":cust_id", ui->cust_id_label->property("cust_id").toInt());

        if(!query.exec())
            qDebug() << "update customers comment_id query fault: " << query.lastError();

        return;
    }
    query.clear();
    query.prepare("UPDATE comments "
                  "SET comment_text = :text "
                  "WHERE id = :comm_id;");
    query.bindValue(":text", ui->comment_textEdit->toPlainText());
    query.bindValue(":comm_id", ui->comment_textEdit->property("comment_id").toUInt());
    if(!query.exec())
        qDebug() << "update comments query fault: " << query.lastError();
}
