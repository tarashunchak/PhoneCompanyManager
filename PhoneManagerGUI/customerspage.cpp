#include "includes/customerspage.h"
#include "ui_customerspage.h"
#include <QSqlError>
#include <QScrollArea>
#include <QPushButton>
#include <QLabel>

CustomersPage::CustomersPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersPage)
    , insert_customer_dialog(new InsertCustomerDialog{})
{
    ui->setupUi(this);

    SetCustomersCards();
    SetConnections();

    ui->scrollAreaWidgetContents->setLayout(ui->gridLayout);

    ui->filter_pic->setPixmap(QPixmap{"./img/filter.png"});
    filter_animation = new QPropertyAnimation{ui->filter_widget, "pos"};
    filter_animation->setDuration(200);

    ui->gridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->gridLayout->setHorizontalSpacing(34);
    ui->gridLayout->setVerticalSpacing(40);
    ui->gridLayout->setContentsMargins(40, 40, 0, 0);

    ui->sort_by_comboBox->clear();
    ui->sort_by_comboBox->addItem("By date(newest)", " ORDER BY date DESC;");
    ui->sort_by_comboBox->addItem("By name(a-z)", " ORDER BY first_name ASC;");
    ui->sort_by_comboBox->addItem("By name(z-a)", " ORDER BY first_name DESC;");
    ui->sort_by_comboBox->addItem("By date(oldest)", " ORDER BY date ASC;");
}

CustomersPage::~CustomersPage()
{
    delete ui;
}

void CustomersPage::SetConnections(){
    connect(ui->lineEdit, &QLineEdit::textEdited
            , this, &CustomersPage::FindCustomersByName);
    connect(ui->add_cust_btn, &QPushButton::clicked
            , insert_customer_dialog, &QDialog::exec);
    connect(ui->add_cust_btn, &QPushButton::clicked, insert_customer_dialog
            , &InsertCustomerDialog::updateComboBoxData);
    connect(ui->close_open_filter_btn, &QPushButton::clicked
            , this, &CustomersPage::open_close_filter_widget);
    connect(ui->apply_filter_btn, &QPushButton::clicked, this, &CustomersPage::apply_filters);
}


void CustomersPage::SetCustomersCards(QSqlQuery query){
    static QPixmap pixmap{"./img/customer.png"};
    QLayout* layout = ui->gridLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }
    if(!query.exec()){
        query.prepare("SELECT * FROM customers;");
        if(!query.exec()){
            qDebug() << "SetCustomersCards Query fault!!!: " << query.lastError();
            return;
        }
    }

    int cols = 0;
    int rows = 0;

    while(query.next()){
        QPushButton* card = new QPushButton;
        card->setMinimumSize(290, 120);
        card->setMaximumSize(290, 120);
        card->setStyleSheet(
            "QPushButton{"
            "	font-family:Lato, Consolas;"
            "	border-radius:8px;"
            "	background-color:rgb(51, 51, 51);"
            "}"
            "QPushButton:hover{"
            "	background-color:rgb(71, 71, 71);"
            "}");

        QLabel* image = new QLabel(card);
        image->setPixmap(pixmap);
        image->setGeometry(16, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

        QLabel* phone = new QLabel("Phone: " + query.value("phone").toString(), card);
        phone->setGeometry(80, 35, 200, 20);
        phone->setStyleSheet("background-color:transparent;color:white;font-size:18px;");

        QLabel* full_name = new QLabel(query.value("first_name").toString()
                                    + query.value("last_name").toString(), card);

        full_name->setGeometry(80, 60, 250, 20);
        full_name->setStyleSheet("background-color:transparent;color:white;font-size:14px;");

        ui->gridLayout->addWidget(card, rows, cols);
        const int id = query.value("id").toInt();
        connect(card, &QPushButton::clicked, this, [this, id](){emit customer_selected(id);});

        cols++;
        if(cols % 5 == 0){
            cols = 0;
            rows++;
        }
    }
}

void CustomersPage::FindCustomersByName(){
    QSqlQuery query;
    query.prepare("SELECT * FROM customers "
                  "WHERE LOWER(first_name) LIKE LOWER(:text) "
                  "OR LOWER(last_name) LIKE LOWER(:text) "
                  "OR LOWER(first_name || ' ' || last_name) LIKE LOWER(:text) "
                  "OR LOWER(phone) LIKE LOWER(:text);");
    QString text = ui->lineEdit->text() + "%";
    query.bindValue(":text", text);
    SetCustomersCards(std::move(query));
}
