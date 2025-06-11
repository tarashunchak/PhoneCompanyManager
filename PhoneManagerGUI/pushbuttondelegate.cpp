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

    QColor fillcolor{(option.state & QStyle::State_MouseOver) ? QColor{"#ccee77"} : QColor{"#e0e0e0"}};
    QColor borderColor = QColor("#888888");
    QColor textColor = QColor("#000000");

    painter->setBrush(fillcolor);
    painter->setPen(borderColor);
    painter->drawRect(rect.adjusted(1, 1, -1, -1));

    painter->setPen(textColor);
    painter->drawText(rect, Qt::AlignCenter, "Take");

    painter->save();
    /*QStyleOptionButton button_option;
    button_option.text = "Take";
    button_option.rect = rect;
    button_option.state = QStyle::State_Enabled;

    if (option.state & QStyle::State_MouseOver){
        button_option.state |= QStyle::State_MouseOver;
    }*/

    //QApplication::style()->drawControl(QStyle::CE_PushButton, &button_option, painter);
}

bool PushButtonDelegate::editorEvent(QEvent* event, QAbstractItemModel* model,
                                     const QStyleOptionViewItem& option, const QModelIndex& index)
{
    if(event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (option.rect.contains(mouseEvent->pos())) {
            QSqlQuery query;
            query.prepare("UPDATE Requests SET status = 'In Progress', assigned_to_id = :empl_id WHERE id = :id;");
            query.bindValue(":empl_id", CurrentUser::getCurrentUserID());
            query.bindValue(":id", model->data(model->index(index.row(), 0)));
            if(!query.exec())
                qDebug() << "Update requests assigned_to_id query fault: " << query.lastError().text();
            else
                emit successfully_updated();
        }
    }
    return true;
}
