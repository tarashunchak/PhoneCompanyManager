#include "includes/customerspage.h"
#include "ui_customerspage.h"
#include <QSqlError>
#include <QScrollArea>
#include <QPushButton>
#include <QLabel>
#include <QListView>
#include "includes/databasemanager.h"
#include <QSqlRecord>

CustomersPage::CustomersPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersPage)
    , insert_customer_dialog(new InsertCustomerDialog{})
{
    ui->setupUi(this);

    SetCustomersCards();
    SetConnections();

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

    ui->sort_by_comboBox->clear();
    ui->sort_by_comboBox->addItem("By date(newest)", " ORDER BY date DESC;");
    ui->sort_by_comboBox->addItem("By name(a-z)", " ORDER BY first_name ASC;");
    ui->sort_by_comboBox->addItem("By name(z-a)", " ORDER BY first_name DESC;");
    ui->sort_by_comboBox->addItem("By date(oldest)", " ORDER BY date ASC;");
}

CustomersPage::~CustomersPage()
{
    delete ui;
}

namespace{
    const QString left{
        "QPushButton{"
        "border-top-right-radius:0px;"
        "border-bottom-right-radius:0px;"
        "border-top-left-radius:4px;"
        "border-bottom-left-radius:4px;"
    };
    const QString right{
        "QPushButton{"
        "border-top-left-radius:0px;"
        "border-bottom-left-radius:0px;"
        "border-top-right-radius:4px;"
        "border-bottom-right-radius:4px;"
    };
    const QString center{
        "QPushButton{"
        "border-radius:0px;"
    };
    const QString both{
        "font-size:18px;"
        "border:1px solid rgb(255, 255, 255);"
        "height:30px;"
        "}"
    };
    const QString inactive{
        "QPushButton:hover{"
        "background-color:rgba(200, 200, 200, 0.3);"
        "}"
    };
    const QString active_right{right + "background-color:white;color:black;" + both};
    const QString inactive_right{right + "background-color:transparent;color:white;" + both + inactive};
    const QString active_left{left + "background-color:white;color:black;" + both};
    const QString inactive_left{left + "background-color:transparent;color:white;" + both + inactive};
    const QString active_center{center + "background-color:white;color:black;" + both};
    const QString inactive_center{center + "background-color:transparent;color:white;" + both + inactive};
}

void CustomersPage::SetConnections(){
    connect(ui->lineEdit, &QLineEdit::textEdited
            , this, &CustomersPage::FindCustomersByName);
    connect(ui->add_cust_btn, &QPushButton::clicked
            , insert_customer_dialog, &QDialog::exec);
    connect(ui->add_cust_btn, &QPushButton::clicked, insert_customer_dialog
            , &InsertCustomerDialog::updateComboBoxData);
    connect(ui->close_open_filter_btn, &QPushButton::clicked
            , this, &CustomersPage::open_close_filter_widget);
    connect(ui->apply_filter_btn, &QPushButton::clicked, this, &CustomersPage::apply_filters);
    connect(ui->active_btn, &QPushButton::clicked, this, [&, this](){
        ui->active_btn->setStyleSheet(active_left);
        ui->inactive_btn->setStyleSheet(inactive_right);
        ui->all_by_activity_btn->setStyleSheet(inactive_center);
        ui->active_btn->setProperty("status", true);
        ui->all_by_activity_btn->setProperty("status", false);
    });
    connect(ui->inactive_btn, &QPushButton::clicked, this, [&, this](){
        ui->inactive_btn->setStyleSheet(active_right);
        ui->active_btn->setStyleSheet(inactive_left);
        ui->all_by_activity_btn->setStyleSheet(inactive_center);
        ui->active_btn->setProperty("status", false);
        ui->all_by_activity_btn->setProperty("status", false);
    });
    connect(ui->all_by_activity_btn, &QPushButton::clicked, this, [&, this](){
        ui->inactive_btn->setStyleSheet(inactive_right);
        ui->active_btn->setStyleSheet(inactive_left);
        ui->all_by_activity_btn->setStyleSheet(active_center);
        ui->all_by_activity_btn->setProperty("status", true);
    });
}

namespace {
    constexpr uint CARD_MAX_WIDTH = 290;
    constexpr uint CARD_MAX_HEIGHT = 120;
    constexpr uint CARDS_PER_ROW = 5;

    QPushButton* createCustomerCard(const QSqlRecord& record
                                     , const QPixmap& pixmap
                                     , QWidget* parent = nullptr)
    {
        QPushButton* card = new QPushButton{parent};
        card->setMinimumSize(CARD_MAX_WIDTH, CARD_MAX_HEIGHT);
        card->setMaximumSize(CARD_MAX_WIDTH, CARD_MAX_HEIGHT);
        card->setProperty("id", record.value("id").toInt());
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
        image->setGeometry(16, 25, 50, 50);
        image->setStyleSheet("background-color:transparent;");

        QLabel* phone = new QLabel("Phone: " + record.value("phone").toString(), card);
        phone->setGeometry(80, 35, 200, 20);
        phone->setStyleSheet("background-color:transparent;color:white;font-size:18px;");

        QLabel* full_name = new QLabel(record.value("first_name").toString()
                                           + record.value("last_name").toString(), card);

        full_name->setGeometry(80, 60, 250, 20);
        full_name->setStyleSheet("background-color:transparent;color:white;font-size:14px;");

        return card;
    }
}

void CustomersPage::SetCustomersCards(QSqlQuery query){
    static QPixmap pixmap{"./img/customer.png"};
    QLayout* layout = ui->gridLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }
    if(!query.exec()){
        query.prepare("SELECT * FROM customers ORDER BY date DESC;");
        if(!query.exec()){
            qDebug() << "SetCustomersCards Query fault!!!: " << query.lastError();
            return;
        }
    }

    uint cols = 0;
    uint rows = 0;

    while(query.next()){
        auto card = createCustomerCard(query.record(), pixmap, this);
        ui->gridLayout->addWidget(card, rows, cols);
        connect(card, &QPushButton::clicked, this, [this, card](){
            ui->lineEdit->clear();
            emit customer_selected(card->property("id").toInt());
        });

        cols++;
        if(cols >= CARDS_PER_ROW){
            cols = 0;
            rows++;
        }
    }
}

void CustomersPage::FindCustomersByName(){
    auto query = DatabaseManager::findByName("customers", ui->lineEdit->text());
    SetCustomersCards(std::move(query));
}
