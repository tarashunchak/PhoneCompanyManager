#include "includes/mainwindow.h"

#include <QApplication>
#include "includes/databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseManager::instance();

    MainWindow w;
    w.showFullScreen();
    qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));
    //w.showMaximized();
    return a.exec();
}
