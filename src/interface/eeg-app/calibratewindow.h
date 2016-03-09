#ifndef CALIBRATEWINDOW_H
#define CALIBRATEWINDOW_H

#include <QWidget>
#include "../../util/eeg/eegData.hpp"

namespace Ui {
class CalibrateWindow;
}

class CalibrateWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CalibrateWindow(QWidget *parent = 0);
    ~CalibrateWindow();

private slots:
    void on_btnBack_clicked();
    void on_btnBegin_clicked();
    void txtChanged(QString msg, int time);
    void startDataCollect();
    void stopDataCollect(bool open);

    void on_btnCancel_clicked();

    void on_cmbHeadset_activated(const QString &arg1);

private:
    Ui::CalibrateWindow *ui;
    EEGData *eegEyesOpen;
    EEGData *eegEyesClosed;
};

#endif // CALIBRATEWINDOW_H
