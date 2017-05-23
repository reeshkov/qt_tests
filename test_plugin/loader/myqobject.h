#ifndef MYQOBJECT_H
#define MYQOBJECT_H

#include <QObject>
#include <QDebug>

class MyQObject : public QObject
{
  Q_OBJECT
public:
  explicit MyQObject(QObject *parent = 0);
  int testCalll();
  int testInt;
  int(*pTest)();
signals:

public slots:
 private:
// int testCalll();

};

Q_DECLARE_METATYPE(MyQObject*)

#endif // MYQOBJECT_H

