#include "mainwindow.h"

#include <QApplication>
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseManager::instance();
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
