#include "pagesizedialog.h"

#include <QtWidgets>

PageSizeDialog::PageSizeDialog(QWidget *parent) :
	QDialog(parent)
{
	setWindowTitle("Amazul");
	setWindowIcon(QIcon(QPixmap(":/images/images/Amazul.ico")));

	settings = new QSettings("Luciano", "Amazul");

	QLabel *label = new QLabel(trUtf8("Tamaño de la página"), this);
	label->setAlignment(Qt::AlignCenter);

	QHBoxLayout *horLayout = new QHBoxLayout;
	QButtonGroup *buttonGroup = new QButtonGroup;

	rbLegal = new QRadioButton(tr("Oficio"));
	rbLegal->setChecked(true);
	buttonGroup->addButton(rbLegal, QPrinter::Legal);
	horLayout->addWidget(rbLegal);

	rbA4 = new QRadioButton(tr("A4"));
	buttonGroup->addButton(rbA4, QPrinter::A4);
	horLayout->addWidget(rbA4);

	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok |
													   QDialogButtonBox::Cancel,
													   Qt::Horizontal);
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	QPushButton *ok = buttonBox->button(QDialogButtonBox::Ok);
	ok->setIcon(QIcon(QPixmap(":/images/images/Accept.png")));
	QPushButton *cancel = buttonBox->button(QDialogButtonBox::Cancel);
	cancel->setIcon(QIcon(QPixmap(":/images/images/Reject.png")));

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(label);
	layout->addLayout(horLayout);
	layout->addWidget(buttonBox);
	setLayout(layout);

	setupPageSize();

	connect(buttonGroup, SIGNAL(buttonClicked(int)),
			this, SLOT(sizeChanged(int)));
}

PageSizeDialog::~PageSizeDialog()
{
	delete settings;
	delete rbA4;
	delete rbLegal;
}


void PageSizeDialog::setupPageSize()
{
	QPrinter::PaperSize size;
	size = (QPrinter::PaperSize)settings->value("pageSize").toInt();
	switch(size)
	{
	case QPrinter::Legal:
		rbLegal->setChecked(true);
		break;
	case QPrinter::A4:
		rbA4->setChecked(true);
		break;
	default:
		break;
	}
}

void PageSizeDialog::sizeChanged(int size)
{
	settings->setValue("pageSize", QVariant(size));
}

QPrinter::PaperSize PageSizeDialog::pageSize() const
{
	return (QPrinter::PaperSize)settings->value("pageSize").toInt();
}
