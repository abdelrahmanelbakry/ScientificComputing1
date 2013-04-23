#-------------------------------------------------
#
# Project created by QtCreator 2013-04-09T00:23:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseWork1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    linearregression.cpp

HEADERS  += mainwindow.h \
    cmatrix.h \
    cvector.h \
    controller.h \
    linearregression.h \
    Utils.h

FORMS    += mainwindow.ui
