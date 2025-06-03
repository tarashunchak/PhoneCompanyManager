#ifndef PUSHBUTTONDELEGATE_H
#define PUSHBUTTONDELEGATE_H

#include <QStyledItemDelegate>

class PushButtonDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    PushButtonDelegate();
    explicit PushButtonDelegate(QObject* parent = nullptr);
    void paint(QPainter*,
               const QStyleOptionViewItem&, const QModelIndex&) const override;
    bool editorEvent(QEvent*, QAbstractItemModel*,
                 const QStyleOptionViewItem&, const QModelIndex&) override;
signals:
    void successfully_updated();

};

#endif // PUSHBUTTONDELEGATE_H
