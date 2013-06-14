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
    drawBackground(painter, option, index);
    drawFocus(painter, option, option.rect);

	painter->save();

	QPixmap pixmap;
	bool value = index.model()->data(index).toBool();
	if (value)
		pixmap = QPixmap(":/icons/ok.png");
	else
		pixmap = QPixmap(":/icons/reject.png");
	QRect rect = pixmap.rect();
	rect.moveCenter(option.rect.center());
	painter->drawPixmap(rect, pixmap);

	painter->restore();
}
