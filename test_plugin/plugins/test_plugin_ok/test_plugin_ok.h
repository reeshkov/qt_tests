#ifndef TEST_PLUGIN_OK_H
#define TEST_PLUGIN_OK_H

#include "plugininterface.h"

#include <QThread>
class MyQObject;
class Test_plugin_ok: public PluginInterface
{
  Q_OBJECT
  Q_INTERFACES(PluginInterface)
public:

  Test_plugin_ok();
  bool pubFunc1(MyQObject&);
};

#endif // TEST_PLUGIN_OK_H
