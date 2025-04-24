#include "chatui.h"
#include "ui_chatui.h"

ChatUI::ChatUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatUI)
{
    ui->setupUi(this);
}

ChatUI::~ChatUI()
{
    delete ui;
}
