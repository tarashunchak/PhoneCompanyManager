#include "includes/employeespage.h"
#include "ui_employeespage.h"
#include <QSqlError>
#include <QScrollArea>
#include <QLabel>
#include "includes/currentuser.h"

EmployeesPage::EmployeesPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeesPage)
    , insert_employee_dialog(new InsertEmployeeDialog{})
{
    ui->setupUi(this);
    insert_employee_dialog->close();
    insert_employee_dialog->setModal(true);
    SetConnections();
    SetEmployeesCards();
}

EmployeesPage::~EmployeesPage()
{
    delete ui;
}

void EmployeesPage::SetConnections(){
    connect(ui->lineEdit, &QLineEdit::textEdited, this, &EmployeesPage::FindEmployeesByName);
    connect(ui->add_empl_btn, &QPushButton::clicked, insert_employee_dialog, &InsertEmployeeDialog::exec);
    connect(ui->add_empl_btn, &QPushButton::clicked, insert_employee_dialog, &InsertEmployeeDialog::updateComboBoxData);
}

void EmployeesPage::setCurrentUser()const{
    QSqlQuery query;
    query.prepare("SELECT positions.position_name AS POS_NAME "
                  "FROM users "
                  "JOIN employees ON employees.id = users.empl_id "
                  "JOIN positions ON positions.id = employees.position_id "
                  "WHERE users.id = :id");

    query.bindValue(":id", CurrentUser::getCurrentUserID());

    if(!query.exec() || !query.next())
        qDebug() << "EmployeesPage::setCurrentUser() query fault!" << query.lastError();
    else
        ui->add_empl_btn->setVisible(query.value("POS_NAME").toString() == "Administrator");
}

void EmployeesPage::FindEmployeesByName(){
    QSqlQuery query;
    query.prepare("SELECT * FROM employees WHERE first_name LIKE LOWER(:name) "
                  "OR last_name LIKE LOWER(:name) OR id = :id");
    query.bindValue(":name", ui->lineEdit->text() + "%");
    query.bindValue(":id", ui->lineEdit->text());
    SetEmployeesCards(std::move(query));
}

void EmployeesPage::SetEmployeesCards(QSqlQuery query){
    static QPixmap pixmap{"./img/employees.png"};
    QLayout* layout = ui->gridLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }
    if(!query.exec()){
        query.prepare("SELECT *FROM employees;");
        if(!query.exec()){
            qDebug() << "SetEmployeesCards query fault!" << query.lastError();
            return;
        }
    }
    int rows = 0;
    int cols = 0;


    //QWidget* mainWidget = new QWidget{};
    //QGridLayout* ui->gridLayout = new QGridLayout(mainWidget);

    while(query.next()){
        QPushButton* card = new QPushButton;
        card->setMinimumSize(290, 120);
        card->setMaximumSize(290, 120);
        card->setStyleSheet(
            "QPushButton{"
            "	background-color:rgba(51, 51, 51, 1);"
            "	border-radius:8px;"
            "}"
            "QPushButton:hover{"
            "	background-color:rgba(71, 71, 71, 1);"
            "}"
        );

        QLabel* image = new QLabel(card);
        image->setPixmap(pixmap);
        image->setGeometry(20, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

        QLabel* full_name = new QLabel(query.value("first_name").toString()
                                           + " " + query.value("last_name").toString(), card);
        full_name->setGeometry(85, 35, 250, 20);
        full_name->setStyleSheet("background-color:transparent;"
                                 "color:white;"
                                 "font-size:18px;");

        QLabel* empl_id = new QLabel("ID:" + query.value("id").toString(), card);
        
        empl_id->setGeometry(85, 60, 100, 20);
        empl_id->setStyleSheet("background-color:transparent;"
                               "color:white;"
                               "font-size:16px;");

        ui->gridLayout->addWidget(card, rows, cols);

        cols++;
        if(cols % 5 == 0){
            cols = 0;
            rows++;
        }
    }

    ui->gridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->gridLayout->setHorizontalSpacing(34);
    ui->gridLayout->setVerticalSpacing(40);
    ui->gridLayout->setContentsMargins(40, 40, 0, 0);
    ui->scrollArea->setWidgetResizable(true);

    ui->scrollAreaWidgetContents->setLayout(ui->gridLayout);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    //ui->gridLayout->addWidget(ui->scrollArea);
}
