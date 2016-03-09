#pragma once

#ifndef EEGDISPLAYDIALOG_H
#define EEGDISPLAYDIALOG_H

#include "../../util/eeg/eegManager.hpp"
#include "../../eeg/eegHeadset.hpp"
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class EEGDisplayDialog;
}

class EEGDisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EEGDisplayDialog(QWidget *parent = 0);
    explicit EEGDisplayDialog(QWidget *parent, EEGManager *manIn);
    ~EEGDisplayDialog();

private:
    Ui::EEGDisplayDialog *ui;
    int normalizePoint(int rawY, double range);

protected:
    void paintEvent(QPaintEvent *e);

signals:
  void displayStarted();
  void notchChanged(char*);
  void bandpassChanged(char*);
private slots:
    void on_btnStart_clicked();
    void updateDisplay();
    void updateRange();
    void on_btnStop_clicked();
    void on_cmbNotch_activated(const QString &notch);
    void on_cmbBandpass_activated(const QString &bp);
    void on_cmbChannels_activated(int displayNumIn);
    void on_cmbSpeed_activated(const QString &speedIn);

private:
    EEGHeadset *hs;
    EEGManager *eMgr;
    bool collectionStarted;
};

#endif // EEGDISPLAYDIALOG_H
