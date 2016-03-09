#include "dummyHS.hpp"
#include <unistd.h>

DummyHS::DummyHS() {
  //init counter?
}

DummyHS::~DummyHS() {
   delete this->gen;
}

void DummyHS::drawData(int x1, int y1, int x2, int y2,
		       int color, int channel) {
  //do nothing?
}

void DummyHS::startSerial() {
  //will need to create a thread for the serial and parser
  this->gen = new DummyGenerator();
  this->gen->start();
}

void DummyHS::stopSerial() {
  //stop that thread.
  this->gen->stop();
  //::sleep(1);
}
