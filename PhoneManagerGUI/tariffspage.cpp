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

    SetTariffsCards(QSqlQuery());

}

TariffsPage::~TariffsPage()
{
    delete ui;
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

    QWidget* mainWidget = new QWidget;
    QGridLayout* innerGridLayout = new QGridLayout(mainWidget);
    while(query.next()){
        TariffCard* card = new TariffCard();
        card->setMinimumSize(300, 360);
        card->setStyleSheet("background-color:rgba(49, 49, 49, 1);");

        innerGridLayout->addWidget(card, rows, cols);

        cols++;
        if(cols % 4 == 0){
            cols = 0;
            rows++;
        }
    }
    innerGridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    innerGridLayout->setHorizontalSpacing(60);
    innerGridLayout->setVerticalSpacing(50);
    innerGridLayout->setContentsMargins(60, 70, 0, 0);

    mainWidget->setLayout(innerGridLayout);
    scrollArea->setWidget(mainWidget);
    ui->gridLayout->addWidget(scrollArea);

}
