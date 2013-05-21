#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QAbstractTableModel>

class CalendarModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit CalendarModel(QObject *parent = 0);
	int getDay(const QModelIndex &index) const;

protected:
	int rowCount(const QModelIndex &) const { return 5; }
	int columnCount(const QModelIndex &) const { return 7; }
	QVariant data(const QModelIndex &index, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;

signals:

public slots:
};

#endif // CALENDARMODEL_H
