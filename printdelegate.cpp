#include "printdelegate.h"
#include <QPainter>

PrintDelegate::PrintDelegate(QObject *parent) :
	QItemDelegate(parent)
{
}

void PrintDelegate::paint(QPainter *painter,
		   const QStyleOptionViewItem &option,
		   const QModelIndex &index) const
{
	painter->save();

	QPixmap pixmap;
	bool value = index.model()->data(index).toBool();
	if (value)
		pixmap = QPixmap(":/images/images/Accept-small.png");
	else
		pixmap = QPixmap(":/images/images/Reject-small.png");
	QRect rect = pixmap.rect();
	rect.moveCenter(option.rect.center());
	painter->drawPixmap(rect, pixmap);

	painter->restore();
}
