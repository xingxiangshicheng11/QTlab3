#include "sexdelegate.h"

#include <QApplication>
#include <QComboBox>
#include <QPainter>
#include <QStyle>
#include <QStyleOptionViewItem>

SexDelegate::SexDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void SexDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const
{
    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);
    opt.text = (index.data().toInt() == 1) ? QStringLiteral("男")
                                           : QStringLiteral("女");

    const QWidget *widget = opt.widget;
    QStyle *style = widget ? widget->style() : QApplication::style();
    style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
}

QWidget *SexDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                   const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)
    QComboBox *editor = new QComboBox(parent);
    editor->addItem(QStringLiteral("男"), 1);
    editor->addItem(QStringLiteral("女"), 0);
    return editor;
}

void SexDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *combo = qobject_cast<QComboBox *>(editor);
    if (!combo)
        return;
    combo->setCurrentIndex(index.data().toInt() == 1 ? 0 : 1);
}

void SexDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                               const QModelIndex &index) const
{
    QComboBox *combo = qobject_cast<QComboBox *>(editor);
    if (!combo)
        return;
    model->setData(index, combo->currentData().toInt());
}
