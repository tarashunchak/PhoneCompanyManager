#include "includes/tariffspage.h"
#include "ui_tariffspage.h"
#include "includes/currentuser.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QScrollArea>
#include "includes/tariffcard.h"

TariffsPage::TariffsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffsPage)
    , tariff_edit_widget(new TariffEditWidget{})
{
    ui->setupUi(this);
    setConnections();
    setTariffsCards();
    tariff_edit_widget->setWindowModality(Qt::WindowModality::WindowModal);
}

TariffsPage::~TariffsPage()
{
    delete ui;
}

void TariffsPage::setCurrentUser(){
    QSqlQuery query;
    query.prepare("SELECT p.position_name AS position "
                  "FROM employees e "
                  "JOIN positions p ON p.id = e.position_id "
                  "WHERE e.id = :empl_id;");
    const uint empl_id = CurrentUser::getCurrentEmployeeID();
    query.bindValue(":empl_id", empl_id);
    if(query.exec() && query.next()){
        bool is_admin = query.value("position").toString() == "Administrator";
        ui->add_tariff_btn->setVisible(is_admin);
        TariffCard::setEditable(is_admin);
    }else{
        qDebug() << "setCurrentUser Dashboard Page fault!" << query.lastError();
        return;
    }
}

void TariffsPage::setConnections()const{
    connect(ui->lineEdit, &QLineEdit::textChanged
            , this, &TariffsPage::FindTariffInDB);
    connect(this, &TariffsPage::on_add_tariff_btn_clicked
            , &insertT_Dialog, &InsertTariffDialog::exec);
}

void TariffsPage::setTariffsCards(QSqlQuery query){
    QLayout* layout = ui->gridLayout;
    if(layout){
        while(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }

    if(!query.exec()){
        query.prepare("SELECT * FROM tariffs;");
        if(!query.exec())
            qDebug() << "TariffsPage::setTariffsCards(QSqlQuery) query fault: " << query.lastError();
    }

    uint8_t cols = 0;
    uint8_t rows = 0;
    uint32_t tariff_id{};
    while(query.next()){
        tariff_id = query.value("id").toUInt();
        TariffCard* card = new TariffCard();
        card->setMinimumSize(300, 460);
        card->setTariffInfoFromQuery(query.record());

        ui->gridLayout->addWidget(card, rows, cols);
        cols++;
        if(cols % 4 == 0){
            cols = 0;
            rows++;
        }
        connect(card, &TariffCard::on_edit_btn_clicked, this, [this, tariff_id](){
            tariff_edit_widget->setTariffInformation(tariff_id);
            tariff_edit_widget->show();
        });
    }
    ui->gridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->gridLayout->setHorizontalSpacing(100);
    ui->gridLayout->setVerticalSpacing(50);
    ui->gridLayout->setContentsMargins(84, 40, 0, 0);

    ui->scrollAreaWidgetContents->setLayout(ui->gridLayout);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
}

void TariffsPage::FindTariffInDB(){
    QSqlQuery query;
    query.prepare("SELECT * FROM tariffs "
                  "WHERE LOWER(tariff_name) LIKE LOWER(:name) OR id = :id;");
    QString text{ui->lineEdit->text()};
    query.bindValue(":name", text + "%");
    query.bindValue(":id", text);

    setTariffsCards(std::move(query));
}
