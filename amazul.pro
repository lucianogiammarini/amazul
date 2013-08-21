#-------------------------------------------------
#
# Project created by QtCreator 2012-06-28T20:00:06
#
#-------------------------------------------------

QT += sql webkitwidgets widgets printsupport

#CONFIG += debug warn_on
#CONFIG += static

DESTDIR = build
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build

TARGET = amazul
TEMPLATE = app

SOURCES += main.cpp\
	amazul.cpp \
    calendarmodel.cpp \
    calendarwidget.cpp \
    linefilter.cpp \
    studentstablemodel.cpp \
    delegate.cpp \
    studentstableview.cpp \
    printdelegate.cpp \
    sortfilterproxymodel.cpp \
    lineedit.cpp \
    pdfcreator.cpp \
    pagesizedialog.cpp \
    combobox.cpp

HEADERS  += amazul.h \
    calendarmodel.h \
    calendarwidget.h \
    linefilter.h \
    studentstablemodel.h \
    delegate.h \
    studentstableview.h \
    printdelegate.h \
    sortfilterproxymodel.h \
    lineedit.h \
    htmlConstants.h \
    pdfcreator.h \
    pagesizedialog.h \
    combobox.h

FORMS    += amazul.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
	amazul_db

#include(./libs/qtsingleapplication-2.6-opensource/src/qtsingleapplication.pri)
