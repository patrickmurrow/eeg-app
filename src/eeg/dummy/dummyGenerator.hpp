#pragma once

#include <QtGui>

/**
 * DummyGenerator
 *
 * A thread which transmits the natural numbers as if it is an
 * EEG headset.
 */
class DummyGenerator: public QThread {

  Q_OBJECT
  
public:
  DummyGenerator();
  ~DummyGenerator();
  void stop();
  void run();

private:
  bool running;
  QMutex runningMtx;

};
