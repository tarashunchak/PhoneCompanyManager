#include "includes/customerspage.h"
#include "ui_customerspage.h"
#include <QSqlError>
#include <QScrollArea>
#include <QPushButton>
#include <QLabel>

CustomersPage::CustomersPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersPage)
{
    ui->setupUi(this);

    SetCustomersCards();
    SetConnections();
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
        query.prepare("SELECT *FROM Customers;");
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
            "font-family:Lato;"
            "background-color:rgba(51, 51, 51, 1);;"
            "}"
            "QPushButton:hover{"
            "background-color:rgba(71, 71, 71, 1);;"
            "}");

        QLabel* image = new QLabel(card);
        image->setPixmap(QPixmap("./img/customer.png"));
        image->setGeometry(16, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

        QLabel* phone = new QLabel("Phone: " + query.value("phone").toString(), card);
        phone->setGeometry(80, 35, 200, 20);
        phone->setStyleSheet("background-color:transparent;color:white;font-size:18px;");

        QLabel* full_name = new QLabel(query.value("full_name").toString(), card);
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
    innerGridLayout->setContentsMargins(40, 70, 0, 0);

    mainWidget->setLayout(innerGridLayout);
    scrollArea->setWidget(mainWidget);
    ui->gridLayout->addWidget(scrollArea);
}

void CustomersPage::FindCustomersByName(){
    QSqlQuery query;
    query.prepare("SELECT *FROM Customers WHERE full_name LIKE :name "
                  "OR phone LIKE :phone;");
    query.bindValue(":name", ui->lineEdit->text() + "%");
    query.bindValue(":phone", ui->lineEdit->text() + "%");
    SetCustomersCards(std::move(query));
}
