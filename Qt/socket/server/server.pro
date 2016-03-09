QT += core network
QT -= gui

TARGET = server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp \
    fortunethread.cpp \
    serverthread.cpp

HEADERS += \
    myserver.h \
    fortunethread.h \
    serverthread.h

