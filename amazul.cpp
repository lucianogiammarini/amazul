#include "amazul.h"
#include "ui_amazul.h"
#include "delegate.h"
#include "printdelegate.h"
#include "pdfcreator.h"
#include "pagesizedialog.h"

#include <QtWidgets>
#include <QtWebKitWidgets>
#include <QtSql/QtSql>

Amazul::Amazul(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Amazul)
{
	ui->setupUi(this);
	modified = false;

	calendar = new CalendarWidget();
	ui->calendarLayout->addWidget(calendar);

	mapView = new QWebView();

	leNumber = new LineEdit();
	leNumber->setMaxLength(4);
	leNumber->setMaximumWidth(50);
	leNumber->setPlaceholderText(trUtf8("Nro"));
	ui->layoutNumber->addWidget(leNumber);

	leLastname = new LineEdit();
	leLastname->setMaxLength(20);
	leLastname->setPlaceholderText(trUtf8("Apellido"));
	ui->layoutLastname->addWidget(leLastname);

	leFilter = new LineFilter(":/images/images/Clear-small.png", this);
	ui->centralLayout->addWidget(leFilter);
	leFilter->hide();

	setupConnections();
	setupModel();
	setupView();
	setupMapper();
	setupStateMachine();

	tableView->selectRow(0);

	connect(ui->pbSearch, SIGNAL(toggled(bool)),
			this, SLOT(buttonSearchToggled(bool)));

	connect(ui->pbSave, SIGNAL(clicked()), this, SLOT(save()));
	connect(ui->pbUndo, SIGNAL(clicked()), this, SLOT(undo()));

	connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addRow()));
	connect(ui->pbDel, SIGNAL(clicked()), this, SLOT(removeRow()));
	connect(ui->pbPreview, SIGNAL(clicked()), this, SLOT(preview()));
	connect(ui->pbPrintAll, SIGNAL(clicked()), this, SLOT(printAll()));

	connect(ui->pbMap, SIGNAL(clicked()), this, SLOT(showMap()));

	showMaximized();
}

Amazul::~Amazul()
{
	delete leFilter;
	delete leLastname;
    delete leNumber;

	delete tableView;
	delete model;
	delete proxyModel;
    //delete selectionModel;
    delete mapper;
	delete machine;
	delete editing;
	delete addingRow;

	delete ui;
	delete calendar;
    delete mapView;
}

void Amazul::closeEvent(QCloseEvent *event)
{
	event->ignore();
	if (!modified)
	{
		model->submitAll();
		event->accept();
	}
	else
	{
		QMessageBox::StandardButton save = saveChanges();
		if (save == QMessageBox::No){
			model->submitAll();
			event->accept();
		}
		else if (save == QMessageBox::Yes) {
			mapper->submit();
			model->submitAll();
			event->accept();
		}
	}
}

void Amazul::buttonSearchToggled(bool b)
{
	if (b)
	{
		leFilter->showAnimated();
		leFilter->setFocus();
	}
	else
	{
		leFilter->clear();
		leFilter->hideAnimated();
	}
}

void Amazul::addRow()
{
	if (modified){
		QMessageBox::StandardButton save = saveChanges();
		if (save == QMessageBox::Yes)
			mapper->submit();
		else if(save == QMessageBox::Cancel)
			return;
	}

	proxyModel->insertRow(0);
	QModelIndex index = proxyModel->index(0,0);
	tableView->setCurrentIndex(index);
	tableView->scrollToTop();
	leLastname->setFocus();
}

void Amazul::removeRow()
{
	QMessageBox question(QMessageBox::Question, trUtf8("Confirmar"),
					trUtf8("<b>Seguro desea eliminar la alumna seleccionada?</b>"),
					QMessageBox::Cancel | QMessageBox::Ok, this);
	question.setWindowIcon(QIcon(QPixmap(":/images/images/Amazul.png")));
	question.setInformativeText(trUtf8("Los datos se perderan."));
	question.setProperty("iconPixmap", QPixmap(":/images/images/Question.png"));

	QAbstractButton *ok = question.button(QMessageBox::Ok);
	ok->setIcon(QIcon(QPixmap(":/images/images/Accept.png")));
	QAbstractButton *cancel = question.button(QMessageBox::Cancel);
	cancel->setIcon(QIcon(QPixmap(":/images/images/Reject.png")));
	question.setDefaultButton(QMessageBox::Cancel);

	question.exec();
	if (question.clickedButton() != question.button(QMessageBox::Ok))
		return;

	mapper->revert();
	proxyModel->removeRow(tableView->currentIndex().row());
	model->submitAll();
}

