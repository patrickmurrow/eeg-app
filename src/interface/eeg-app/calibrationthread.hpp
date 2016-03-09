#include <QtGui>


class CalibrationThread: public QThread {

  Q_OBJECT

public:
  CalibrationThread(QObject *parent);//: QThread(parent){}
  ~CalibrationThread();
  void run();
  void stop();

signals:
  void txtChanged(QString msg, int time);
  void startCollect();
  void stopCollect(bool open);
};
