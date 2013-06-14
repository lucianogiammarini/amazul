#include "pdfcreator.h"
#include "studentstablemodel.h"
#include "htmlConstants.h"
#include <QDebug>

PdfCreator::PdfCreator(StudentsTableModel *model) :
	QObject()
{
	this->model = model;
	mLength.insert(QPrinter::Legal, 64);
	mLength.insert(QPrinter::A4, 51);

	web = new QWebView();
	connect(web, SIGNAL(loadFinished(bool)), this, SLOT(convertIt()));

	printer.setPageSize(QPrinter::Legal); // "legal", "a4"
	printer.setPageMargins(20, 15, 20, 15, QPrinter::Millimeter);
	printer.setOutputFormat(QPrinter::PdfFormat);
}

PdfCreator::~PdfCreator()
{
	delete web;
}

void PdfCreator::createPdf(const QString filename, QPrinter::PageSize size)
{
	printer.setOutputFileName(filename);
	printer.setPageSize(size);
	web->setHtml(buildHTML());
}

void PdfCreator::convertIt(void)
{
	web->print(&printer);
}

QString PdfCreator::buildHTML()
{
	QString html(HTML_INIT);
	int mLength = this->mLength[printer.pageSize()];
	int length = 0;
	int page = 1;
	for(int i=0; i<model->rowCount(); i++){
		if (!model->print(i))
			continue;

		QString name = model->name(i);
		QString address = model->address(i);
		QString birthday = model->birthday(i);
		QStringList phones = model->phones(i);

		int max = qMax(phones.count(), 2);
		length += max;
		if (length > mLength){
			html.append(END_TABLE.arg(page));
			for (int i=0; i<mLength-(length-max); i++)
				html.append("</br>");

			html.append(TABLE_INIT);
			length = phones.count();
			page++;
		}

		html.append(ROW.arg(name,address,birthday,phones.join("</br>")));
	}
	html.append(END_HTML.arg(page));
	//qDebug() << html;
	return html;
}
