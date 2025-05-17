#ifndef TASKSPAGE_H
#define TASKSPAGE_H

#include <QWidget>

namespace Ui {
class TasksPage;
}

class TasksPage : public QWidget
{
    Q_OBJECT

public:
    explicit TasksPage(QWidget *parent = nullptr);
    ~TasksPage();

private:
    Ui::TasksPage *ui;
};

#endif // TASKSPAGE_H
