#include <QtGui>
#include <iostream>
#include <fstream>
#include <cstring>
#include "eegManager.hpp"
#include "headsetManager.hpp"

//EEG output file
std::ofstream outputFile("rawEEG.txt");

enum notchState {NNO=0, N50, N60};
enum bandpassState {BPNO=0, BP150, BP713, BP1550, BP550};

enum notchState nState;
enum bandpassState bpState;

int Nback = 5;

std::vector<std::vector<double> > prev_y;
std::vector<std::vector<double> > prev_x;
std::vector<std::vector<double> > prev_y_b;
std::vector<std::vector<double> > prev_x_b;

/**
 * EEGManager
 *
 * Constructs a new EEGManager object, instantiating the 
 * EEGData with the num of channels provided.
 *
 * @param numChannels The number of channels to record EEG data.
 * @param headset A reference to the headset to read from.
 */
EEGManager::EEGManager(int numChannels, EEGHeadset *headset) {
  this->fftCalculating = false;
  this->numChannels = numChannels;
  this->data = new EEGData(numChannels);
  initHeadset(this, headset);
  this->headsetTransmitting = false;
  this->bp = "No BP Filter";
  this->notch = "No Notch";

  prev_y.resize(numChannels);
  for (int i = 0; i < numChannels; i++) prev_y[i].resize(Nback);
  prev_x.resize(numChannels);
  for (int i = 0; i < numChannels; i++) prev_x[i].resize(Nback);
  prev_y_b.resize(numChannels);
  for (int i = 0; i < numChannels; i++) prev_y_b[i].resize(Nback);
  prev_x_b.resize(numChannels);
  for (int i = 0; i < numChannels; i++) prev_x_b[i].resize(Nback);
}

EEGManager::EEGManager(int numChannels, EEGHeadset *headset, int samples) {
  this->fftCalculating = true;
  this->numSamples = samples;
  this->numChannels = numChannels;
  this->data = new EEGData(numChannels);
  initHeadset(this, headset);
  this->headsetTransmitting = false;
  this->bp = "No BP Filter";
  this->notch = "No Notch";

  prev_y.resize(numChannels);
  for (int i = 0; i < numChannels; i++) prev_y[i].resize(Nback);
  prev_x.resize(numChannels);
  for (int i = 0; i < numChannels; i++) prev_x[i].resize(Nback);
  prev_y_b.resize(numChannels);
  for (int i = 0; i < numChannels; i++) prev_y_b[i].resize(Nback);
  prev_x_b.resize(numChannels);
  for (int i = 0; i < numChannels; i++) prev_x_b[i].resize(Nback);
}

/**
 * ~EEGManager
 *
 * Destroys this EEGManager. All references to it's contained 
 * information becomes invalid, *including EEGData*, copy to
 * a new object if necessary to save.
 */
EEGManager::~EEGManager() {
  if (this->headsetTransmitting) {
    this->stopDataCollection();
  }
  delete this->data;
  shutdownHeadset();
}

/**
 * getEEGData
 *
 * Returns a reference to where the EEGData is being stored.
 * Recommended for read use *only*.
 *
 * @return A reference to an EEGData object.
 */
EEGData* EEGManager::getEEGData() {
  return this->data;
}


EEGHeadset* EEGManager::getHeadsetDevice(){
    return this->headset;
}

int EEGManager::getNumChannels(){
    return numChannels;
}

/**
 * startDataCollection
 *
 * Signal to the EEG headset to begin transmitting data.
 * The EEGManager will automatically save data to an EEGData object
 * and trigger the signal dataUpdated when receiving data.
 */
void EEGManager::startDataCollection() {
  if (!this->headsetTransmitting) {
    printf("EEGManager::startDataCollection\n");
    this->headsetTransmitting = true;
    startHeadset();
  }
}

/**
 * stopDataCollection
 *
 * Signal to thee EEG headset to stop transmitting data.
 */
void EEGManager::stopDataCollection() {
  if (this->headsetTransmitting) {
    printf("EEGManager::stopDataCollection\n");
    this->headsetTransmitting = false;
    stopHeadset();
  }
}


