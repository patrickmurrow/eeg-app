#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <QtGui>
#include "bluetoothManager.hpp"
#include "bluetoothSearchThread.hpp"
#include "bluetoothConnectThread.hpp"

/***/
BluetoothManager::BluetoothManager() {
  this->currentlySearching = false;
  this->currentlyConnecting = false;
} 

/***/
BluetoothManager::~BluetoothManager() {
  if (currentlyConnecting) {
    delete this->connectThread;
  }
}

/**
 * startSearch
 *
 * Creates a thread to perform a search for bluetooth devices.
 * Only one search thread may run at a time.
 */
void BluetoothManager::startSearch() {
  this->searchMtx.lock();
  if (this->currentlySearching) {
    printf("Search already in progress.\n");
  } else {
    printf("Search beginning!\n");
    BluetoothSearchThread *thread = new BluetoothSearchThread();
    connect(thread, SIGNAL(deviceFound(QString, QString)),
	    this, SIGNAL(deviceFound(QString, QString)));
    connect(thread, SIGNAL(finished()),
	    this, SLOT(searchFinished()));
    thread->start();
    this->currentlySearching = true;
  }
  this->searchMtx.unlock();
}

/**
 * searchFinished
 *
 * Called once the a bluetooth search has finished.
 * Sets the flags to allow for another search to begin.
 */
void BluetoothManager::searchFinished() {
  this->searchMtx.lock();
  this->currentlySearching = false;
  this->searchMtx.unlock();
  this->searchFinishedSig();
  printf("Search finished\n");
}

/**
 * Establishes a bluetooth connection to the specified device
 * by creating a new thread to hold the connection.
 *
 * As of now, only supports a single connection at a time.
 *
 * @param serialPath The serial port to use, e.g. /dev/rfcomm0
 * @param addr The bluetooth address of the device, e.g. 8C:DE:52:12:7D
 * @param channel The channel to connect to. Valid channels are 1-30.
 */
void BluetoothManager::connectToDevice(QString serialPath, QString addr,
				       int channel) {
  if (!this->currentlyConnecting) {
    this->connectThread = new BluetoothConnectThread(serialPath,
						     addr,
						     channel);
    this->connectThread->start();
    this->currentlyConnecting = true;
  }
  printf("BluetoothManager Done...\n");
}

/**
 * Closes the bluetooth connect with the specified parameters.
 * Currently, will only be able to close connections that were
 * opened in the application.
 *
 * @param serialPath The serial port that was used. e.g. /dev/rfcomm0
 * @param addr The addr of the device connected to. e.g. 8C:DE:52:12:7D
 */
void BluetoothManager::closeConnection(QString serialPath,
					QString addr) {
  
}
