#include "includes/mainwindow.h"

#include <QApplication>
#include "includes/databasemanager.h"
#include "messagechecker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager::instance();

    MainWindow w;
    w.showFullScreen();
    //w.showMaximized();
    MessageChecker::getChecker();
    int result = a.exec();

    DatabaseManager::cleanUpConnections();

    return result;
}
