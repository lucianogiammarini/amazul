#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include "calendarmodel.h"
#include <QTableView>
#include <QComboBox>

#define COLUMN_WIDTH 30
#define ROW_HEIGTH 30

class CalendarWidget : public QTableView
{
	Q_OBJECT
	Q_PROPERTY(int day READ day WRITE setDay)
	Q_PROPERTY(int month READ month WRITE setMonth)
public:
	explicit CalendarWidget(QWidget *parent = 0);
	~CalendarWidget();

	QComboBox *combo() const;

	void setDay(const int);
	int day() const;

	void setMonth(const int);
	int month() const;

protected:
	void mousePressEvent(QMouseEvent *);

signals:
	void monthChanged(int);
	void dayChanged(int);

private slots:
	void currentMonthChanged(int);

private:
	CalendarModel		*mModel;
	QComboBox			*mCombo;
};

#endif // CALENDARWIDGET_H
