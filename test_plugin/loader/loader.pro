QT += core
QT += gui
QT += widgets

DESTDIR    = ../
TARGET = ploader
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    pluginsloader.cpp \
    myqobject.cpp

HEADERS += \
    pluginsloader.h \
    plugininterface.h \
    myqobject.h

