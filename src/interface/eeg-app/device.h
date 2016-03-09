#ifndef DEVICE_H
#define DEVICE_H
#include <QtGui>



class Device : public QObject
{
    Q_OBJECT
public:
    Device(QString addr, QString name);
    ~Device();
    QString getAddress();
    QString getName();

private:
    QString addr;
    QString name;

};

#include <QMetaType>
Q_DECLARE_METATYPE(Device*)

#endif // DEVICE_H


