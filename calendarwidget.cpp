#include "calendarwidget.h"
#include "combobox.h"
#include <QtWidgets>
#include <QDebug>

CalendarWidget::CalendarWidget(QWidget *parent) :
	QTableView(parent)
{
	verticalHeader()->hide();
	horizontalHeader()->hide();
	setSelectionMode(QAbstractItemView::SingleSelection);
	setFixedSize(7*COLUMN_WIDTH + 4, 5*ROW_HEIGTH + 4);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFocusPolicy(Qt::NoFocus);

	QPalette p = palette();
	QColor color = p.color(QPalette::Active, QPalette::Highlight);
	p.setColor(QPalette::Inactive, QPalette::Highlight, color);
	setPalette(p);

	/*void MyDelegate::paint(
		QPainter                     *painter,
		QStyleOptionViewItem const &  option,
			QModelIndex          const &  index) const
	{
		QStyleOptionViewItem opt(option);

		if (index.column() == _colorColumn)
		{
			opt.palette.setColor(
				QPalette::Base,
				QColor(255, 255, 204));

			opt.palette.setColor(
				QPalette::Window,
				QColor(255, 255, 204));
		}

		return QItemDelegate::paint(painter, opt, index);
	}
	*/

	mModel = new CalendarModel();
	setModel(mModel);

	for(int i=0;i<5;i++)
		setRowHeight(i,ROW_HEIGTH);
	for(int i=0;i<7;i++)
		setColumnWidth(i,COLUMN_WIDTH);

    mCombo = new ComboBox(this);
	mCombo->setMaxVisibleItems(13);
	mCombo->setGeometry(3*COLUMN_WIDTH+2,4*ROW_HEIGTH+2,4*COLUMN_WIDTH,ROW_HEIGTH);
	mCombo->addItems(QStringList() << tr("Mes") << tr("Enero") << tr("Febrero")
					 << tr("Marzo") << tr("Abril") << tr("Mayo") << tr("Junio")
					 << tr("Julio") << tr("Agosto") << tr("Septiembre")
					 << tr("Octubre") << tr("Noviembre") << tr("Diciembre"));
	connect(mCombo, SIGNAL(activated(int)),
			this, SLOT(currentMonthChanged(int)));
}

CalendarWidget::~CalendarWidget()
{
	delete mModel;
	delete mCombo;
}

void CalendarWidget::mousePressEvent(QMouseEvent *event)
{
	QModelIndex indexSelected = currentIndex();
	QModelIndex indexClicked = indexAt(event->pos());
	if (indexClicked.isValid() && indexClicked != indexSelected)
	{
		emit dayChanged(mModel->getDay(indexClicked));
	}
	QTableView::mousePressEvent(event);
}


void CalendarWidget::currentMonthChanged(int month)
{
	emit monthChanged(month);
	if (month == 0){
		setDay(0);
		clearSelection();
	}
}

void CalendarWidget::setDay(const int day)
{
	int d = day-1;
	QModelIndex index = mModel->index(d/7, d%7);
	setCurrentIndex(index);
}

int CalendarWidget::day() const
{
	QModelIndex index = currentIndex();
	if (!index.isValid())
		return 0;

	return mModel->getDay(index);
}

void CalendarWidget::setMonth(const int month)
{
	mCombo->setCurrentIndex(month);
}

int CalendarWidget::month() const
{
	return mCombo->currentIndex();
}

QComboBox *CalendarWidget::combo() const
{
	return mCombo;
}
