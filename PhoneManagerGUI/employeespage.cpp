#include "includes/employeespage.h"
#include "ui_employeespage.h"

#include "includes/databasemanager.h"
#include <QSqlError>
#include <QScrollArea>
#include <QLabel>

EmployeesPage::EmployeesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesPage)
    , db(&DatabaseManager::instance().getDatabase())
{
    ui->setupUi(this);
    SetConnections();
    SetEmployeesCards();
}

EmployeesPage::~EmployeesPage()
{
    db = nullptr;
    delete ui;
}

void EmployeesPage::SetConnections(){
    connect(ui->lineEdit, &QLineEdit::textEdited, this, &EmployeesPage::FindEmployeesByName);
}

void EmployeesPage::FindEmployeesByName(){
    QSqlQuery query;
    query.prepare("SELECT *FROM Employees WHERE full_name LIKE :name OR id = :id;");
    query.bindValue(":name", ui->lineEdit->text() + "%");
    query.bindValue(":id", ui->lineEdit->text());
    SetEmployeesCards(std::move(query));
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
            qDebug() << "SetEmployeesCards query fault!" << query.lastError();
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
            "QPushButton{background-color:rgba(51, 51, 51, 1);}"
            "QPushButton:hover{background-color:rgba(71, 71, 71, 1);}"
        );

        QLabel* image = new QLabel(card);
        image->setPixmap(QPixmap("./img/employees.png"));
        image->setGeometry(20, 25, 50, 50);
        image->setStyleSheet("QPushButton{background-color:transparent;}");

        QLabel* full_name = new QLabel(query.value("full_name").toString(), card);
        full_name->setGeometry(85, 35, 250, 20);
        full_name->setStyleSheet("QPushButton{background-color:transparent;color:white;font-size:18px;}");

        QLabel* empl_id = new QLabel("ID:" + query.value("id").toString(), card);
        
        empl_id->setGeometry(85, 60, 100, 20);
        empl_id->setStyleSheet("QPushButton{background-color:transparent;color:white;font-size:16px;}");

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