/**
 * @brief EEGManager::changeBandpass - Adjusts which filter coefficients to use in filtering
 * @param bpIn - Input from a combobox which triggers this slot when changed
 */
void EEGManager::changeBandpass(char * bpIn){
    if (bpIn[0] == '1' && bpIn[1] == '-'){
        bpState = BP150;
    }
    else if(bpIn[0] == '7'){
        bpState = BP713;

    }
    else if(bpIn[0] == '1' && bpIn[1] == '5'){
        bpState = BP1550;

    }
    else if(bpIn[0] == '5'){
        bpState = BP550;

    }
    else{
        bpState = BPNO;
    }
    this->bp = bpIn;
}

/**
 * @brief EEGManager::changeNotch - Adjusts which filter coefficients to use in filtering
 * @param notchIn - Input from a combobox which triggers this slot when changed
 */
void EEGManager::changeNotch(char * notchIn){
    if (notchIn[0] == '5'){
        nState = N50;
    }
    else if(notchIn[0] == '6'){
        nState = N60;

    }
    else{
        nState = NNO;
    }
    this->notch = notchIn;
}

/**
 * @brief EEGManager::filterIIRn - Notch filter - The filter works with a global double vector for each
 *   channel prev_x/y etc...
 * @param filt_bin - b coefficients
 * @param filt_ain - a coefficients
 * @param data - single data point to be processed
 * @param ch - channel where the data point comes from
 * @return filtered data point
 */
float EEGManager::filterIIRn(double* filt_bin, double* filt_ain, float data, int ch) {

    std::vector<double> filt_b(filt_bin, filt_bin + Nback);
    std::vector<double> filt_a(filt_ain, filt_ain + Nback);

    for (int j = Nback-1; j > 0; j--) {
      prev_y[ch][j] = prev_y[ch][j-1];
      prev_x[ch][j] = prev_x[ch][j-1];
    }

    //add in the new point
    prev_x[ch][0] = data;

    //compute the new data point
    double out = 0;
    for (int j = 0; j < Nback; j++) {
      out += filt_b[j]*prev_x[ch][j];
      if (j > 0) {
        out -= filt_a[j]*prev_y[ch][j];
      }
    }

    //save output value
    prev_y[ch][0] = out;
    data = (float)out;
    return data;
}

/**
 * @brief EEGManager::filterIIRn - Notch filter - The filter works with a global double vector for each
 *   channel prev_x/y etc...
 * @param filt_bin - b coefficients
 * @param filt_ain - a coefficients
 * @param data - single data point to be processed
 * @param ch - channel where the data point comes from
 * @return filtered data point
 */
float EEGManager::filterIIRb(double* filt_bin, double* filt_ain, float data, int ch) {

    std::vector<double> filt_b(filt_bin, filt_bin + Nback);
    std::vector<double> filt_a(filt_ain, filt_ain + Nback);


    for (int j = Nback-1; j > 0; j--) {
      prev_y_b[ch][j] = prev_y_b[ch][j-1];
      prev_x_b[ch][j] = prev_x_b[ch][j-1];
    }

    //add in the new point
    prev_x_b[ch][0] = data;

    //compute the new data point
    double out = 0;
    for (int j = 0; j < Nback; j++) {
      out += filt_b[j]*prev_x_b[ch][j];
      if (j > 0) {
        out -= filt_a[j]*prev_y_b[ch][j];
      }
    }

    //save output value
    prev_y_b[ch][0] = out;
    data = (float)out;
    return data;
}

/**
 * updateData
 *
 * Appends data to the EEG data object.
 * Typically used by HeadsetManager.
 *
 * @param newX The x value to append.
 * @param newY The y value to append.
 * @param channel The channel to append the data to.
 */
