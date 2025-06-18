#include "includes/pushbuttondelegate.h"
#include <QPushButton>
#include <QApplication>
#include <QMouseEvent>
#include <QSqlQuery>
#include "includes/currentuser.h"
#include <QSqlError>
#include <QPainter>

PushButtonDelegate::PushButtonDelegate() {}

PushButtonDelegate::PushButtonDelegate(QObject* parent)
    : QStyledItemDelegate(parent) {}


void PushButtonDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,
                               const QModelIndex& index) const
{
    QRect rect = option.rect;

    QColor fillcolor{"#3A3A3A"};
    QColor borderColor = QColor("#888888");
    QColor textColor = QColor("#FFFFFF");

    painter->setBrush(fillcolor);
    painter->setPen(borderColor);
    painter->drawRect(rect.adjusted(1, 1, -1, -1));

    painter->setPen(textColor);
    painter->drawText(rect, Qt::AlignCenter, "Take");

    painter->save();
}

bool PushButtonDelegate::editorEvent(QEvent* event, QAbstractItemModel* model,
                                     const QStyleOptionViewItem& option, const QModelIndex& index)
{
    if(event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (option.rect.contains(mouseEvent->pos())) {
            QSqlQuery query(QSqlDatabase::database("remote"));
            query.prepare("UPDATE requests SET status = 'In Progress', assigned_to_id = :empl_id WHERE id = :id;");
            query.bindValue(":empl_id", CurrentUser::getCurrentEmployeeID());
            query.bindValue(":id", model->data(model->index(index.row(), 0)));
            if(!query.exec())
                qDebug() << "Update requests assigned_to_id query fault: " << query.lastError().text();
            else
                emit successfully_updated();
        }
    }
    return true;
}
