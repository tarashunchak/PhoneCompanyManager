#include "employeespage.h"
#include "ui_employeespage.h"

#include "databasemanager.h"
#include <QSqlError>
#include <QScrollArea>
#include "buttonsstylemanager.h"

EmployeesPage::EmployeesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesPage)
    , db(&DatabaseManager::instance().getDatabase())
{
    ui->setupUi(this);
    ButtonsStyleManager::SetLeftMenuIcons({
        ui->dashboard_btn,
        ui->customers_btn,
        ui->employees_btn,
        ui->tariffs_btn,
        ui->requests_btn
    });

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
        image->setPixmap(QPixmap("./img/employees.png"));
        image->setGeometry(20, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

        QLabel* full_name = new QLabel(query.value("full_name").toString(), card);
        full_name->setGeometry(85, 35, 250, 20);
        full_name->setStyleSheet("background-color:transparent;color:white;font-size:18px;");

        QLabel* empl_id = new QLabel("ID:" + query.value("id").toString(), card);
        
        empl_id->setGeometry(85, 60, 100, 20);
        empl_id->setStyleSheet("background-color:transparent;color:white;font-size:16px;");

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
