#ifndef STUDENTSTABLEMODEL_H
#define STUDENTSTABLEMODEL_H

#include <QSqlTableModel>
#include <QVariant>

class StudentsTableModel : public QSqlTableModel
{
	Q_OBJECT
public:
	explicit StudentsTableModel(QObject * parent = 0,
							QSqlDatabase db = QSqlDatabase());

	QString name(int row) const;
	QString address(int row) const;
	QString addressForMap(int row) const;
	QString birthday(int row) const;
	QString phone(int row, int i) const;
	QStringList phones(int row) const;
	bool print(int row) const;

	QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;

protected:
	Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // STUDENTSTABLEMODEL_H
