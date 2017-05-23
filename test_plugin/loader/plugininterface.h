#ifndef PLUGININTERFACE
#define PLUGININTERFACE
#include <QDebug>

#include <QObject>
#include <QtPlugin>
#include <QMetaType>
#include <QMetaProperty>

#include <QVariant>

#include "myqobject.h"

//QT_BEGIN_NAMESPACE

 class PluginInterface : public QObject
  {
    Q_OBJECT
  public:
    virtual bool pubFunc1(MyQObject &link){
      qDebug() << this->metaObject()->className() << link.objectName();
      return true;}
    //virtual bool pubFunc();
    //bool pubFunc(){return true;}
    //bool pubFunc();
    //MyQObject myObj;
  };
  Q_DECLARE_INTERFACE(PluginInterface, "myplugin/1.0")
  Q_DECLARE_METATYPE(PluginInterface*)
  //Q_PLUGIN_METADATA(IID "myplugin/1.0")

//QT_END_NAMESPACE

#endif // PLUGININTERFACE
