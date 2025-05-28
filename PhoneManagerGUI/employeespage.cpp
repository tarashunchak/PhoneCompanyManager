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
    ui->scrollAreaWidgetContents->setLayout(ui->gridLayout);

    ui->filter_pic->setPixmap(QPixmap{"./img/filter.png"});
    ui->close_open_filter_btn->setIcon(QIcon{"./img/filter.svg"});
    ui->close_open_filter_btn->setIconSize(QSize{24, 24});
    filter_animation = new QPropertyAnimation{ui->filter_widget, "pos"};
    filter_animation->setDuration(200);

    ui->gridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->gridLayout->setHorizontalSpacing(34);
    ui->gridLayout->setVerticalSpacing(40);
    ui->gridLayout->setContentsMargins(40, 40, 0, 0);
    ui->scrollArea->setWidgetResizable(true);

    ui->sort_by_comboBox->clear();
    ui->sort_by_comboBox->addItem("By date(newest)", " ORDER BY date DESC;");
    ui->sort_by_comboBox->addItem("By name(a-z)", " ORDER BY first_name ASC;");
    ui->sort_by_comboBox->addItem("By name(z-a)", " ORDER BY first_name DESC;");
    ui->sort_by_comboBox->addItem("By date(oldest)", " ORDER BY date ASC;");
}

EmployeesPage::~EmployeesPage()
{
    delete ui;
}

void EmployeesPage::SetConnections(){
    connect(ui->lineEdit, &QLineEdit::textEdited
            , this, &EmployeesPage::FindEmployeesByName);
    connect(ui->add_empl_btn, &QPushButton::clicked, insert_employee_dialog
            , &InsertEmployeeDialog::exec);
    connect(ui->add_empl_btn, &QPushButton::clicked, insert_employee_dialog
            , &InsertEmployeeDialog::updateComboBoxData);
    connect(ui->close_open_filter_btn, &QPushButton::clicked
            , this, &EmployeesPage::open_close_filter_widget);
    connect(ui->apply_filter_btn, &QPushButton::clicked, this, &EmployeesPage::apply_filters);
}

void EmployeesPage::setCurrentUser()const{
    QSqlQuery query;
    query.prepare("SELECT p.position_name AS POS_NAME "
                  "FROM users "
                  "JOIN employees e ON e.id = users.empl_id "
                  "JOIN positions p ON p.id = e.position_id "
                  "WHERE users.id = :id");

    query.bindValue(":id", CurrentUser::getCurrentUserID());

    if(!query.exec() || !query.next())
        qDebug() << "EmployeesPage::setCurrentUser() query fault!" << query.lastError();
    else
        ui->add_empl_btn->setVisible(query.value("POS_NAME").toString() == "Administrator");
}

void EmployeesPage::FindEmployeesByName(){
    static bool ok;
    const uint input = ui->lineEdit->text().toUInt(&ok);
    QSqlQuery query;
    query.prepare("SELECT * FROM employees "
                  "WHERE LOWER(first_name) LIKE LOWER(:name) "
                  "OR LOWER(last_name) LIKE LOWER(:name) "
                  "OR LOWER(first_name || ' ' || last_name) LIKE LOWER(:name) "
                          + QString{ok ? "OR id = :id;" : ";"});

    query.bindValue(":name", ui->lineEdit->text() + "%");
    if(ok)
        query.bindValue(":id", input);
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
        query.prepare("SELECT * FROM employees;");
        if(!query.exec()){
            qDebug() << "SetEmployeesCards query fault!" << query.lastError();
            return;
        }
    }
    int rows = 0;
    int cols = 0;

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
}
