#ifndef BLUETOOTHSEARCHTHREAD_HPP
#define BLUETOOTHSEARCHTHREAD_HPP

#include <QtGui>

class BluetoothSearchThread : public QThread {

Q_OBJECT

public:
  BluetoothSearchThread();
  ~BluetoothSearchThread();
  void run();

signals:
  void deviceFound(QString addr, QString name);

};

#endif
