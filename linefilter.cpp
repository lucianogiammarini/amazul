#include "linefilter.h"
#include <QtWidgets>
#include <iostream>

LineFilter::LineFilter(QString buttonFileName, QWidget *parent) :
	QLineEdit(parent)
{
	//setMinimumHeight(31);
	setToolTip(tr("Filtrar alumnas"));

	mClearButton = new QToolButton(this);
	QPixmap pixmap(buttonFileName);
	mClearButton->setIcon(QIcon(pixmap));
	mClearButton->setIconSize(pixmap.size());
	mClearButton->setToolTip(tr("Borrar"));
	mClearButton->setCursor(Qt::PointingHandCursor);
	mClearButton->setFixedSize(pixmap.size() + QSize(4,4));
	mClearButton->setStyleSheet("QToolButton { background-color: rgb(0,40,0,0); }");
	connect(mClearButton, SIGNAL(clicked()), this, SLOT(clear()));
	mClearButton->hide();

	connect(this, SIGNAL(textChanged(QString)), this, SLOT(updateClearButton()));

	int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
	//int widthHint = mClearButton->sizeHint().width();
	int widthHint = mClearButton->size().width();
	QString styleSheet("padding-right: %1px;");
	setStyleSheet(styleSheet.arg(widthHint + frameWidth + 1));

	setupAnimations();
}

LineFilter::~LineFilter()
{
	delete mClearButton;
	delete showAnim;
	delete hideAnim;
}

void LineFilter::setupAnimations()
{
	QPropertyAnimation *showHeigthAnim = new QPropertyAnimation(this,
																"maximumHeight");
	showHeigthAnim->setDuration(500);
	showHeigthAnim->setStartValue(0);
	showHeigthAnim->setEndValue(31);

	QPropertyAnimation *showWidthAnim = new QPropertyAnimation(this,
															   "maximumWidth");
	showWidthAnim->setDuration(1000);
	showWidthAnim->setStartValue(0);
	showWidthAnim->setEndValue(2000);

	showAnim = new QSequentialAnimationGroup;
	showAnim->addAnimation(showHeigthAnim);
	showAnim->addAnimation(showWidthAnim);

	QPropertyAnimation *hideHeigthAnim = new QPropertyAnimation(this,
																"maximumHeight");
	hideHeigthAnim->setDuration(500);
	hideHeigthAnim->setStartValue(31);
	hideHeigthAnim->setEndValue(0);

	QPropertyAnimation *hideWidthAnim = new QPropertyAnimation(this,
															   "maximumWidth");
	hideWidthAnim->setDuration(1000);
	hideWidthAnim->setStartValue(2000);
	hideWidthAnim->setEndValue(0);

	hideAnim = new QSequentialAnimationGroup;
	hideAnim->addAnimation(hideWidthAnim);
	hideAnim->addAnimation(hideHeigthAnim);
	connect(hideAnim, SIGNAL(finished()), this, SLOT(hide()));
}

void LineFilter::hideAnimated()
{
	hideAnim->start();
}

void LineFilter::showAnimated()
{
	setMaximumWidth(0);
	QLineEdit::show();
	showAnim->start();
}

void LineFilter::resizeEvent(QResizeEvent *)
{
	int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);

	//QSize szb = mClearButton->sizeHint();
	QSize szb = mClearButton->size();
	mClearButton->move(rect().right() - frameWidth - szb.width(),
					  (rect().bottom() + 1 - szb.height())/2);

	frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
	QString styleSheet("padding-right: %1px;");
	setStyleSheet(styleSheet.arg(szb.width() + frameWidth + 1));
}

void LineFilter::updateClearButton()
{
	mClearButton->setVisible(!text().isEmpty());
}
