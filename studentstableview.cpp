#include "studentstableview.h"
#include <QMouseEvent>
#include <QHeaderView>
#include <QSqlTableModel>


StudentsTableView::StudentsTableView(QWidget *parent) :
	QTableView(parent)
{
	setSelectionMode(QAbstractItemView::SingleSelection);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	verticalHeader()->hide();
	//setFocusPolicy(Qt::NoFocus);
}

void StudentsTableView::mousePressEvent(QMouseEvent *event)
{
	QModelIndex indexSelected = currentIndex();
	QModelIndex indexClicked = indexAt(event->pos());
    if (!indexSelected.isValid() || !indexClicked.isValid())
        return;

    if (indexClicked.row() != indexSelected.row())
		emit rowToChange(indexClicked);

    if (indexClicked.column() == 14) {
		int value = model()->data(indexClicked).toInt();
		model()->setData(indexClicked, 1-value);
		emit printChanged();
    }

	QTableView::mousePressEvent(event);
}
