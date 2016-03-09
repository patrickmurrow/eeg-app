#include "bluetoothItem.hpp"
#include <stdio.h>
#include <QtGui>

BluetoothItem::BluetoothItem(QWidget *parent, QString name, 
			     QString addr) {
  this->deviceName = new QString(name);
  this->devicePath = new QString(addr);
  this->isConnected = false;
  this->isSaved = false;
  this->setMouseTracking(true);
  this->initUI();
}

BluetoothItem::~BluetoothItem() {
  delete this->deviceName;
  delete this->devicePath;
}

/**
 * initUI
 *
 * Creates the UI for this bluetooth item.
 * Including, background colour, fonts, labels.
 */
void BluetoothItem::initUI() {
  QPalette Pal(palette());
  Pal.setColor(QPalette::Background, Qt::gray);
  this->setFixedHeight(100);
  this->setAutoFillBackground(true);
  this->setPalette(Pal);
  this->show();
  this->nameLabel = new QLabel(*this->deviceName);
  this->pathLabel = new QLabel(*this->devicePath);
  this->layout = new QVBoxLayout(this);
  this->layout->addWidget(this->nameLabel);
  this->layout->addWidget(this->pathLabel);
}

/**
 * mouseReleaseEvent
 *
 * Overriding method, responds to left clicks by selecting
 * the device. 
 * @TODO Respond to right clicks by creating a context menu.
 *
 * @param ev The QMouseEvent* that triggered this call.
 */
void BluetoothItem::mouseReleaseEvent(QMouseEvent *ev) {
  if (ev->button() == Qt::LeftButton) {
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::yellow);
    this->setPalette(Pal);
    this->show();
    this->isSelected(this);
  }
}

/**
 * deselect
 *
 * Notifies this BluetoothItem that it is no longer selected.
 * Responds by adjusting UI elements as appropriate.
 */
void BluetoothItem::deselect() {
  QPalette Pal(palette());
  Pal.setColor(QPalette::Background, Qt::gray);
  this->setPalette(Pal);
  this->show();
}

/**
 * getDeviceName
 *
 * Returns the name of this bluetooth device.
 *
 * @return QString* for the device name.
 */
QString* BluetoothItem::getDeviceName() {
  return this->deviceName;
}

/**
 * getDevicePath
 *
 * Returns the path of this bluetooth device
 *
 * @return QString* for the device path.
 */
QString* BluetoothItem::getDevicePath() {
  return this->devicePath;
}
