#pragma once

#ifndef EEGMANAGER_HPP
#define EEGMANAGER_HPP

#include <QtGui>
#include <iostream>
#include <fstream>
#include "eegData.hpp"
#include "../eeg/eegHeadset.hpp"
#include <math.h>

/**
 * EEGManager
 *
 * Manager class for EEG retrieval and collection.
 * @TODO Write more documentation here once class is fully defined.
 * @TODO Move dataTransmitting boolean to HeadsetManager.
 *       Requires HeadsetObject be an object.
 */
class EEGManager : public QObject {

  Q_OBJECT

public: 
  EEGManager(int numChannels, EEGHeadset *headset);
  EEGManager(int numChannels, EEGHeadset *headset, int samples);
  ~EEGManager();
  EEGData* getEEGData();
  EEGHeadset* getHeadsetDevice();
  int getNumChannels();
  void filterIIR(double* filt_b, double* filt_a, int start, int channel);
  float filterIIRn(double* filt_b, double* filt_a, float data, int channel);
  float filterIIRb(double* filt_b, double* filt_a, float data, int channel);
  //getHeadsetProperties? @TODO

signals:
  void dataUpdated();
  void sampleReceived(int);
    
public slots:
  void startDataCollection();
  void stopDataCollection();
  void updateData(int newX, int newY, int channel);
  void deleteRange(int startPos, int endPos, int channel);
  void insertRange(QList<eegDatum> data, int startPos, int channel);
  void updateXValues(int startValue, int channel);
  void undo();
  void redo();
  void changeNotch(char*);
  void changeBandpass(char*);
  /*The following two methods may be better suited GUI level*/
  //undo()
  //redo()

  /*These may be useful if headsets have metadata added to the classes
   otherwise they are probably excessive for now.*/
  //setHeadsetDevice()
  //setHeadsetProperties()
  //headsetHasNewData() //Probably not

  void resetData();

private:
  char* bp;
  char* notch;
  bool fftCalculating;
  int numSamples;
  int numChannels;
  EEGData *data;
  EEGHeadset *headset;
  bool headsetTransmitting;
  QStack<QList<eegDatum> > undoStack;
  QStack<QList<eegDatum> > redoStack;
};

#endif

/*
 Things to take from EEGDisplayWidget, and how to implemented them.

 eegData struct list:
   This NEEDS to be its own object. The manager
   will then instantiate the object and path suitable references as
   required. One modification that will need to be made is to
   channel data. For the most part it will be straightforward, the
   only consideration left is whether markers should be global
   or channel specific. Or even both.
   
 void draw:
   Functionality and Notes:
     draw has a misleading name. It functions more as a dataUpdate 
     method. The purpose of this method is to append new EEGData to 
     the EEGData list. 
   Proposed Name: 
     void EEGManager::dataUpdate(int currX, int currY, int channel).
   Noted Changes:
     We have dropped the previous values of X and Y as they
     are redundant. The HeadsetManager (currently eegDisplayCProxy)
     will still accept the redundant values, but will not pass
     them on. A new parameter value has been added, channel. This
     will currently be redundant, but will allow for easier porting
     to multi-channel data.
   New Functionality:
     The functionality will be almost the same as draw currently has:
     take the input data and store it in the appropriate data 
     structure. Then send a signal to update. (EEGDisplayWidget will
     accept this signal).

 void paintEvent:
   Functionality and Notes:
     Has a redundant check to see if the displaywidget is using
     a GUI. Of course it should be! The method itself iterates
     over the various data and draws what is required. Nothing will
     be implemented in EEGManager. But one important change should be
     made to EEGData. Make EEGData thread safe. Just put
     mutex responsibly in EEGData and it should be sufficient. 
    
     Other changes would include having private methods to draw
     specific components, so the method isn't as bloated and is
     more explicit
   Proposed Name:
     Same name.
   Noted Changes:
     EEGData must be thread safe.
   New Functionality:
     paintEvent remains implemented in a similar, but not exactly
     same state. Will evolve as the support classes change.

 void addMarker:
   Functionality and Notes:
     Currently, changes the marker at the last index position of data.
     Should be in EEGManager. The Test Suite will call this. 
   Proposed Name:
     void EEGManager::setMarkerAtMostRecent(QString newValue)
   Noted Changes:
     EEGData must be thread safe.
   New Functionality:
     Will call the other setMarker method, specifying the last position
     as a parameter.

 void createMarker, void removeMarkers, void deleteSelectedData:
   Functionality and Notes:
     Modifies the EEGData directly. Methods should still exist, but
     will be stripped of most functionality, having EEGManager 
     handle it instead.
   Proposed Name:
     Names can remain the same.
   Noted Changes:
     Call EEGManager functionality.
   New Functionality:
     EEGManager will need to perform most of the data manipulation
     currently being done by EEGDisplayWidget.
   
 void updateEEGXPos:
   Functionality and Notes:
     Currently updates the x values so they are sequential
     in the EEGData.
   Proposed Name:
     adjustXPos or something?
   Noted Changes:
     Remove ENTIRELY from EEGDisplayWIdget. Add almost entirely
     to EEGManager instead.
   New Functionality:
     No new functionality, just moved filed really.
*/
