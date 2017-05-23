#include "test_plugin_ok.h"

Test_plugin_ok::Test_plugin_ok()
{
  this->setObjectName(this->metaObject()->className());
  qDebug() << "Constructor "+objectName() << "\033[33m" << this << QThread::currentThread() << "\033[0m";
}



bool Test_plugin_ok::pubFunc1(MyQObject *pdata1){
  qDebug() << "Plugin OK"<< this->metaObject()->className();// << pdata1->objectName();
  qDebug() << "Plugin Int 1 ="<< pdata1->testInt;
  pdata1->testInt++;
  qDebug() << "Plugin Int 2 ="<< pdata1->testInt;
//  qDebug() << "Plugin func pointer=" << pdata1->MyQObject::pTest();
  qDebug() << "Plugin func pointer=" << pdata1->pTest();
  qDebug() << "Plugin func=" << pdata1->testCalll();
  return false;
}

Q_EXPORT_PLUGIN2(Test_plugin_ok, Test_plugin_ok)

