#ifndef REQUESTSTABELVIEW_H
#define REQUESTSTABELVIEW_H

#include <QTableView>

class RequestsTabelView : public QTableView
{
    Q_OBJECT
public:
    using QTableView::QTableView;

protected:
    void mouseMoveEvent(QMouseEvent*) override;

};

#endif // REQUESTSTABELVIEW_H