void EEGManager::updateData(int newX, int newY, int channel) {

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Filtering -- The data is being filtered before being saved, can easily be moved to post process
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    double *b; //Notch coefficients b
    double *a; //Notch coefficients a
    double *d; //Bandpass coefficients d
    double *c; //Bandpass coefficients c
    switch(nState){
        case N50:
            //50Hz Notch
            b = new double[5]{ 0.96508099, -1.19328255,  2.29902305, -1.19328255,  0.96508099 };
            a = new double[5]{ 1.0       , -1.21449348,  2.29780334, -1.17207163,  0.93138168 };
            break;
        case N60:
            //60Hz Notch
            b = new double[5]{ 9.650809863447347e-001, -2.424683201757643e-001, 1.945391494128786e+000, -2.424683201757643e-001, 9.650809863447347e-001 };
            a = new double[5]{ 1.000000000000000e+000, -2.467782611297853e-001, 1.944171784691352e+000, -2.381583792217435e-001, 9.313816821269039e-001  };
            break;
        case NNO:
            //No Notch
            b = new double[5]{1.0,1.0,1.0,1.0,1.0};
            a = new double[5]{1.0,1.0,1.0,1.0,1.0};
            break;
    }

    switch(bpState){
        case BP150:
            //1-50Hz Bandpass
            d = new double[5]{ 2.001387256580675e-001, 0.0f, -4.002774513161350e-001, 0.0f, 2.001387256580675e-001};
            c = new double[5]{ 1.0f, -2.355934631131582e+000, 1.941257088655214e+000, -7.847063755334187e-001, 1.999076052968340e-001};
            break;
        case BP713:
            //7-13Hz Bandpass
            d = new double[5]{ 5.129268366104263e-003, 0.0f, -1.025853673220853e-002, 0.0f, 5.129268366104263e-003};
            c = new double[5]{ 1.0f, -3.678895469764040e+000, 5.179700413522124e+000, -3.305801890016702e+000, 8.079495914209149e-001};
            break;
        case BP1550:
            //15-50 Hz Bandpass
            d = new double[5]{ 1.173510367246093e-001, 0.0f, -2.347020734492186e-001, 0.0f, 1.173510367246093e-001};
            c = new double[5]{ 1.0f, -2.137430180172061e+000, 2.038578008108517e+000, -1.070144399200925e+000, 2.946365275879138e-001};
            break;
        case BP550:
            //5-50 Hz Bandpass
            d = new double[5]{  1.750876436721012e-001, 0.0f, -3.501752873442023e-001, 0.0f, 1.750876436721012e-001};
            c = new double[5]{ 1.0f, -2.299055356038497e+000, 1.967497759984450e+000, -8.748055564494800e-001, 2.196539839136946e-001};
            break;
        case BPNO:
            //No Bandpass
            d = new double[5]{1.0,1.0,1.0,1.0,1.0};
            c = new double[5] {1.0,1.0,1.0,1.0,1.0};
            break;
    }



  float notched = this->filterIIRn(b,a,(float)newY, channel);
  float bandpassed = this->filterIIRb(d,c,notched, channel);
  QPoint data = QPoint(newX, (int)bandpassed);//newY);
  struct eegDatum newData;
  newData.pt = data;
  newData.marker = QString("");
  int length = this->data->getLengthOfChannel(channel);

  //Triggers FFT calculating (FFTCalc.cpp)
  if (fftCalculating && length>512 && channel == numChannels-1 && length%numSamples == 0 ){
      emit sampleReceived(length);
      fftCalculating = false;
  }
  else if(numSamples > 1 && length%numSamples != 0){
      fftCalculating = true;
  }
  //printf("Length: %d\t New X: %d\t New Y: %d\t Channel: %d, Filtered: %f\n", length, newX, newY, channel, bandpassed);

  //Adds to output file
  if (newX > 23){
      std::string result;
      char numstr[21];
      std::string pRet = "\n";
      sprintf(numstr, "%d", newY);
      result = numstr + pRet;
      outputFile << result;
  }


  this->data->append(newData, channel);
}




/**
 * deleteRange
 *
 * Deletes all the EEG data stored between the specified positions in
 * the specified channel.
 *
 * Deletes from startPos (inclusive) upto but not including endPos.
 * i.e. A call from 0 to the channel length will delete all data.
 * Updates x values after deletion
 *
 * Silently fails if the parameters are invalid.
 *
 * @param startPos The starting position in the data to delete from.
 * @param endPos The ending position to delete to.
 * @param channel The channel to delete data from.
 * @TODO Add exception to silent failure.
 */
