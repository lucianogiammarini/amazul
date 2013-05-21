#ifndef LINEFILTER_H
#define LINEFILTER_H

#include <QLineEdit>
class QToolButton;
class QSequentialAnimationGroup;

class LineFilter : public QLineEdit
{
	Q_OBJECT
public:
	explicit LineFilter(QString buttonFileName, QWidget *parent = 0);
	~LineFilter();

	void hideAnimated();
	void showAnimated();

protected:
	void resizeEvent(QResizeEvent *);
	
private slots:
	void updateClearButton();

private:
	void setupAnimations();

	QToolButton *mClearButton;
	QSequentialAnimationGroup *showAnim;
	QSequentialAnimationGroup *hideAnim;
};

#endif // LINEFILTER_H
