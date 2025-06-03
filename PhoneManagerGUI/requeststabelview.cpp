#include "requeststabelview.h"
#include <QMouseEvent>

void RequestsTabelView::mouseMoveEvent(QMouseEvent* event){
    QModelIndex index = indexAt(event->pos());
    if(index.isValid()){
        viewport()->update(visualRect(index));
    }
    //QTableView::mouseMoveEvent(event);
}
