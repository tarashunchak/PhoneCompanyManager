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
    , req_qmodel(new QSqlTableModel{})
    , tariff_pie_chart(new PieChart{})
    , tariff_bar_chart(new BarChart{})
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->raise();

    tariff_pie_chart->setParent(ui->tariffs_history);
    tariff_pie_chart->resize(ui->tariffs_history->size());

    tariff_bar_chart->setParent(ui->tariffs_history);
    tariff_bar_chart->resize(ui->tariffs_history->size());

    ui->no_request_label->setVisible(false);

    ui->tableView->setModel(qmodel);
    SetTableViewStyle();

    ui->cust_profile_pic->setPixmap(QPixmap{"./img/profile_photo_cust.svg"});
    ui->return_btn->setIcon(QIcon{"./img/exit.png"});
    ui->delete_customer_btn->setIcon(QIcon{"./img/delete_can.png"});
    ui->delete_customer_btn->setStyleSheet("background-color:transparent;");

    ui->delete_customer_widget->close();

    SetConnections();
}

CustomersDetailsPage::~CustomersDetailsPage()
{
    delete ui;
}

uint CustomersDetailsPage::curr_cust_id = 0;

void CustomersDetailsPage::SetConnections(){
    connect(ui->return_btn, &QPushButton::clicked, this, [this](){emit on_return_btn_clicked();});
    connect(ui->open_chat_btn, &QPushButton::clicked, this, [this](){
        emit on_open_chat_btn_clicked(ui->phone_Label->text());
    });
    connect(ui->charts_comboBox, &QComboBox::currentIndexChanged, this, &CustomersDetailsPage::SetCharts);
    connect(ui->save_comment_btn, &QPushButton::clicked, this, &CustomersDetailsPage::SaveCommentToDB);
    connect(ui->delete_customer_btn, &QPushButton::clicked, ui->delete_customer_widget, &QWidget::show);
    connect(ui->confirm_btn, &QPushButton::clicked, this, [this](){
        ui->delete_customer_widget->close();
        DeleteCustomerFromDB();
        emit on_return_btn_clicked();
    });
    connect(ui->cancel_btn, &QPushButton::clicked, ui->delete_customer_widget, &QWidget::close);
}

void CustomersDetailsPage::SetCustomerInfo(const uint id){
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
    ui->requests_statistic_tableView->setModel(req_qmodel);
    ui->requests_statistic_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->requests_statistic_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    const static QString style{
        "QHeaderView{"
        "   height:30px;"
        "	background-color:rgb(50, 40, 85);"
        "	border:none;"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:16px;"
        "}"
        "QHeaderView:section:first{"
        "	background-color:rgb(50, 40, 85);"
        "	border:none;"
        "	border-top-left-radius:10px;"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:16px;"
        "}"
        "QHeaderView:section:last{"
        "	background-color:rgb(50, 40, 85);"
        "	border:none;"
        "	border-top-right-radius:10px;"
        "   font-family:Lato, Arial, Consolas;"
        "   font-size:16px;"
        "}"
    };
    ui->tableView->horizontalHeader()->setStyleSheet(style);
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
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

void CustomersDetailsPage::SetRequestsHistory()const{
    QSqlQuery request_query;
    request_query.prepare("SELECT id AS ID, "
                        "date AS Date, "
                        "request_type AS Type "
                        "FROM requests "
                        "WHERE cust_id = :id "
                        "GROUP BY date ORDER BY date DESC;");
    request_query.bindValue(":id", this->curr_cust_id);
    if(!request_query.exec() || !request_query.next()){
        qDebug() << "In CustomersDetailsPage::SetCustomersInfo::request_query fault!!!: " << request_query.lastError();
        ui->requests_statistic_tableView->setVisible(false);
        ui->no_request_label->setVisible(true);
        return;
    }
    req_qmodel->setQuery(std::move(request_query));
    if(!req_qmodel->rowCount()){
        ui->requests_statistic_tableView->setVisible(false);
        ui->no_request_label->setVisible(true);
    }else{
        ui->requests_statistic_tableView->setVisible(true);
        ui->no_request_label->setVisible(false);
    }
}

void CustomersDetailsPage::SetCharts(){
    SetTariffsChart();
    SetRequestsHistory();
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

void CustomersDetailsPage::DeleteCustomerFromDB()const{
    QSqlQuery query;
    query.prepare("DELETE FROM customers WHERE id = :cust_id;");
    qDebug() << "delete customer id = " << curr_cust_id;
    query.bindValue(":cust_id", curr_cust_id);
    if(!query.exec())
        qDebug() << "DeleteCustomerFromDB() fault " << query.lastError();
}
