#include "employeespage.h"
#include "ui_employeespage.h"

#include "databasemanager.h"
#include <QSqlError>
#include <QScrollArea>

EmployeesPage::EmployeesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesPage)
    , db(&DatabaseManager::instance().getDatabase())
{
    ui->setupUi(this);

    ui->dashboard_btn->setIcon(QIcon("./img/dashboards.png"));
    ui->customers_btn->setIcon(QIcon("./img/customers.png"));
    ui->employees_btn->setIcon(QIcon("./img/employee.png"));
    ui->tariffs_btn->setIcon(QIcon("./img/tariffs.png"));
    ui->requests_btn->setIcon(QIcon("./img/requests.png"));

    SetEmployeesCards(QSqlQuery());

}

EmployeesPage::~EmployeesPage()
{
    delete ui;
}

void EmployeesPage::SetEmployeesCards(QSqlQuery query){

    QLayout* layout = ui->gridLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }

    if(!query.exec()){
        query.prepare("SELECT *FROM Employees;");
        if(!query.exec()){
            qDebug() << "SetEmployeesCards query falt!" << query.lastError();
            return;
        }
    }

    int rows = 0;
    int cols = 0;

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("border:none;");

    QWidget* mainWidget = new QWidget;
    QGridLayout* innerGridLayout = new QGridLayout(mainWidget);

    for(int i = 0; i < 220; i++){
        QPushButton* card = new QPushButton;
        card->setMinimumSize(290, 120);
        card->setMaximumSize(290, 120);
        card->setStyleSheet(
            "QPushButton{"
              "background-color:rgba(167, 175, 183, 1);"
            "}"
            "QPushButton:hover{"
               "background-color:rgba(220, 220, 220, 1);"
            "}");

        QLabel* image = new QLabel(card);
        image->setPixmap(QPixmap("./img/employees.png"));
        image->setGeometry(20, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

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
