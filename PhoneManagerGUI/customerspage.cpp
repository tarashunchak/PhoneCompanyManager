#include "customerspage.h"
#include "ui_customerspage.h"

#include <QSqlError>
#include "databasemanager.h"
#include <QScrollArea>
#include "buttonsstylemanager.h"

CustomersPage::CustomersPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersPage)
    , db(&DatabaseManager::instance().getDatabase())
{
    ui->setupUi(this);

    SetCustomersCards();
    SetConnections();

    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });

}

CustomersPage::~CustomersPage()
{
    db = nullptr;
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
            "background-color:rgba(51, 51, 51, 1);;"
            "}"
            "QPushButton:hover{"
            "background-color:rgba(71, 71, 71, 1);;"
            "}");

        QLabel* image = new QLabel(card);
        image->setPixmap(QPixmap("./img/customer.png"));
        image->setGeometry(20, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

        QLabel* phone = new QLabel("Phone: " + query.value("phone").toString(), card);
        phone->setGeometry(85, 35, 200, 20);
        phone->setStyleSheet("background-color:transparent;color:white;font-size:18px;");

        QLabel* full_name = new QLabel(query.value("full_name").toString(), card);
        full_name->setGeometry(85, 60, 250, 20);
        full_name->setStyleSheet("background-color:transparent;color:white;font-size:14px;");

        innerGridLayout->addWidget(card, rows, cols);

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
