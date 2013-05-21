#ifndef PRINTDELEGATE_H
#define PRINTDELEGATE_H

#include <QItemDelegate>

class PrintDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	explicit PrintDelegate(QObject *parent = 0);

protected:
	void paint(QPainter *painter,
			   const QStyleOptionViewItem &option,
			   const QModelIndex &index) const;
signals:
	
public slots:

private:
};

#endif // PRINTDELEGATE_H
