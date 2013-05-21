#ifndef AMAZUL_H
#define AMAZUL_H

#include "lineedit.h"
#include "linefilter.h"
#include "calendarwidget.h"
#include "studentstableview.h"
#include "studentstablemodel.h"
#include "sortfilterproxymodel.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QDataWidgetMapper>

//class QDataWidgetMapper;
class QSortFilterProxyModel;
class QSqlTableModel;
class QItemSelectionModel;
class QState;
class QStateMachine;
class QWebView;

namespace Ui {
class Amazul;
}

class Amazul : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit Amazul(QWidget *parent = 0);
	~Amazul();

	void closeEvent(QCloseEvent *);
	static QMessageBox::StandardButton questionDialog(QString title,
													  QString text,
													  QString info,
													  QWidget *parent = 0);

	static void infoDialog(QString title, QString text, QString info,
						   QWidget *parent = 0);

private slots:
	void buttonSearchToggled(bool);
	void addRow();
	void removeRow();
	void save();
	void undo();
	void preview();
	void printAll();
	void showMap();

	void setModified(bool b = true);
	void rowToChange(QModelIndex);
	void selectionChanged();
	void focusCorrespondingEditor(QModelIndex);


private:
	void setupModel();
	void setupView();
	void setupMapper();
	void setupConnections();
	void setupStateMachine();
	QMessageBox::StandardButton saveChanges();

	LineFilter				*leFilter;
	LineEdit				*leLastname;
	LineEdit				*leNumber;

	StudentsTableView		*tableView;
	StudentsTableModel		*model;
	SortFilterProxyModel	*proxyModel;
	QItemSelectionModel		*selectionModel;
	QDataWidgetMapper		*mapper;

	QStateMachine			*machine;
	QState					*editing;
	QState					*addingRow;

	Ui::Amazul				*ui;
	CalendarWidget			*calendar;
	QWebView				*mapView;
	bool					modified;
};

#endif // AMAZUL_H
