#ifndef PLUGINSLOADER_H
#define PLUGINSLOADER_H

#include <QDebug>

#include "plugininterface.h"

#include <QPluginLoader>
#include <QDir>
#include <QThread>

class PluginsLoader : public QObject
{
  Q_OBJECT
public:
  explicit PluginsLoader(QObject*);
  ~PluginsLoader();
  MyQObject mqo;
signals:
  void sigPluginLoaded(QString);
  void loadfinished();
public slots:
  void loadPlugins();
private:
  QDir pluginsDir;
  QObject *container;
private slots:
  void handleUnloadPlugin();
};

#endif // PLUGINSLOADER_H
