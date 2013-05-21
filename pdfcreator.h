#ifndef PDFCREATOR_H
#define PDFCREATOR_H

#include <QPrinter>
#include <QMap>
#include <QWebView>
#include <QTemporaryFile>
#include "studentstablemodel.h"

class PdfCreator : public QObject
{
	Q_OBJECT
	
public:
	explicit PdfCreator(StudentsTableModel *model);
	virtual ~PdfCreator();

	void createPdf(const QString filename, QPrinter::PageSize size);

private slots:
	void convertIt();

private:
	QString buildHTML();

	StudentsTableModel				*model;
	QWebView						*web;
	QPrinter						printer;
	QMap<QPrinter::PageSize, int>	mLength;
};

#endif // PDFCREATOR_H
