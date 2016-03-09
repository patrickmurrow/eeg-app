#pragma once

#include "../eegHeadset.hpp"
#include "dummyGenerator.hpp"

/**
 * DummyHS
 *
 * A simulated headset. Does not require Bluetooth in order
 * to transmit a signal. Will transmit a sequence of numbers
 * 1, 2, 3, 4 and so on....
 */
class DummyHS : public EEGHeadset {

public:
  DummyHS();
  ~DummyHS();
  void drawData(int x1, int y1, int x2, int y2, int color, int channel);
  void startSerial();
  void stopSerial();

private:
  DummyGenerator *gen;

};
