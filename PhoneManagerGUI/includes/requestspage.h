#ifndef REQUESTSPAGE_H
#define REQUESTSPAGE_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class RequestsPage;
}

class RequestsPage : public QWidget
{
    Q_OBJECT

public:
    explicit RequestsPage(QWidget *parent = nullptr);
    ~RequestsPage();
    //void setTableView();
    void setCurrentUser();
    void showUnassignmentRequests();
    void showInProgressRequests()const;
    void showCompletedRequests()const;

signals:

private:
    void SetConnections()const;
    //void contextMenuEvent(QContextMenuEvent* event) override;

private:
    Ui::RequestsPage *ui;
    QSqlTableModel* qmodel;

};

#endif // REQUESTSPAGE_H