void EEGManager::deleteRange(int startPos, int endPos, int channel) {
  if (startPos > endPos || startPos < 0) {
    return;
  } else {
    //The list shrinks on each delete, so the position does not
    //need to increment to delete all the required data.
    QList<eegDatum> undoList;
    int deletePos = startPos; 
    for (int count = startPos; count < endPos; count++) {
      eegDatum datum = this->data->getDataInChannel(channel, deletePos);
      undoList.append(datum);
      this->data->remove(channel, deletePos);
    }
    this->updateXValues(0, channel);
    //add a new eegdatum which holds reference to the start position (x) of
    //the deletion and the channel (y)
    eegDatum meta;
    meta.pt.setX(0);
    meta.pt.setY(channel);
    undoList.append(meta);
    undoStack.push(undoList);
  }
}

/**
 * insertRange
 *
 * Inserts EEG data into this instances data starting at a given
 * position for the specified channel
 *
 * Inserts into the current data after the given start position
 * The data which comes after the start position will now follow
 * the last datum from the inserted data
 *
 * @param inData The data to be inserted into the current set
 * @param startPos The position in the data to start insertion
 * @param channel The channel to delete data from.
 */
void EEGManager::insertRange(QList<eegDatum> inData, int startPos, int channel){
  if (startPos < 0){
    return;
  } else {
      for(int i = 0; i < inData.size(); i++) {
        eegDatum currData = inData.value(i);
        this->data->insert(currData, channel, startPos);
        startPos++;
        //off by one?
    }
        
  }
}

/**
 * updateXValues
 *
 * Iterates over all of the available eegData and updates 
 * the eeg data to have consistent x values.
 *
 * Example using startValue = 1:
 *   - Old data: 9, 10, 13, 14.
 *   - New data: 1, 2, 3, 4.
 *
 * @param startValue The value to increment the x values from.
 * @param channel The channel to update x values of.
 */
void EEGManager::updateXValues(int startValue, int channel) {
  for(int i = 0; i < this->data->getLengthOfChannel(channel); i++) {
    eegDatum currData = this->data->getDataInChannel(channel, i);
    currData.pt.setX(startValue+i);
    this->data->replace(currData, channel, i);
  }
}

/**
 * resetData
 *
 * Resets all the EEG data. Any references to the EEG data become
 * invalid and must be retrieved again if used outside of EEGManager.
 *
 * There are occurances where the old EEG data automatically maintains
 * reference to the new EEG data. This is *not* guranteed and does
 * not always occur. Please exercise caution.
 */
void EEGManager::resetData() {
  //@TODO
  //Check if running and pause connection if so?
  int numChannels = this->data->getNumChannels();
  delete this->data;
  this->data = new EEGData(numChannels);
}

/**
 * undo
 *
 * Implements an undo function which utilizes an undo stack and
 * "undoes" the previously executed step
 *
 * Pops the previous step off the undo stack and re-inserts the
 * data that is held in the stack, the last eegDatum holds a 
 * reference to the channel so is deleted before it is passed to 
 * the insertRange function
 */
void EEGManager::undo(){
  QList<eegDatum> toUndo = undoStack.pop();
  int endPos = toUndo.length()-1;
  int channel = toUndo.at(endPos).pt.y();
  redoStack.push(toUndo);
  toUndo.removeLast();
  int startPos = toUndo.at(0).pt.x();
  this->insertRange(toUndo, startPos, channel);
}

/**
 * redo
 *
 * Implements a redo function which utilizes a redo stack and
 * "redoes" the previously undone step
 *
 * Pops the undone step off the redo stack and re-deletes the
 * data that was previously inserted, the last eegDatum holds a 
 * reference to the channel so is deleted before it is passed to 
 * the deleteRange function
 */
void EEGManager::redo(){
  QList<eegDatum> toRedo = redoStack.pop();
  int endPos = toRedo.length()-1;
  int channel = toRedo.at(endPos).pt.y();
  undoStack.push(toRedo);
  toRedo.removeLast();
  endPos = toRedo.length()-1;
  int startDelete = toRedo.at(0).pt.x();
  int endDelete = toRedo.at(endPos).pt.x();
  printf("sD: %d   eD: %d\n", startDelete, endDelete);
  this->deleteRange(startDelete, endDelete, channel);
}
