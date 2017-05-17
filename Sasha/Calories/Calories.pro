#-------------------------------------------------
#
# Project created by QtCreator 2017-05-16T23:44:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calories
TEMPLATE = app


SOURCES += main.cpp\
    interface.cpp \
    product.cpp \
    calculator.cpp \
    loader.cpp

HEADERS  += \
    interface.h \
    product.h \
    calculator.h \
    loader.h

FORMS    += mainwindow.ui
