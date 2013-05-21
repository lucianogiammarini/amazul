#include "calendarmodel.h"

CalendarModel::CalendarModel(QObject *parent) :
	QAbstractTableModel(parent)
{
}

QVariant CalendarModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) return QVariant();

	if (role == Qt::DisplayRole){
		int day = getDay(index);
		if (day <= 31)
			return QVariant(day);
		else
			return QVariant();
	}

	if (role == Qt::TextAlignmentRole)
		return QVariant(Qt::AlignHCenter | Qt::AlignCenter);

	return QVariant();
}

Qt::ItemFlags CalendarModel::flags(const QModelIndex &index) const
{
	if (!index.isValid()) return 0;

	Qt::ItemFlags result = QAbstractItemModel::flags(index);
	int day = getDay(index);

	if (day <= 31)
		result = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	else
		result &= !Qt::ItemIsEnabled;

	return result;
}

int CalendarModel::getDay(const QModelIndex &index) const
{
	if (index.isValid())
		return index.row()*7 + index.column() + 1;
	else
		return 0;
}
