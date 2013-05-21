#ifndef PAGESIZEDIALOG_H
#define PAGESIZEDIALOG_H

#include <QDialog>
#include <QPrinter>

class QSettings;
class QRadioButton;


class PageSizeDialog : public QDialog
{
	Q_OBJECT
public:

	explicit PageSizeDialog(QWidget *parent = 0);
	~PageSizeDialog();
	
	void setupPageSize();
	QPrinter::PaperSize pageSize() const;

private slots:
	void sizeChanged(int);

private:
	QSettings	*settings;
	QRadioButton *rbA4;
	QRadioButton *rbLegal;
};

#endif // PAGESIZEDIALOG_H
