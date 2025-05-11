#include "taskspage.h"
#include "ui_taskspage.h"

TasksPage::TasksPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TasksPage)
{
    ui->setupUi(this);
}

TasksPage::~TasksPage()
{
    delete ui;
}
