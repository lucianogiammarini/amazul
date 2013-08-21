#include "studentstablemodel.h"
#include <QStringList>
#include <QDate>

QString capitalize(const QString &str)
{
	QString tmp = str;
	tmp[0] = str[0].toUpper();
	return tmp;
}

StudentsTableModel::StudentsTableModel(QObject * parent,
								   QSqlDatabase db) :
	QSqlTableModel(parent, db)
{
}

QVariant StudentsTableModel::data(const QModelIndex &idx, int role) const
{
	if (role == Qt::TextAlignmentRole &&
			(idx.column() == 4 || idx.column() == 6))
		return Qt::AlignCenter;

	if (idx.column() == 6 && role == Qt::DisplayRole)
	{
		int day = QSqlTableModel::data(idx).toInt();
		if (day == 0)
			return QVariant();

		return QVariant(day);
	}

	if (idx.column() == 7 && role == Qt::DisplayRole)
	{
		int month = QSqlTableModel::data(idx).toInt();
		if (month == 0)
			return QVariant();

		QString monthName = QDate::longMonthName(month);
		return capitalize(monthName);
	}

	return QSqlTableModel::data(idx, role);
}

Qt::ItemFlags StudentsTableModel::flags(const QModelIndex &index) const
{
	if (!index.isValid()) return 0;

	Qt::ItemFlags result = QSqlTableModel::flags(index);

    /*if (index.column() != 14)
		result = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	else
        result = Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;*/

	return result;
}

QString StudentsTableModel::name(int row) const
{
	QModelIndex nameIdx = index(row, 2);
	QModelIndex lastNameIdx = index(row, 1);
	QString name = QString(data(lastNameIdx).toString());
	name.append(", ");
	name.append(data(nameIdx).toString());
	return name;
}

QString StudentsTableModel::address(int row) const
{
	QModelIndex streetIdx = index(row, 3);
	QModelIndex numberIdx = index(row, 4);
	QModelIndex cityIdx = index(row, 5);
	QString address = QString(data(streetIdx).toString());
	QString number = data(numberIdx).toString();
	if (!number.isEmpty())
	{
		address.append(" ");
		address.append(number);
	}
	QString city = data(cityIdx).toString();
	if (!city.isEmpty())
	{
		address.append(" - ");
		address.append(city);
	}
	return address;
}

QString StudentsTableModel::addressForMap(int row) const
{
	QModelIndex streetIdx = index(row, 3);
	QModelIndex numberIdx = index(row, 4);
	QModelIndex cityIdx = index(row, 5);

	QString street = data(streetIdx).toString();
	QString number = data(numberIdx).toString();
	QString city = data(cityIdx).toString();
	if (city.isEmpty())
		city = QString("Laboulaye");

	QStringList address;
	address << street << number << city;

	return address.join("+");
}

QString StudentsTableModel::birthday(int row) const
{
	QModelIndex dayIdx = index(row, 6);
	QModelIndex monthIdx = index(row, 7);
	int day = data(dayIdx).toInt();
	int month = data(monthIdx, Qt::EditRole).toInt();
	if (day == 0 || month==0)
		return QString();

	QString birthday = QString::number(day);
	birthday.append(" de ");
	birthday.append(data(monthIdx).toString());
	return birthday;
}

QString StudentsTableModel::phone(int row, int i) const
{
	QModelIndex phoneIdx;
	QModelIndex labelIdx;
	switch(i)
	{
	case 1:
		labelIdx = index(row, 8);
		phoneIdx = index(row, 9);
		break;
	case 2:
		labelIdx = index(row, 10);
		phoneIdx = index(row, 11);
		break;
	case 3:
		labelIdx = index(row, 12);
		phoneIdx = index(row, 13);
		break;
	}

	QString phone = QString(data(phoneIdx).toString());
	QString label = data(labelIdx).toString();
	if (!phone.isEmpty() && !label.isEmpty())
		phone.prepend(QString("(%1) ").arg(label));

	return phone;
}

QStringList StudentsTableModel::phones(int row) const
{
	QStringList phoneList;
	for(int i=1; i<=3; i++)
	{
		QString phone = this->phone(row, i);
		if (!phone.isEmpty())
			phoneList.append(phone);
	}
	return phoneList;
}

bool StudentsTableModel::print(int row) const
{
	QModelIndex printIdx = index(row, 14);
	return data(printIdx).toBool();
}
