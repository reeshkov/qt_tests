#include "pluginsloader.h"
#include <QApplication>


PluginsLoader::PluginsLoader(QObject *container): container(container)
{
  const QString dirName("plugins");
  pluginsDir = QDir(qApp->applicationDirPath());
  if(!pluginsDir.cd(dirName)) qWarning() << "Plugins: Folder "+ pluginsDir.absolutePath()+dirName +" not exist.";
  else qDebug()<< "Search plugins in: "+pluginsDir.absolutePath();

  QStringList filters;
  filters << "*.so" << "*.dll";
  pluginsDir.setNameFilters(filters);

  qRegisterMetaType<MyQObject*>("MyQObject");
}

PluginsLoader::~PluginsLoader()
{
  qDebug() << "~"+objectName();
}

void PluginsLoader::loadPlugins(){
  qDebug() << objectName()+".loadPlugins() " << "\033[33m" << this << QThread::currentThread() << "\033[0m";
  foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
    qDebug()<< "Found plugin:" << fileName;
    QPluginLoader loader(pluginsDir.absoluteFilePath(fileName),this);
    QObject *oplugin = loader.instance();
    if(oplugin){
      PluginInterface *plugin = qobject_cast<PluginInterface*>(oplugin);
      if(plugin){
        qDebug()<< "Initalize plugin: "+ fileName << oplugin->metaObject()->className();

        qDebug()<< plugin->pubFunc1( mqo );
      }else{
        qWarning() << "Fail cast from plugin: " + fileName << oplugin->metaObject()->className();
        loader.unload();
      }
    }else{
      qWarning() << "Not loaded" << fileName << loader.errorString();
      loader.unload();
    }
  }
  qDebug() << "Loaded plugins: "<< container->dynamicPropertyNames();
  emit loadfinished();
}

void PluginsLoader::handleUnloadPlugin()
{
  qWarning() << " Some plugin unloaded...";
//  foreach(QThread *thread , this->findChildren<QThread*>()){
//    qDebug() << thread;
//  }
//  foreach (const QByteArray &pluginName, container->dynamicPropertyNames()) {
//    qDebug() << QString(pluginName);
//    try{
//      qDebug() << container->property(pluginName.data()).value<QObject*>();
//    }catch(...){
//      qDebug()<< "WTF?:" << QString(pluginName);
//    }
//    container->setProperty(pluginName.data(),QVariant());
//  }
//  foreach (const QByteArray &pluginName, container->dynamicPropertyNames()) {
//    qDebug() << QString(pluginName);
//    //qDebug() << container->property(pluginName.data()).value<QObject*>();
//    qDebug() << container->property(pluginName.data()).canConvert<QObject*>();
//    qDebug() << container->property(pluginName.data()).isValid();
//    qDebug() << container->property(pluginName.data()).isNull();
//    qDebug() << container->property(pluginName.data()).isDetached();
//  }
}
