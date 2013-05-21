#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class LineEdit : public QLineEdit
{
	Q_OBJECT
public:
	explicit LineEdit(QWidget *parent = 0);

protected:
	void keyPressEvent(QKeyEvent *);
	
signals:
	
public slots:
	
};

#endif // LINEEDIT_H
