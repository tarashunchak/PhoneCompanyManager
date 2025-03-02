#include "tariffspage.h"
#include "ui_tariffspage.h"

#include "buttonsstylemanager.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QScrollArea>
#include "tariffcard.h"

TariffsPage::TariffsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffsPage)
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
    SetConnections();
    SetTariffsCards(QSqlQuery());

}

TariffsPage::~TariffsPage()
{
    delete ui;
}

void TariffsPage::SetConnections()const{
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &TariffsPage::FindTariffInDB);
}

void TariffsPage::SetTariffsCards(QSqlQuery query){
    if(!query.exec()){
        query.prepare("SELECT *FROM Tariffs;");
        if(query.exec()){
            qDebug() << "SetTariffsCards query fault!" << query.lastError();
        }
    }

    QLayout* layout = ui->gridLayout;
    if(layout){
        if(QLayoutItem* item = layout->takeAt(0)){
            delete item->widget();
            delete item;
        }
    }

    int cols = 0;
    int rows = 0;

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("border:none;");

    QWidget* mainWidget = new QWidget();
    QGridLayout* innerGridLayout = new QGridLayout(mainWidget);
    while(query.next()){
        TariffCard* card = new TariffCard();
        card->setMinimumSize(296, 510);
        card->setTariffNameLabelText(query.value("tariff_name").toString());

        innerGridLayout->addWidget(card, rows, cols);
        qDebug() << card->styleSheet();
        cols++;
        if(cols % 4 == 0){
            cols = 0;
            rows++;
        }
    }
    innerGridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    innerGridLayout->setHorizontalSpacing(100);
    innerGridLayout->setVerticalSpacing(50);
    innerGridLayout->setContentsMargins(84, 70, 0, 0);

    mainWidget->setLayout(innerGridLayout);

    scrollArea->setWidget(mainWidget);
    ui->gridLayout->addWidget(scrollArea);

}

void TariffsPage::FindTariffInDB(){
    QSqlQuery query;
    query.prepare("SELECT *FROM Tariffs WHERE tariff_name LIKE :name OR id LIKE :id;");
    query.bindValue(":name", ui->lineEdit->text() + "%");
    query.bindValue(":id", ui->lineEdit->text() + "%");
    SetTariffsCards(std::move(query));
}
