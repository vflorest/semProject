#include "doublespinboxdelegate.h"
#include <QDoubleSpinBox>


DoubleSpinBoxDelegate::DoubleSpinBoxDelegate(QObject *parent)
    : QItemDelegate{parent}
{

}

QWidget *DoubleSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    auto doubleSpinBox = new QDoubleSpinBox(parent);
    doubleSpinBox->setMinimum(-99999999999.999);
    doubleSpinBox->setMaximum(+99999999999.999);
    return doubleSpinBox;
}

void DoubleSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto doubleSpinBox = (QDoubleSpinBox*) editor;
    doubleSpinBox->setValue(index.data().toDouble());
}

void DoubleSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto doubleSpinBox = (QDoubleSpinBox*) editor;
    model->setData(index, doubleSpinBox->value());
}

void DoubleSpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
