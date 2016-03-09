#include "headsetManager.hpp"
#include "../../eeg/brainlink/brainlinkHS.hpp"
#include "../../eeg/eegHeadset.hpp"
#include <stdio.h>
#include <iostream>
#include <sstream>
#define MODEMDEVICE "/dev/rfcomm0"

EEGManager *eegMan;
EEGHeadset *eegHeadset;

/**
 * init
 *
 * Initialises the connection parameters. Specifically:
 * - The headset parameters.
 * - Where to forward the data.
 *
 * @param _eegMan Where to forward the data to.
 */
void initHeadset(EEGManager *_eegMan, EEGHeadset *_headset) {
  eegMan = _eegMan;
  eegHeadset = _headset;
}

/**
 * shutdown
 *
 * Deletes the Headset objects created.
 */
void shutdownHeadset() {
  delete eegHeadset;
}

/**
 * start
 *
 * Signals to the headset to begin forwarding its EEG data.
 */
void startHeadset() {
  printf("startHeadset -> headsetManager\n");
  eegHeadset->startSerial();
}

/**
 * stop
 *
 * Signals to the headset to stop forwarding its EEG data.
 */
void stopHeadset() {
  printf("stopHeadset -> headsetManager\n");
  eegHeadset->stopSerial();
}

/**
 * updateData
 *
 * The headset sends its data to this method.
 * The data is then forwarded to the EEGManager specified in init().
 * Contrary to the method name, this does not actually draw any 
 * data. The name is purely for compatability at this stage.
 *
 * @param x1 The previous x value for EEG data.
 * @param y1 The previous y value for EEG data.
 * @param x2 The current x value for EEG data.
 * @param y2 The current y value for EEG data.
 * @param color The color flag - Unused.
 */
void updateData(int x1, int y1, int x2, int y2, int channel) {
  //std::stringstream stream;
  //stream << x1 << " " << y1 << " " <<  x2 << " " << y2 << "\n";
  //std::cout << stream.str();
  //printf("Hi\n");

  //Temp output mechanism, will be moved to commandlineapp.
  //printf("%d %d\n", x2, y2);
  //end temp
  eegMan->updateData(x2,y2,channel);
}

