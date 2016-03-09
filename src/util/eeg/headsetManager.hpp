#ifndef HEADSET_MANAGER
#define HEADSET_MANAGER
#include "eegManager.hpp"
#include "../../eeg/eegHeadset.hpp"

/**
 * HeadsetManager
 *
 * An interface between the parser/serial code, and the 
 * EEGManager.
 *
 * Given that this is not an object, extra care should be taken with 
 * this particular file. Try to use EEGManager instead, if possible.
 *
 * The general use case of this class is as follows:
 * 1. Call init(). This sets up the Headset and forwarding info.
 * 2. Call start(). This begins the data transmission.
 * 3. Call stop(). This stops the data transmission.
 * 4. Call shutdown(). This deallocates memory.
 *
 * @TODO Investigate a rework that allows for HeadsetManager
 *       to be an object, while also still being about to
 *       interact with the parser/serial. May require rewriting
 *       parser/serial.
 */

void initHeadset(EEGManager *_eegManager, EEGHeadset *_headset);
void shutdownHeadset();
void startHeadset();
void stopHeadset();
void updateData(int x1, int y1, int x2, int y2, int color);

#endif
