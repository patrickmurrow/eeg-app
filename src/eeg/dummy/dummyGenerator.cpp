/*#include "dummyGenerator.hpp"
#include "../../util/eeg/headsetManager.hpp"

DummyGenerator::DummyGenerator() {
  this->running = true;
}

DummyGenerator::~DummyGenerator() {
  
}

void DummyGenerator::stop() {
  runningMtx.lock();
  this->running = false;
  runningMtx.unlock();
}

void DummyGenerator::run() {
  int currI = 0;
  int prevI;
  runningMtx.lock();
  bool stillRunning = this->running;
  runningMtx.unlock();
  while(stillRunning) {
    prevI = currI;
    currI++;
    updateData(prevI, prevI*2, currI, currI*2, 0);
    runningMtx.lock();
    stillRunning = this->running;
    runningMtx.unlock();
  }
}*/


#include "dummyGenerator.hpp"
#include "../../util/eeg/headsetManager.hpp"

DummyGenerator::DummyGenerator(){
  this->running = true;
}

DummyGenerator::~DummyGenerator(){
 }
 
void DummyGenerator::stop(){
    runningMtx.lock();
    this->running = false;
    runningMtx.unlock();
}

void DummyGenerator::run(){
  int x = 0;
  int y = (rand()%100) + 200;
  runningMtx.lock();
  bool stillRunning = this->running;
  runningMtx.unlock();
  while(stillRunning){
    updateData(x, y, x, y, 0);
    x = x + 1;
    y = (rand()%100) + 200;
    usleep(100000);
    runningMtx.lock();
    stillRunning = this->running;
    runningMtx.unlock();
  }
}
