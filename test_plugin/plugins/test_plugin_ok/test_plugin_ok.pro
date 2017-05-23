QT       += core
QT       -= gui


TARGET = test_plugin_ok
TEMPLATE = lib
#CONFIG += static

SUPPORT_DEVICES = AM335X NESO PC
include(../plugins.pri)

INCLUDEPATH    += ../../loader
HEADERS += ../../loader/plugininterface.h
HEADERS += ../../loader/myqobject.h

SOURCES += test_plugin_ok.cpp

HEADERS += test_plugin_ok.h

message(Plugins $$TARGET headers:$$join(HEADERS, $$CR, $$CR, $$CR) )
