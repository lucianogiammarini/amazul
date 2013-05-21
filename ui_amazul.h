/********************************************************************************
** Form generated from reading UI file 'amazul.ui'
**
** Created: Mon 16. Jul 16:33:03 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMAZUL_H
#define UI_AMAZUL_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_Amazul
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pbSearch;
    QPushButton *pbAdd;
    QPushButton *pbDel;
    QPushButton *pbPreview;
    QPushButton *pbPrintAll;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *centralLayout;
    QWidget *widgetInfo;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *lePhone1;
    QLineEdit *leLabel1;
    QLineEdit *lePhone2;
    QLineEdit *lePhone3;
    QLineEdit *leName;
    QLineEdit *leLabel2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *layoutNumber;
    QLineEdit *leCity;
    QPushButton *pbMap;
    QLineEdit *leAddress;
    QLineEdit *leLabel3;
    QHBoxLayout *layoutLastname;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *calendarLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbSave;
    QPushButton *pbUndo;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *Amazul)
    {
        if (Amazul->objectName().isEmpty())
            Amazul->setObjectName(QString::fromUtf8("Amazul"));
        Amazul->resize(715, 596);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Amazul.png"), QSize(), QIcon::Normal, QIcon::Off);
        Amazul->setWindowIcon(icon);
        centralWidget = new QWidget(Amazul);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pbSearch = new QPushButton(centralWidget);
        pbSearch->setObjectName(QString::fromUtf8("pbSearch"));
        pbSearch->setCursor(QCursor(Qt::PointingHandCursor));
        pbSearch->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSearch->setIcon(icon1);
        pbSearch->setIconSize(QSize(20, 20));
        pbSearch->setCheckable(true);

        verticalLayout->addWidget(pbSearch);

        pbAdd = new QPushButton(centralWidget);
        pbAdd->setObjectName(QString::fromUtf8("pbAdd"));
        pbAdd->setCursor(QCursor(Qt::PointingHandCursor));
        pbAdd->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/Contacts.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbAdd->setIcon(icon2);
        pbAdd->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(pbAdd);

        pbDel = new QPushButton(centralWidget);
        pbDel->setObjectName(QString::fromUtf8("pbDel"));
        pbDel->setCursor(QCursor(Qt::PointingHandCursor));
        pbDel->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/Recyclebin Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDel->setIcon(icon3);
        pbDel->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(pbDel);

        pbPreview = new QPushButton(centralWidget);
        pbPreview->setObjectName(QString::fromUtf8("pbPreview"));
        pbPreview->setCursor(QCursor(Qt::PointingHandCursor));
        pbPreview->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPreview->setIcon(icon4);
        pbPreview->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(pbPreview);

        pbPrintAll = new QPushButton(centralWidget);
        pbPrintAll->setObjectName(QString::fromUtf8("pbPrintAll"));
        pbPrintAll->setCursor(QCursor(Qt::PointingHandCursor));
        pbPrintAll->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/Accept.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPrintAll->setIcon(icon5);
        pbPrintAll->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(pbPrintAll);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout);

        centralLayout = new QVBoxLayout();
        centralLayout->setSpacing(6);
        centralLayout->setObjectName(QString::fromUtf8("centralLayout"));

        horizontalLayout_4->addLayout(centralLayout);


        verticalLayout_4->addLayout(horizontalLayout_4);

        widgetInfo = new QWidget(centralWidget);
        widgetInfo->setObjectName(QString::fromUtf8("widgetInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetInfo->sizePolicy().hasHeightForWidth());
        widgetInfo->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(widgetInfo);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lePhone1 = new QLineEdit(widgetInfo);
        lePhone1->setObjectName(QString::fromUtf8("lePhone1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lePhone1->sizePolicy().hasHeightForWidth());
        lePhone1->setSizePolicy(sizePolicy1);
        lePhone1->setMinimumSize(QSize(0, 30));
        lePhone1->setMaxLength(15);

        gridLayout->addWidget(lePhone1, 2, 2, 1, 1);

        leLabel1 = new QLineEdit(widgetInfo);
        leLabel1->setObjectName(QString::fromUtf8("leLabel1"));
        sizePolicy1.setHeightForWidth(leLabel1->sizePolicy().hasHeightForWidth());
        leLabel1->setSizePolicy(sizePolicy1);
        leLabel1->setMinimumSize(QSize(0, 30));
        leLabel1->setMaxLength(10);

        gridLayout->addWidget(leLabel1, 2, 0, 1, 1);

        lePhone2 = new QLineEdit(widgetInfo);
        lePhone2->setObjectName(QString::fromUtf8("lePhone2"));
        sizePolicy1.setHeightForWidth(lePhone2->sizePolicy().hasHeightForWidth());
        lePhone2->setSizePolicy(sizePolicy1);
        lePhone2->setMinimumSize(QSize(0, 30));
        lePhone2->setMaxLength(15);

        gridLayout->addWidget(lePhone2, 3, 2, 1, 1);

        lePhone3 = new QLineEdit(widgetInfo);
        lePhone3->setObjectName(QString::fromUtf8("lePhone3"));
        sizePolicy1.setHeightForWidth(lePhone3->sizePolicy().hasHeightForWidth());
        lePhone3->setSizePolicy(sizePolicy1);
        lePhone3->setMinimumSize(QSize(0, 30));
        lePhone3->setMaxLength(15);

        gridLayout->addWidget(lePhone3, 4, 2, 1, 1);

        leName = new QLineEdit(widgetInfo);
        leName->setObjectName(QString::fromUtf8("leName"));
        sizePolicy1.setHeightForWidth(leName->sizePolicy().hasHeightForWidth());
        leName->setSizePolicy(sizePolicy1);
        leName->setMinimumSize(QSize(0, 30));
        leName->setMaxLength(20);

        gridLayout->addWidget(leName, 0, 2, 1, 1);

        leLabel2 = new QLineEdit(widgetInfo);
        leLabel2->setObjectName(QString::fromUtf8("leLabel2"));
        sizePolicy1.setHeightForWidth(leLabel2->sizePolicy().hasHeightForWidth());
        leLabel2->setSizePolicy(sizePolicy1);
        leLabel2->setMinimumSize(QSize(0, 30));
        leLabel2->setMaxLength(10);

        gridLayout->addWidget(leLabel2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        layoutNumber = new QHBoxLayout();
        layoutNumber->setSpacing(6);
        layoutNumber->setObjectName(QString::fromUtf8("layoutNumber"));

        horizontalLayout->addLayout(layoutNumber);

        leCity = new QLineEdit(widgetInfo);
        leCity->setObjectName(QString::fromUtf8("leCity"));
        sizePolicy1.setHeightForWidth(leCity->sizePolicy().hasHeightForWidth());
        leCity->setSizePolicy(sizePolicy1);
        leCity->setMinimumSize(QSize(0, 30));
        leCity->setMaxLength(20);

        horizontalLayout->addWidget(leCity);

        pbMap = new QPushButton(widgetInfo);
        pbMap->setObjectName(QString::fromUtf8("pbMap"));
        pbMap->setMaximumSize(QSize(30, 30));
        pbMap->setCursor(QCursor(Qt::PointingHandCursor));
        pbMap->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/Address.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbMap->setIcon(icon6);
        pbMap->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pbMap);


        gridLayout->addLayout(horizontalLayout, 1, 2, 1, 1);

        leAddress = new QLineEdit(widgetInfo);
        leAddress->setObjectName(QString::fromUtf8("leAddress"));
        sizePolicy1.setHeightForWidth(leAddress->sizePolicy().hasHeightForWidth());
        leAddress->setSizePolicy(sizePolicy1);
        leAddress->setMinimumSize(QSize(0, 30));
        leAddress->setMaxLength(40);

        gridLayout->addWidget(leAddress, 1, 0, 1, 1);

        leLabel3 = new QLineEdit(widgetInfo);
        leLabel3->setObjectName(QString::fromUtf8("leLabel3"));
        sizePolicy1.setHeightForWidth(leLabel3->sizePolicy().hasHeightForWidth());
        leLabel3->setSizePolicy(sizePolicy1);
        leLabel3->setMinimumSize(QSize(0, 30));
        leLabel3->setMaxLength(10);

        gridLayout->addWidget(leLabel3, 4, 0, 1, 1);

        layoutLastname = new QHBoxLayout();
        layoutLastname->setSpacing(6);
        layoutLastname->setObjectName(QString::fromUtf8("layoutLastname"));

        gridLayout->addLayout(layoutLastname, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        calendarLayout = new QHBoxLayout();
        calendarLayout->setSpacing(0);
        calendarLayout->setObjectName(QString::fromUtf8("calendarLayout"));

        verticalLayout_2->addLayout(calendarLayout);

        widget = new QWidget(widgetInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbSave = new QPushButton(widget);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        pbSave->setCursor(QCursor(Qt::PointingHandCursor));
        pbSave->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/Floopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon7);
        pbSave->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pbSave);

        pbUndo = new QPushButton(widget);
        pbUndo->setObjectName(QString::fromUtf8("pbUndo"));
        pbUndo->setCursor(QCursor(Qt::PointingHandCursor));
        pbUndo->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/Undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbUndo->setIcon(icon8);
        pbUndo->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pbUndo);


        verticalLayout_2->addWidget(widget);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(widgetInfo);

        Amazul->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Amazul);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 715, 18));
        Amazul->setMenuBar(menuBar);
        QWidget::setTabOrder(leName, leAddress);
        QWidget::setTabOrder(leAddress, leCity);
        QWidget::setTabOrder(leCity, leLabel1);
        QWidget::setTabOrder(leLabel1, lePhone1);
        QWidget::setTabOrder(lePhone1, leLabel2);
        QWidget::setTabOrder(leLabel2, lePhone2);
        QWidget::setTabOrder(lePhone2, leLabel3);
        QWidget::setTabOrder(leLabel3, lePhone3);

        retranslateUi(Amazul);

        QMetaObject::connectSlotsByName(Amazul);
    } // setupUi

    void retranslateUi(QMainWindow *Amazul)
    {
        Amazul->setWindowTitle(QApplication::translate("Amazul", "Amazul", 0));
#ifndef QT_NO_TOOLTIP
        pbSearch->setToolTip(QApplication::translate("Amazul", "Buscar alumnas", 0));
#endif // QT_NO_TOOLTIP
        pbSearch->setText(QApplication::translate("Amazul", "Buscar", 0));
        pbSearch->setShortcut(QApplication::translate("Amazul", "Ctrl+B", 0));
#ifndef QT_NO_TOOLTIP
        pbAdd->setToolTip(QApplication::translate("Amazul", "Agregar una alumna", 0));
#endif // QT_NO_TOOLTIP
        pbAdd->setText(QApplication::translate("Amazul", "Agregar", 0));
#ifndef QT_NO_TOOLTIP
        pbDel->setToolTip(QApplication::translate("Amazul", "Eliminar alumna seleccionada", 0));
#endif // QT_NO_TOOLTIP
        pbDel->setText(QApplication::translate("Amazul", "Eliminar", 0));
        pbPreview->setText(QApplication::translate("Amazul", "Vista Previa", 0));
        pbPreview->setShortcut(QApplication::translate("Amazul", "Ctrl+P", 0));
#ifndef QT_NO_TOOLTIP
        pbPrintAll->setToolTip(QApplication::translate("Amazul", "Marcar todos para imprimir", 0));
#endif // QT_NO_TOOLTIP
        pbPrintAll->setText(QApplication::translate("Amazul", "Todos", 0));
        pbPrintAll->setShortcut(QApplication::translate("Amazul", "Ctrl+P", 0));
        lePhone1->setText(QString());
        lePhone1->setPlaceholderText(QApplication::translate("Amazul", "Tel\303\251fono", 0));
        leLabel1->setText(QString());
        leLabel1->setPlaceholderText(QApplication::translate("Amazul", "Etiqueta", 0));
        lePhone2->setText(QString());
        lePhone2->setPlaceholderText(QApplication::translate("Amazul", "Tel\303\251fono", 0));
        lePhone3->setText(QString());
        lePhone3->setPlaceholderText(QApplication::translate("Amazul", "Tel\303\251fono", 0));
        leName->setPlaceholderText(QApplication::translate("Amazul", "Nombre", 0));
        leLabel2->setText(QString());
        leLabel2->setPlaceholderText(QApplication::translate("Amazul", "Etiqueta", 0));
        leCity->setPlaceholderText(QApplication::translate("Amazul", "Ciudad", 0));
#ifndef QT_NO_TOOLTIP
        pbMap->setToolTip(QApplication::translate("Amazul", "Ver mapa", 0));
#endif // QT_NO_TOOLTIP
        leAddress->setText(QString());
        leAddress->setPlaceholderText(QApplication::translate("Amazul", "Direcci\303\263n", 0));
        leLabel3->setText(QString());
        leLabel3->setPlaceholderText(QApplication::translate("Amazul", "Etiqueta", 0));
#ifndef QT_NO_TOOLTIP
        pbSave->setToolTip(QApplication::translate("Amazul", "Guardar cambios", 0));
#endif // QT_NO_TOOLTIP
        pbSave->setText(QApplication::translate("Amazul", "Guardar", 0));
        pbSave->setShortcut(QApplication::translate("Amazul", "Ctrl+G", 0));
#ifndef QT_NO_TOOLTIP
        pbUndo->setToolTip(QApplication::translate("Amazul", "Deshacer cambios", 0));
#endif // QT_NO_TOOLTIP
        pbUndo->setText(QApplication::translate("Amazul", "Deshacer", 0));
        pbUndo->setShortcut(QApplication::translate("Amazul", "Ctrl+Z", 0));
    } // retranslateUi

};

namespace Ui {
    class Amazul: public Ui_Amazul {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMAZUL_H
