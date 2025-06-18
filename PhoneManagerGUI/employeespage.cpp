#include "includes/employeespage.h"
#include "ui_employeespage.h"
#include <QSqlError>
#include <QScrollArea>
#include <QLabel>
#include "includes/currentuser.h"
#include "includes/databasemanager.h"
#include <QSqlRecord>

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
    ui->scrollAreaWidgetContents->setLayout(ui->gridLayout);

    ui->gridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->gridLayout->setHorizontalSpacing(34);
    ui->gridLayout->setVerticalSpacing(40);
    ui->gridLayout->setContentsMargins(40, 40, 0, 0);
    ui->scrollArea->setWidgetResizable(true);
}

EmployeesPage::~EmployeesPage()
{
    delete ui;
}

void EmployeesPage::SetConnections(){
    connect(ui->lineEdit, &QLineEdit::editingFinished
            , this, &EmployeesPage::FindEmployeesByName);
    connect(ui->add_empl_btn, &QPushButton::clicked, insert_employee_dialog
            , &InsertEmployeeDialog::exec);
    connect(ui->add_empl_btn, &QPushButton::clicked, insert_employee_dialog
            , &InsertEmployeeDialog::updateComboBoxData);
}

void EmployeesPage::setCurrentUser()const{
    QSqlQuery query(QSqlDatabase::database("remote"));
    query.prepare("SELECT p.position_name AS POS_NAME "
                  "FROM users "
                  "JOIN employees e ON e.id = users.empl_id "
                  "JOIN positions p ON p.id = e.position_id "
                  "WHERE users.id = :id;");

    query.bindValue(":id", CurrentUser::getCurrentUserID());

    if(!query.exec() || !query.next())
        qDebug() << "EmployeesPage::setCurrentUser() query fault!" << query.lastError();
    else
        ui->add_empl_btn->setVisible(query.value("POS_NAME").toString() == "Administrator");
}

void EmployeesPage::FindEmployeesByName(){
    auto query = DatabaseManager::findByName(TABLE::EMPLOYEES, ui->lineEdit->text());
    SetEmployeesCards(std::move(query));
}

namespace {
    constexpr uint CARD_MAX_WIDTH = 290;
    constexpr uint CARD_MAX_HEIGHT = 120;
    constexpr uint CARDS_PER_ROW = 5;

    QPushButton* createEmployeeCard(const QSqlRecord& record
                                     , const QPixmap& pixmap
                                     , QWidget* parent = nullptr)
    {
        QPushButton* card = new QPushButton{parent};
        card->setMinimumSize({CARD_MAX_WIDTH, CARD_MAX_HEIGHT});
        card->setMaximumSize({CARD_MAX_WIDTH, CARD_MAX_HEIGHT});
        card->setStyleSheet(
            "QPushButton{"
            "	font-family:Lato, Arial, Consolas;"
            "	border-radius:8px;"
            "	background-color:#434C70;"
            "}"
            "QPushButton:hover{"
            "	background-color:#6C769A;"
            "}");
        QLabel* image = new QLabel(card);
        image->setPixmap(pixmap);
        image->setGeometry(20, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

        QLabel* full_name = new QLabel(record.value("first_name").toString()
                                           + " " + record.value("last_name").toString(), card);
        full_name->setGeometry(85, 35, 250, 20);
        full_name->setStyleSheet("background-color:transparent;"
                                 "color:white;"
                                 "font-size:18px;");

        QLabel* empl_id = new QLabel("ID:" + record.value("id").toString(), card);

        empl_id->setGeometry(85, 60, 100, 20);
        empl_id->setStyleSheet("background-color:transparent;"
                               "color:white;"
                               "font-size:16px;");
        return card;
    }
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
    if(!query.isActive()){
        query.prepare("SELECT * FROM employees "
                      "WHERE is_visible = true;");
        if(!query.exec()){
            qDebug() << "SetEmployeesCards query fault!" << query.lastError();
            return;
        }
    }
    uint rows = 0;
    uint cols = 0;

    while(query.next()){
        auto card = createEmployeeCard(query.record(), pixmap, this);

        ui->gridLayout->addWidget(card, rows, cols);

        cols++;
        if(cols >= CARDS_PER_ROW){
            cols = 0;
            rows++;
        }
        const uint empl_id = query.value("id").toUInt();
        connect(card, &QPushButton::clicked, this, [this, empl_id](){emit employee_selected(empl_id);});
    }
    query.clear();
}
