#include "customerspage.h"
#include "ui_customerspage.h"

#include <QSqlQuery>
#include <QSqlError>
#include "databasemanager.h"
#include "buttonsshadowmanager.h"
#include <QScrollArea>

CustomersPage::CustomersPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersPage)
    , db(DatabaseManager::instance().getDatabase())
{
    ui->setupUi(this);

    SetCustomersCards();

    ButtonsShadowManager::setSideBarButtonsShadow({
                                       ui->dashboard_btn,
                                       ui->customers_btn,
                                       ui->employees_btn,
                                       ui->tariffs_btn,
                                       ui->requests_btn,
                                       ui->log_out_btn
    });

}

CustomersPage::~CustomersPage()
{
    delete ui;
}

void CustomersPage::SetCustomersCards(){

    QLayout* layout = ui->gridLayout;
    if(layout){
        QLayoutItem* item;
        while((item = layout->itemAt(0))){
            delete item->widget();
            delete item;
        }
    }

    QSqlQuery query("SELECT *FROM Customers;");
    if(!query.exec()){
        qDebug() << "In SetCustomersCards Query fault!!!: " << query.lastError();
        return;
    }

    int cols = 0;
    int rows = 0;

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("border:none;");

    QWidget* mainWidget = new QWidget(this);
    QGridLayout* innerGridLayout = new QGridLayout(mainWidget);
    while(query.next()){
        QPushButton* card = new QPushButton;
        card->setMinimumSize(350, 260);
        card->setMaximumSize(350, 260);
        card->setStyleSheet("background-color:#1F2937;");

        innerGridLayout->addWidget(card, rows, cols);
        innerGridLayout->setHorizontalSpacing(50);
        innerGridLayout->setVerticalSpacing(60);
        innerGridLayout->setContentsMargins(50, 70, 50, 50);
        cols++;
        if(cols % 4 == 0){
            cols = 0;
            rows++;
        }
    }
    mainWidget->setLayout(innerGridLayout);
    scrollArea->setWidget(mainWidget);
    ui->gridLayout->addWidget(scrollArea);
}
