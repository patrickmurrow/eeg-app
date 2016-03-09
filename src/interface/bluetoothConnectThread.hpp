#ifndef BLUETOOTHCONNECTTHREAD_HPP
#define BLUETOOTHCONNECTTHREAD_HPP

#include <QtGui>

/**
 * BluetoothConnectThread
 *
 * A QThread used as a wrapper for a (blocking) BASH script.
 * If the connection fails, the script will continuously reattempt
 * to establish a connection. In order to close the connection, the 
 * thread must be deleted. The destructor handles cleanup.
 */
class BluetoothConnectThread : public QThread {
  
  Q_OBJECT
  
public:
  BluetoothConnectThread(QString serialPath, QString addr, int channel);
  ~BluetoothConnectThread();
  void run();

signals:
  void connectionFinished();
  
private:
  QString serialPath;
  QString addr;
  int channel;
  QProcess *connectScript;
  
};

#endif
