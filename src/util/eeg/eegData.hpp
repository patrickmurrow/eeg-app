#ifndef EEGDATA_HPP
#define EEGDATA_HPP

#include <QtGui>

/**
 * eegDatum
 *
 * The struct for representing EEG Data. Contains a point
 * with x, y coordinates and a marker value.
 */
struct eegDatum {
  QPoint pt;
  QString marker;
};

/**
 * EEGData
 *
 * Container class for EEG data points. 
 * Contains the EEG data from each channel and allows for basic
 * list operations. 
 *
 */
class EEGData : public QObject {

  Q_OBJECT

public:
  EEGData(int numChannels);
  ~EEGData();
  int getNumChannels();
  int getLengthOfChannel(int channel);
  QList<eegDatum>* getChannel(int channel);
  eegDatum getDataInChannel(int channel, int pos);

public slots:
  void insert(eegDatum data, int channel, int pos);
  void append(eegDatum data, int channel);
  void replace(eegDatum data, int channel, int pos);
  void remove(int channel, int pos);
  void setMarker(int channel, int pos, QString mText);
  void removeMarker(int channel, int pos);

private:
  QList<QList<eegDatum> *> *data;

};

#endif
