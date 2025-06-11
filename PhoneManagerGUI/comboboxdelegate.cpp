#include "includes/comboboxdelegate.h"
#include <QComboBox>

ComboBoxDelegate::ComboBoxDelegate(QObject* parent) : QStyledItemDelegate(parent){}

ComboBoxDelegate::ComboBoxDelegate(const QStringList& str_list, QObject* parent)
        : QStyledItemDelegate(parent)
        , str_list(std::move(str_list)){}

QWidget* ComboBoxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem&,
        const QModelIndex&)const
{
    QComboBox* combo_box = new QComboBox{parent};
    combo_box->setStyleSheet("background-color:gray;color:black;");
    combo_box->addItems(str_list);
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
