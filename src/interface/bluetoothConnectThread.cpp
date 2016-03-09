#include "bluetoothConnectThread.hpp"
#include <QtGui>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * BluetoothConnectThread
 *
 * Constructs the object and stores parameters as data fields.
 * @param serialpath The serial address to use in the connection.
 * @param addr The bluetooth address to use in the connection.
 * @param channel The channel of the bluetooth connection.
 */
BluetoothConnectThread::BluetoothConnectThread(QString serialPath,
					       QString addr,
					       int channel) {
  this->serialPath = serialPath;
  this->addr = addr;
  this->channel = channel;
}

/**
 * ~BluetoothConnectThread
 *
 * Destructor, calls scripts to release devices/files used.
 */
BluetoothConnectThread::~BluetoothConnectThread() {
  kill(this->connectScript->pid(),2);
  delete this->connectScript;
  system("bash scripts/cleanupBluetooth");
  printf("...Cleanup Complete\n");
}

/**
 * run
 *
 * Calls the required scripts to create the bluetooth conneciton.
 */ 
void BluetoothConnectThread::run() {
  printf("Initialising Bluetooth Connection!\n");
  //system(QString("bash scripts/connect2Bluetooth %1 %2 %3").arg(serialPath).arg(addr).arg(channel).toLatin1());
  //printf("Done\n");
  QString script = QString("bash scripts/connect2Bluetooth %1 %2 %3").arg(serialPath).arg(addr).arg(channel).toLatin1();
  this->connectScript = new QProcess();
  this->connectScript->start(script);
  printf("Connection Established...\n");
}
