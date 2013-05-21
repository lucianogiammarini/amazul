#include "sortfilterproxymodel.h"
#include <QDebug>
#include <QStringList>

SortFilterProxyModel::SortFilterProxyModel(QObject * parent) :
	QSortFilterProxyModel(parent)
{
}

bool SortFilterProxyModel::lessThan(const QModelIndex &left,
									const QModelIndex &right) const
{
	if (sortColumn() != 7)
		return QSortFilterProxyModel::lessThan(left, right);

	int l = left.data(Qt::EditRole).toInt();
	int r = right.data(Qt::EditRole).toInt();
	return l<r;
}

bool SortFilterProxyModel::filterAcceptsRow(int sourceRow,
		const QModelIndex &sourceParent) const
{
	QModelIndex indexLastName = sourceModel()->index(sourceRow, 1, sourceParent);
	QModelIndex indexName = sourceModel()->index(sourceRow, 2, sourceParent);

	QString lastName = sourceModel()->data(indexLastName).toString();
	QString name = sourceModel()->data(indexName).toString();

	QStringList filter;
	filter = filterRegExp().pattern().split(" ", QString::SkipEmptyParts);

	bool result = true;
	for (int i = 0; i < filter.size(); ++i)
		result &= (lastName.contains(filter.at(i), Qt::CaseInsensitive) ||
				   name.contains(filter.at(i), Qt::CaseInsensitive));

	return result;
}
