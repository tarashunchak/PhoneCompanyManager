#include "includes/mainwindow.h"

#include <QApplication>
#include "includes/databasemanager.h"
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseManager::instance();

    MainWindow w;
    w.showFullScreen();
    return a.exec();
}
