#-------------------------------------------------
#
# Project created by QtCreator 2013-04-09T00:23:18
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseWork1
TEMPLATE = app

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000

SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    linearregression.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    cmatrix.h \
    cvector.h \
    controller.h \
    linearregression.h \
    Utils.h \
    qcustomplot.h \
    ifittingtechnique.h

FORMS    += mainwindow.ui
