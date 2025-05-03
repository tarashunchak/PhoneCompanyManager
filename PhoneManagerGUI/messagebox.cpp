#include "messagebox.h"

MessageBox::MessageBox(QFrame* parent)
    : QFrame(parent)
    , message_text(new QLabel{})
    , message_date_time(new QLabel{})
    , verticalLayout(new QVBoxLayout{})
{
    message_text->setParent(this);
    message_text->setWordWrap(true);
    message_date_time->setParent(this);
    message_date_time->setWordWrap(true);
    message_date_time->setStyleSheet("margin-top:10px;");
    verticalLayout->addWidget(message_text);
    verticalLayout->addWidget(message_date_time);
    setMessageStyle();
    this->setMinimumHeight(30);
    this->setFixedWidth(300);
    message_text->setMaximumWidth(this->maximumWidth());
    message_date_time->setMaximumWidth(this->maximumWidth());
    this->setLayout(verticalLayout);
}

void MessageBox::SetMessageText(QString mtext){
    message_text->setText(std::move(mtext));
    message_text->adjustSize();
    this->adjustSize();
}

void MessageBox::SetMessageDateTime(QString mdate){
    message_date_time->setText(std::move(mdate));
    message_date_time->adjustSize();
    this->adjustSize();
}

void MessageBox::setMessageStyle(){
    this->setStyleSheet(
        "QFrame{"
        "font-family:Roboto;"
        "font-size:16px;"
        "color:white;"
        "background-color:rgb(85,85,85);"
        "text-align:right;"
        "}"
    );
}
