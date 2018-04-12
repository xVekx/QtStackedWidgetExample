#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T21:21:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtStackedWidgetExample
TEMPLATE = app


SOURCES += main.cpp\
        mw.cpp \
    mode1.cpp \
    mode2.cpp \
    mode3.cpp \
    mode4.cpp \
    modewidget.cpp

HEADERS  += mw.h \
    mode1.h \
    mode2.h \
    mode3.h \
    mode4.h \
    modewidget.h

FORMS    += mw.ui \
    mode1.ui \
    mode2.ui \
    mode3.ui \
    mode4.ui
