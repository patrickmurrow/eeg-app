#pragma once

class EEGHeadset {

public:
  EEGHeadset();
  ~EEGHeadset();
  virtual void drawData(int x1, int y1, int x2, int y2, int color, int channel) = 0;
  virtual void startSerial() = 0;
  virtual void stopSerial() = 0;
};
