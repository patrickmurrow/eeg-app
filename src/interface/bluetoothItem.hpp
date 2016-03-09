#include <QtGui>

#ifndef BLUETOOTHITEM_HPP
#define BLUETOOTHITEM_HPP



class BluetoothItem : public QWidget {

  Q_OBJECT

public:
  BluetoothItem(QWidget *parent = 0, QString name = "",
		QString addr = "");
  ~BluetoothItem();
  void mouseReleaseEvent(QMouseEvent *ev);
  QString* getDeviceName();
  QString* getDevicePath();
  void deselect();

signals:
  void isSelected(BluetoothItem *item);

private:
  void initUI();
  
  QString *deviceName;
  QString *devicePath;
  bool isConnected;
  bool isSaved;
  QLabel *nameLabel;
  QLabel *pathLabel;
  QVBoxLayout *layout;
};

#endif
