#include "device.h"

Device::Device(QString addr, QString name)
{
    this->addr = addr;
    this->name = name;
}

Device::~Device(){
}

QString Device::getAddress(){
    return addr;
}

QString Device::getName(){
    return name;
}

