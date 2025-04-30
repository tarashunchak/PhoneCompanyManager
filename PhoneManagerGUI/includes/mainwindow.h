#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwidget.h"
#include "navigationmanager.h"
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MainWidget* getMainWidget()const;

private:
    Ui::MainWindow *ui;
    //QStackedWidget* sWidget;
    MainWidget* mainWidget;

    //NavigationManager* nManager;

};
#endif // MAINWINDOW_H
