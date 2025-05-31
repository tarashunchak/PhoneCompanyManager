#ifndef TASKSPAGE_H
#define TASKSPAGE_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class TasksPage;
}

class TasksPage : public QWidget
{
    Q_OBJECT

public:
    explicit TasksPage(QWidget *parent = nullptr);
    ~TasksPage();
    void showAssignedToMe();
    void showCreatedByMe();

private:
    Ui::TasksPage *ui;
    QSqlQueryModel* qmodel;
};

#endif // TASKSPAGE_H
