#include "lineedit.h"
#include <QKeyEvent>
#include <QDebug>

LineEdit::LineEdit(QWidget *parent) :
	QLineEdit(parent)
{
	setMinimumHeight(30);
}

void LineEdit::keyPressEvent(QKeyEvent *event)
{
	QLineEdit::keyPressEvent(event);

	QString lowerCases("abcdefghijklmnñopqrstuvwxyz");
	if (lowerCases.contains(event->text()) &&
			!event->text().isEmpty()){
		int pos = cursorPosition();
		setText(text().toUpper());
		setCursorPosition(pos);
	}
}
