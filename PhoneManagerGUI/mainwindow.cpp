#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QScreen>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Neo Com");
    this->setWindowIcon(QIcon("./img/logo.png"));
    this->setMinimumSize(1920, 1080);
    this->setMaximumSize(1920, 1080);

    sWidget = new QStackedWidget(this);
    setCentralWidget(sWidget);

    nManager = new NavigationManager(sWidget, this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
