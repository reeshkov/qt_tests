#include <QCoreApplication>

#include "pluginsloader.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  PluginsLoader ploader(&a);
  ploader.loadPlugins();

  return a.exec();
}

