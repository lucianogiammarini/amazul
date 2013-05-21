#ifndef STUDENTSTABLEVIEW_H
#define STUDENTSTABLEVIEW_H

#include <QTableView>

class StudentsTableView : public QTableView
{
	Q_OBJECT
public:
	explicit StudentsTableView(QWidget *parent = 0);

protected:
	void mousePressEvent(QMouseEvent *event);
	
signals:
	void rowToChange(QModelIndex);
	void printChanged();
	
public slots:
	
};

#endif // STUDENTSTABLEVIEW_H
