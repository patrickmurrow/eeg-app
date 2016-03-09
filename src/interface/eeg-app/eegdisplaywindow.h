#ifndef EEGDISPLAYWINDOW_H
#define EEGDISPLAYWINDOW_H

#include <QWidget>

namespace Ui {
class EEGDisplayWindow;
}

class EEGDisplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EEGDisplayWindow(QWidget *parent = 0);
    ~EEGDisplayWindow();

public slots:
    void plotGraph();
    void realTimeDataSlot();

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

private:
    Ui::EEGDisplayWindow *ui;
};

#endif // EEGDISPLAYWINDOW_H
