#include "myqobject.h"

MyQObject::MyQObject(QObject *parent) : QObject(parent)
{
  setObjectName(metaObject()->className());
  testInt = 42;
  pTest = (int (*)()) (&MyQObject::testCalll);
}

//MyQObject::MyQObject()
//{
//  qDebug() << "Init MyQObject";
//  testInt = 128;
//  pTest = (int (*)())&MyQObject::testCalll;
//}

int MyQObject::testCalll()
{
  qDebug() << "This is test" << testInt;
  return this->testInt;
}
