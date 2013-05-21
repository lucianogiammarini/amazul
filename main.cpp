#include <QApplication>
//#include <QtSingleApplication>
#include "amazul.h"
#include <QStyleFactory>
#include <QLibraryInfo>
#include <QTranslator>

#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

void myMessageHandler(QtMsgType type, const char *msg)
{
	QString txt;
	switch (type) {
	case QtDebugMsg:
		txt = QString("Debug: %1").arg(msg);
		break;
	case QtWarningMsg:
		txt = QString("Warning: %1").arg(msg);
	break;
	case QtCriticalMsg:
		txt = QString("Critical: %1").arg(msg);
	break;
	case QtFatalMsg:
		txt = QString("Fatal: %1").arg(msg);
		abort();
	}
	QFile outFile("log.txt");
	outFile.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream ts(&outFile);
	QString datetime("ddd d MMM yyyy - hh:mm:ss");
	ts << QDateTime::currentDateTime().toString(datetime) <<": "<< txt << endl;
}



int main(int argc, char *argv[])
{
    /*QtSingleApplication app(argc, argv);
	if (app.isRunning()){
		QString text = Amazul::trUtf8("<b>Amazul ya está abierto.</b>");
		QString info = Amazul::trUtf8("Sólo puede abrir una instancia a la vez.");
		Amazul::infoDialog(Amazul::tr("Amazul"), text, info);
		return 0;
    }*/
    QApplication app(argc, argv);
    //qInstallMsgHandler(myMessageHandler);

	QStyleFactory styleFactory = QStyleFactory();
	app.setStyle(styleFactory.create("Plastique"));

	QTranslator qtTranslator;
	qtTranslator.load("qt_" + QLocale::system().name(),
					  QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	//qtTranslator.load("amazul_en");
	app.installTranslator(&qtTranslator);

	Amazul w;
	w.show();
    //app.setActivationWindow(&w);
	
	return app.exec();
}
