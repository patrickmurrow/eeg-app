#include <QtGui>
#include "eegData.hpp"

/**
 * @TODO MULTI-THREADING safety!
 */

/**
 * EEGData
 *
 * Constructs an empty list of EEGData with the specified number
 * of channels.
 *
 * @param numChannels The number of EEG channels.
 */
EEGData::EEGData(int numChannels) {
  this->data = new QList<QList<eegDatum> *>();
  for (int i = 0; i < numChannels; i++) {
    QList<eegDatum> *temp = new QList<eegDatum>();
    this->data->append(temp);
  }
}

/**
 * ~EEGData
 *
 * Destroys the EEGData lists. All references to this object
 * and the data it contains become invalid.
 */
EEGData::~EEGData() {
  for (int i = 0; i < this->data->length(); i++) {
    QList<eegDatum> *channel = (this->data->at(i));
    channel->length();
    delete channel;
  }
  delete this->data;
}

/**
 * getNumChannels
 *
 * Returns the maximum number of EEG channels that can be used.
 *
 * return The number of channels, as passed to the constructor.
 */
int EEGData::getNumChannels() {
  return this->data->length();
}

/**
 * getLengthOfChannel
 *
 * Returns the number of data points, stored in the specified
 * channel, that there are.
 *
 * @param channel The channel to get the length of.
 * @return The length of the specified channel.
 */
int EEGData::getLengthOfChannel(int channel) {
  return this->data->value(channel)->length();
}

/**
 * getChannel
 *
 * Returns a reference to a particular EEG data channel.
 *
 * @param channel The channel to get.
 * @return A reference to the EEG data channel.
 */
QList<eegDatum>* EEGData::getChannel(int channel) {
  return this->data->value(channel);
}

/**
 * getDataInChannel
 *
 * Returns the EEG data point from a particular channel and 
 * position.
 *
 * @param channel The channel to retrieve data from.
 * @param pos The position to retrieve data from.
 * @return The data in the specified position.
 */
eegDatum EEGData::getDataInChannel(int channel, int pos) {
  return this->data->value(channel)->value(pos);
}

/**
 * insert
 *
 * Inserts EEG data into the specified channel and position.
 *
 * @param data The EEG data to add.
 * @param channel The channel to add data to.
 * @pos The position to add the data at.
 */
void EEGData::insert(eegDatum data, int channel, int pos) {
  this->data->value(channel)->insert(pos, data);
}

/**
 * append
 *
 * Appends EEG data into the specified channel.
 *
 * @param data The EEG data to add.
 * @param channel The channel to add data to.
 */
void EEGData::append(eegDatum data, int channel) {
  this->data->value(channel)->append(data);
}

/**
 * replace
 *
 * Replaces the EEG data at the specified position with the
 * input EEG data.
 *
 * @param data The new data to insert.
 * @param channel The channel to add data to.
 * @param pos The position to replace data at.
 */
void EEGData::replace(eegDatum data, int channel, int pos) {
  this->data->value(channel)->replace(pos, data);
}

/**
 * remove
 *
 * Removes the EEG data from a speicifc channel and position.
 *
 * @param channel The channel to remove data from.
 * @param pos The position to remove data from.
 */
void EEGData::remove(int channel, int pos) {
  this->data->value(channel)->removeAt(pos);
}

/**
 * setMarker
 *
 * Sets the marker of the specified EEG data unit with the
 * input marker text.
 *
 * @param channel The channel the target EEG data is in.
 * @param pos The position in the channel the target EEG is.
 * @param mText The new marker text, to replace the old text.
 */
void EEGData::setMarker(int channel, int pos, QString mText) {
  struct eegDatum temp;
  temp = this->getDataInChannel(channel, pos);
  temp.marker = mText;
  this->replace(temp, channel, pos);
}

/**
 * removeMarker
 *
 * Removes the marker at the specified location.
 *
 * @param channel The channel of the data to remove the marker of.
 * @param pos The position of the data to remove the marker of.
 */
void EEGData::removeMarker(int channel, int pos) {
  this->setMarker(channel, pos, QString());
}
