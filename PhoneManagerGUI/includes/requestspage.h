#ifndef REQUESTSPAGE_H
#define REQUESTSPAGE_H

#include <QWidget>
#include <QSqlTableModel>
#include "requeststabelview.h"

namespace Ui {
class RequestsPage;
}

class RequestsPage : public QWidget
{
    Q_OBJECT

public:
    explicit RequestsPage(QWidget *parent = nullptr);
    ~RequestsPage();
    void setCurrentUser();
    void showUnassignmentRequests();
    void showInProgressRequests();
    void showCompletedRequests();
    void showRequestsHistory();

signals:

private:
    void SetConnections();
    void setActiveButton(const uchar);

private:
    Ui::RequestsPage *ui;
    QSqlTableModel* qmodel;
    RequestsTabelView* req_tableView;
};

#endif // REQUESTSPAGE_H
