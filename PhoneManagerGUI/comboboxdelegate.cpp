#include "includes/comboboxdelegate.h"
#include <QComboBox>

ComboBoxDelegate::ComboBoxDelegate() {}

ComboBoxDelegate::ComboBoxDelegate(QObject* parent)
        : QStyledItemDelegate(parent) {}

QWidget* ComboBoxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem&,
        const QModelIndex&)const
{
    QComboBox* combo_box = new QComboBox{parent};
    combo_box->addItems({"Confirm", "Reject"});
    return combo_box;
}

void ComboBoxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const{
    QComboBox* combo_box = qobject_cast<QComboBox*>(editor);
    if(combo_box){
        combo_box->setCurrentText(index.model()->data(index, Qt::EditRole).toString());
    }
}

void ComboBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model,
        const QModelIndex& index) const
{
    QComboBox* combo_box = qobject_cast<QComboBox*>(editor);
    if(combo_box){
        model->setData(index, combo_box->currentText(), Qt::EditRole);
    }
}

void ComboBoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
        const QModelIndex&) const
{
    editor->setGeometry(option.rect);
}
