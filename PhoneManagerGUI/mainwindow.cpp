#include "includes/mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QScreen>
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mainWidget(new MainWidget{})
{
    ui->setupUi(this);

    this->setWindowTitle("Neo Com");
    this->setWindowIcon(QIcon("./img/logo.png"));
    //this->setMinimumSize(1920, 1080);
    //this->setMaximumSize(1920, 1080);
    //sWidget = mainWidget->getSWidget();
    setCentralWidget(mainWidget);
    setStatusBar(nullptr);
    //nManager = new NavigationManager(sWidget, this);

    centralWidget()->setLayout(new QGridLayout{});

    qApp->setStyleSheet("QPushButton:focus { outline: none; border: none; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWidget* MainWindow::getMainWidget()const{
    return mainWidget;
}
