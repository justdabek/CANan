#-------------------------------------------------
#
# Project created by QtCreator 2019-01-28T17:16:25
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CANan
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canmessage.cpp

HEADERS  += mainwindow.h \
    canmessage.h

FORMS    += mainwindow.ui
