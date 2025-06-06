#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QStyledItemDelegate>

class ComboBoxDelegate : public QStyledItemDelegate
{
public:
    [[nodiscard]] ComboBoxDelegate(QObject* parent = nullptr);
    [[nodiscard]] explicit ComboBoxDelegate(const QStringList&, QObject* parent = nullptr);

private:
    [[nodiscard]] QWidget* createEditor(QWidget*, const QStyleOptionViewItem&,
            const QModelIndex&)const override;
    void setEditorData(QWidget* editor, const QModelIndex& index) const override;
    void setModelData(QWidget* editor,
            QAbstractItemModel* model,
            const QModelIndex& index) const override;
    void updateEditorGeometry(QWidget* editor,
            const QStyleOptionViewItem& option,
            const QModelIndex& index) const override;
    QStringList str_list;
};

#endif // COMBOBOXDELEGATE_H
