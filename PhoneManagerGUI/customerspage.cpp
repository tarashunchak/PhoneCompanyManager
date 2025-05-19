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
    connect(ui->add_cust_btn, &QPushButton::clicked, insert_customer_dialog, &QDialog::exec);
    connect(ui->add_cust_btn, &QPushButton::clicked, insert_customer_dialog
                                , &InsertCustomerDialog::updateComboBoxData);
}

CustomersPage::~CustomersPage()
{
    delete ui;
}

void CustomersPage::SetConnections(){
    connect(ui->lineEdit, &QLineEdit::textEdited, this, &CustomersPage::FindCustomersByName);
}

void CustomersPage::SetCustomersCards(QSqlQuery query){
    QLayout* layout = ui->gridLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }
    if(!query.exec()){
        query.prepare("SELECT * FROM Customers;");
        if(!query.exec()){
            qDebug() << "SetCustomersCards Query fault!!!: " << query.lastError();
            return;
        }
    }

    int cols = 0;
    int rows = 0;

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("border:none;");

    QWidget* mainWidget = new QWidget;
    QGridLayout* innerGridLayout = new QGridLayout(mainWidget);
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
        image->setPixmap(QPixmap("./img/customer.png"));
        image->setGeometry(16, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

        QLabel* phone = new QLabel("Phone: " + query.value("phone").toString(), card);
        phone->setGeometry(80, 35, 200, 20);
        phone->setStyleSheet("background-color:transparent;color:white;font-size:18px;");

        QLabel* full_name = new QLabel(query.value("first_name").toString()
                                    + query.value("last_name").toString(), card);

        full_name->setGeometry(80, 60, 250, 20);
        full_name->setStyleSheet("background-color:transparent;color:white;font-size:14px;");

        innerGridLayout->addWidget(card, rows, cols);
        const int id = query.value("id").toInt();
        connect(card, &QPushButton::clicked, this, [this, id](){emit customer_selected(id);});

        cols++;
        if(cols % 5 == 0){
            cols = 0;
            rows++;
        }
    }
    innerGridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    innerGridLayout->setHorizontalSpacing(34);
    innerGridLayout->setVerticalSpacing(40);
    innerGridLayout->setContentsMargins(40, 40, 0, 0);

    mainWidget->setLayout(innerGridLayout);
    scrollArea->setWidget(mainWidget);
    ui->gridLayout->addWidget(scrollArea);
}

void CustomersPage::FindCustomersByName(){
    QSqlQuery query;
    query.prepare("SELECT * FROM customers "
                  "WHERE first_name LIKE LOWER(:name) "
                  "OR last_name LIKE LOWER(:name) "
                  "OR phone LIKE LOWER(:phone);");
    QString text = ui->lineEdit->text() + "%";
    query.bindValue(":name", text);
    query.bindValue(":phone", text);
    SetCustomersCards(std::move(query));
}
