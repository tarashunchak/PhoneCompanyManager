#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Neo Com");
    this->setWindowIcon(QIcon("./img/logo.png"));
    this->setMinimumSize(QSize(1920, 1080));
    this->setMaximumSize(QSize(1920, 1080));

    sWidget = new QStackedWidget(this);
    setCentralWidget(sWidget);

    bManager = new ButtonsLogicManager(sWidget, this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
