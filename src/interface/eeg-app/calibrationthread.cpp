#include "calibrationthread.hpp"
#include <unistd.h>

CalibrationThread::CalibrationThread(QObject *parent): QThread(parent)
{
}

CalibrationThread::~CalibrationThread(){

}


void CalibrationThread::run() {
    usleep(800000);
    emit txtChanged(".", 10);
    usleep(800000);
    emit txtChanged(" ..", 10);
    usleep(800000);
    emit txtChanged("  ...", 10);
    usleep(800000);
    emit txtChanged(".", 10);
    usleep(800000);
    emit txtChanged(" ..", 10);
    usleep(800000);
    emit txtChanged("  ...", 10);
    usleep(800000);
    emit txtChanged("Fixate on the cross", 10);
    usleep(2000000);
    emit startCollect();
    for(int i = 10; i>0; i--){
        emit txtChanged("+", i);
        usleep(1000000);
    }
    emit stopCollect(true);
    emit txtChanged("Close your eyes for about 10 seconds", 0);
    usleep(2000000);
    emit startCollect();
    for(int i = 10; i>0; i--){
        emit txtChanged("+", i);
        usleep(1000000);
    }
    emit stopCollect(false);
    emit txtChanged("Headset Calibration Complete", 0);
}

void CalibrationThread::stop(){
    txtChanged("Click Begin to Start Calibration", 0);
    this->terminate();
}