void Amazul::save()
{
	mapper->submit();
	QModelIndex current = tableView->currentIndex();
	model->submitAll();
	tableView->setCurrentIndex(current);
	tableView->scrollTo(current);
	modified = false;
	ui->widget->setEnabled(modified);
}

void Amazul::undo()
{
	mapper->revert();
	modified = false;
	ui->widget->setEnabled(modified);
	if (machine->configuration().contains(addingRow)){
		proxyModel->removeRow(tableView->currentIndex().row());
	}
}

void Amazul::preview()
{
	PageSizeDialog dialog(this);
	if (dialog.exec() == QDialog::Rejected)
		return;

    QString path = QDir::tempPath().append("/amazul.pdf");
    QString fileName = QDir::toNativeSeparators(path);
    if (QFile::exists(fileName))
        QFile::remove(fileName);

    QFile tmpFile(fileName);
    tmpFile.open(QIODevice::ReadWrite);

	QPrinter::PageSize size = dialog.pageSize();
	PdfCreator creator(model);
    creator.createPdf(fileName, size);
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

void Amazul::printAll()
{
	for(int row=0; row < model->rowCount(); row++)
		model->setData(model->index(row, 14), QVariant(1));
}

void Amazul::showMap()
{
	QString url("http://maps.google.es/maps?q=%1+Cordoba+Argentina&output=embed");

	QModelIndex index = proxyModel->mapToSource(tableView->currentIndex());
	QString address = model->addressForMap(index.row());
	address = address.replace("Sarmiento",
							  "Domingo Faustino Sarmiento",
							  Qt::CaseInsensitive);
	address = address.replace("Mitre",
							  "Bartolome Mitre",
							  Qt::CaseInsensitive);

	QString title = tr("Amazul - Mapa de %1").arg(model->name(index.row()));
	mapView->setWindowTitle(title);
	mapView->load(QUrl(url.arg(address)));
	mapView->showMaximized();
	mapView->activateWindow();
	mapView->raise();
}

void Amazul::setModified(bool b)
{
	modified = b;
	ui->widget->setEnabled(modified);
}

void Amazul::rowToChange(QModelIndex index)
{
	if (!modified){
		if (machine->configuration().contains(addingRow)){
			proxyModel->removeRow(tableView->currentIndex().row());
		}
		tableView->setCurrentIndex(index);
		return;
	}

	QMessageBox::StandardButton save = saveChanges();
	if (save == QMessageBox::No)
		tableView->setCurrentIndex(index);
	else if (save == QMessageBox::Yes) {
		mapper->submit();
		tableView->setCurrentIndex(index);
	}
}

void Amazul::selectionChanged()
{
	ui->widgetInfo->setEnabled(selectionModel->hasSelection());
	ui->pbDel->setEnabled(selectionModel->hasSelection());
	modified = false;
	ui->widget->setEnabled(modified);
}

void Amazul::focusCorrespondingEditor(QModelIndex index){
	switch(index.column())
	{
	case 1:
		leLastname->setFocus();
		break;
	case 2:
		ui->leName->setFocus();
		break;
	case 3:
		ui->leAddress->setFocus();
		break;
	case 4:
		leNumber->setFocus();
		break;
	case 5:
		ui->leCity->setFocus();
		break;
	case 9:
		ui->lePhone1->setFocus();
		break;
	case 11:
		ui->lePhone2->setFocus();
		break;
	case 13:
		ui->lePhone3->setFocus();
		break;
	}
}

void Amazul::setupStateMachine()
{
	machine = new QStateMachine(this);
	editing = new QState();
	editing->assignProperty(ui->pbUndo, "text", trUtf8("Deshacer"));
	editing->assignProperty(ui->pbUndo, "icon", QIcon(QPixmap(":/images/images/Undo.png")));
	editing->assignProperty(ui->widget, "enabled", false);

	addingRow = new QState();
	addingRow->assignProperty(ui->pbUndo, "text", trUtf8("Cancelar"));
	addingRow->assignProperty(ui->pbUndo, "icon", QIcon(QPixmap(":/images/images/Reject.png")));
	addingRow->assignProperty(ui->widget, "enabled", true);
	addingRow->assignProperty(calendar, "day", -1);
	addingRow->assignProperty(calendar, "month", 0);
	editing->addTransition(ui->pbAdd, SIGNAL(clicked()), addingRow);

	addingRow->addTransition(ui->pbSave, SIGNAL(clicked()), editing);
	addingRow->addTransition(ui->pbUndo, SIGNAL(clicked()), editing);
	addingRow->addTransition(selectionModel,
				SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), editing);

	machine->addState(editing);
	machine->addState(addingRow);
	machine->setInitialState(editing);
	machine->start();
}

