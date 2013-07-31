#-------------------------------------------------
#
# Project created by QtCreator 2013-07-23T15:57:59
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = QCCS_RPi
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    TQCCSServer.cpp \
    TTcpThread.cpp

HEADERS += \
    TQCCSServer.h \
    TTcpThread.h
