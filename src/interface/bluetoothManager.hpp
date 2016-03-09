#ifndef BLUETOOTHMANAGER_HPP
#define BLUETOOTHMANAGER_HPP

#include <QtGui>
#include "bluetoothConnectThread.hpp"

//Several operations here will require multi-threading
//Hence, we need to use signals to response to calls.
class BluetoothManager : public QObject {
  
  Q_OBJECT

public:
  BluetoothManager();
  ~BluetoothManager();
  void startSearch();
  void connectToDevice(QString serialPath, QString addr, int channel);
  void closeConnection(QString serialPath, QString addr);

signals:
  void deviceFound(QString addr, QString name);
  void searchFinishedSig();

public slots:
  void searchFinished();
  //void connectionFinished();

private:
  QMutex searchMtx;
  bool currentlySearching;
  bool currentlyConnecting;
  BluetoothConnectThread *connectThread;
};

#endif
