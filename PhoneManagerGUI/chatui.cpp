#include "includes/chatui.h"
#include "ui_chatui.h"

ChatUI::ChatUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatUI)
{
    ui->setupUi(this);
    ui->send_btn->setIcon(QIcon{"./img/paper-plane.svg"});
}

ChatUI::~ChatUI()
{
    delete ui;
}
