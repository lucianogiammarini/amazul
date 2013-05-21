#include "delegate.h"
#include <QVariant>
#include <QDebug>

Delegate::Delegate(QObject *parent) :
	QItemDelegate(parent)
{
}

void Delegate::setEditorData(QWidget *editor,
					   const QModelIndex &index) const
{
	if (editor->property("currentIndex").isValid()) {
		editor->setProperty("currentIndex", index.data(Qt::EditRole));
		return;
	} else if (editor->property("day").isValid()) {
		editor->setProperty("day", index.data(Qt::EditRole));
		return;
	}
	QItemDelegate::setEditorData(editor, index);
}

// if (!editor->metaObject()->userProperty().isValid()) {

void Delegate::setModelData(QWidget *editor,
						 QAbstractItemModel *model,
						 const QModelIndex &index) const
{
	QVariant value = editor->property("currentIndex");
	if (value.isValid()) {
		model->setData(index, value);
		return;
	}
	value = editor->property("day");
	if (value.isValid()) {
		model->setData(index, value);
		return;
	}
	QItemDelegate::setModelData(editor, model, index);
}