void Amazul::setupConnections()
{
	connect(ui->leName, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(leLastname, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(ui->leAddress, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(leNumber, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(ui->leCity, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(ui->leLabel1, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(ui->leLabel2, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(ui->leLabel3, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(ui->lePhone1, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(ui->lePhone2, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(ui->lePhone3, SIGNAL(textEdited(QString)),
			this, SLOT(setModified()));
	connect(calendar, SIGNAL(dayChanged(int)),
			this, SLOT(setModified()));
	connect(calendar, SIGNAL(monthChanged(int)),
			this, SLOT(setModified()));
}


void Amazul::setupModel()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("amazul_db");

	if (!db.open()) {
		QMessageBox::critical(0, trUtf8("No se puede abrir la base de datos"),
				trUtf8("No se puede establecer una conexión de base de datos.\n"),
				QMessageBox::Cancel);
		return;
	}

	/*QSqlQuery query;
	query.exec("CREATE TABLE student (id INTEGER PRIMARY KEY AUTOINCREMENT, "
			   "lastName VARCHAR(20), name VARCHAR(20), "
			   "address VARCHAR(40), number VARCHAR(4), city VARCHAR(20),"
			   "day TINYINT DEFAULT -1, month TINYINT DEFAULT 0,"
			   "label1 VARCHAR(10) DEFAULT '', phone1 VARCHAR(15) DEFAULT '',"
			   "label2 VARCHAR(10) DEFAULT '', phone2 VARCHAR(15) DEFAULT '',"
			   "label3 VARCHAR(10) DEFAULT '', phone3 VARCHAR(15) DEFAULT '',"
			   "print TINYINT DEFAULT 1)");

	QFile file("amazul_db.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			 return;

	while (!file.atEnd())
	{
		 QString string = QString::fromUtf8(file.readLine());
		 bool b = query.exec(string);
		 if (!b)
			 qDebug() << string << query.lastError().text();
	}*/

	model = new StudentsTableModel(this, db);
	model->setTable("student");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Apellido"));
	model->setHeaderData(2, Qt::Horizontal, trUtf8("Nombre"));
	model->setHeaderData(3, Qt::Horizontal, trUtf8("Calle"));
	model->setHeaderData(4, Qt::Horizontal, trUtf8("Numero"));
	model->setHeaderData(5, Qt::Horizontal, trUtf8("Ciudad"));
	model->setHeaderData(6, Qt::Horizontal, trUtf8("Dia"));
	model->setHeaderData(7, Qt::Horizontal, trUtf8("Mes"));
	model->setHeaderData(8, Qt::Horizontal, trUtf8("Etiqueta"));
	model->setHeaderData(9, Qt::Horizontal, trUtf8("Telefono"));
	model->setHeaderData(10, Qt::Horizontal, trUtf8("Etiqueta"));
	model->setHeaderData(11, Qt::Horizontal, trUtf8("Telefono"));
	model->setHeaderData(12, Qt::Horizontal, trUtf8("Etiqueta"));
	model->setHeaderData(13, Qt::Horizontal, trUtf8("Telefono"));
	model->setHeaderData(14, Qt::Horizontal, trUtf8("Imprimir"));
}

void Amazul::setupView()
{
	proxyModel = new SortFilterProxyModel(this);
	proxyModel->setSourceModel(model);
	proxyModel->setDynamicSortFilter(true);
	proxyModel->setFilterKeyColumn(1);
	proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

	tableView = new StudentsTableView();
	ui->centralLayout->addWidget(tableView);
	tableView->setModel(proxyModel);
	tableView->setSortingEnabled(true);
	tableView->sortByColumn(1, Qt::AscendingOrder);
	tableView->resizeColumnsToContents();
	tableView->hideColumn(0);
	tableView->hideColumn(5);
	//tableView->hideColumn(6);
	//tableView->hideColumn(7);
	tableView->hideColumn(8);
	tableView->hideColumn(10);
	tableView->hideColumn(12);
	tableView->setItemDelegateForColumn(14, new PrintDelegate(this));

	connect(tableView, SIGNAL(rowToChange(QModelIndex)),
			this, SLOT(rowToChange(QModelIndex)));
	connect(tableView, SIGNAL(activated(QModelIndex)),
			this, SLOT(focusCorrespondingEditor(QModelIndex)));

	selectionModel = tableView->selectionModel();
	connect(selectionModel,
			SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
			this, SLOT(selectionChanged()));
	connect(leFilter, SIGNAL(textChanged(QString)),
			proxyModel, SLOT(setFilterFixedString(QString)));
}

QMessageBox::StandardButton Amazul::saveChanges()
{
	QString question;
	if (machine->configuration().contains(editing)){
		QModelIndex current = tableView->currentIndex();
		int row = proxyModel->mapToSource(current).row();

		QModelIndex lastNameIndex = model->index(row, 1);
		QModelIndex nameIndex = model->index(row, 2);
		QString lastName = lastNameIndex.data(Qt::DisplayRole).toString();
		QString name = nameIndex.data(Qt::DisplayRole).toString();


		question = trUtf8("<b>Desea guardar los cambios realizados<br/>en la"
					  " alumna <k>%1 %2</k></b>?").arg(name).arg(lastName);
	}
	else{
		question = trUtf8("<b>Desea guardar los cambios realizados "
						   "en la fila insertada?</b>");
	}

	return questionDialog(trUtf8("Confirmar"), question, QString());
}

void Amazul::setupMapper()
{
	mapper = new QDataWidgetMapper(this);
	mapper->setModel(proxyModel);
	mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
	mapper->setItemDelegate(new Delegate(this));
	mapper->addMapping(leLastname, model->fieldIndex("lastName"));
	mapper->addMapping(ui->leName, model->fieldIndex("name"));
	mapper->addMapping(ui->leAddress, model->fieldIndex("address"));
	mapper->addMapping(leNumber, model->fieldIndex("number"));
	mapper->addMapping(ui->leCity, model->fieldIndex("city"));
	mapper->addMapping(calendar, model->fieldIndex("day"));
	mapper->addMapping(calendar->combo(), model->fieldIndex("month"));
	mapper->addMapping(ui->leLabel1, model->fieldIndex("label1"));
	mapper->addMapping(ui->lePhone1, model->fieldIndex("phone1"));
	mapper->addMapping(ui->leLabel2, model->fieldIndex("label2"));
	mapper->addMapping(ui->lePhone2, model->fieldIndex("phone2"));
	mapper->addMapping(ui->leLabel3, model->fieldIndex("label3"));
	mapper->addMapping(ui->lePhone3, model->fieldIndex("phone3"));

	connect(selectionModel, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
			mapper, SLOT(setCurrentModelIndex(QModelIndex)));
}

QMessageBox::StandardButton Amazul::questionDialog(QString title, QString text,
												   QString info, QWidget *parent)
{
	QMessageBox question(QMessageBox::Question, title, text,
				QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, parent);
	question.setWindowIcon(QIcon(QPixmap(":/images/images/Amazul.png")));
	question.setProperty("iconPixmap", QPixmap(":/images/images/Question.png"));
	question.setInformativeText(info);

	QAbstractButton *yes = question.button(QMessageBox::Yes);
	yes->setIcon(QIcon(QPixmap(":/images/images/Accept.png")));
	QAbstractButton *no = question.button(QMessageBox::No);
	no->setIcon(QIcon(QPixmap(":/images/images/Reject.png")));
	QAbstractButton *cancel = question.button(QMessageBox::Cancel);
	cancel->setIcon(QIcon(QPixmap(":/images/images/Cancel.png")));
	question.setDefaultButton(QMessageBox::Yes);

	question.exec();
	if (question.clickedButton() == question.button(QMessageBox::Yes))
		return QMessageBox::Yes;
	else if (question.clickedButton() == question.button(QMessageBox::No))
		return QMessageBox::No;
	else
		return QMessageBox::Cancel;
}

void Amazul::infoDialog(QString title, QString text, QString info, QWidget *parent)
{
	QMessageBox dialog(QMessageBox::Information, title, text,
				QMessageBox::Ok, parent);
	dialog.setWindowIcon(QIcon(QPixmap(":/images/images/Amazul.png")));
	dialog.setProperty("iconPixmap", QPixmap(":/images/images/Alert.png"));
	dialog.setInformativeText(info);

	QAbstractButton *ok = dialog.button(QMessageBox::Ok);
	ok->setIcon(QIcon(QPixmap(":/images/images/Accept.png")));
	dialog.setDefaultButton(QMessageBox::Ok);

	dialog.exec();
}
