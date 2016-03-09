#include "eegdisplaydialog.h"
#include "ui_eegdisplaydialog.h"
#include "../../util/eeg/eegManager.hpp"
#include "../../eeg/dummy/dummyHS.hpp"
#include "../../eeg/brainlink/brainlinkHS.hpp"
#include "../../eeg/muse/museHS.hpp"
#include "../../eeg/openBCI/openBCIHS.hpp"
#include "../../util/eeg/eegData.hpp"
#include <stdlib.h>
#include <cmath>

//to be set in calibration
int defaultStartY = 10000000;
int defaultEndY = -10000000;

int cy;
int cx;

int startY = defaultStartY;
int endY = defaultEndY;

double dSpeed = 1;

int displayNum = 1;
int cNum = 8;
QTimer *dTimer;
QTimer *resizeTimer;
QColor colours [16];


EEGDisplayDialog::EEGDisplayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EEGDisplayDialog)
{
    ui->setupUi(this);
    setStyleSheet("background-color:#B7B8B7;");
    ui->btnStart->setFocusPolicy(Qt::NoFocus);
    ui->btnStop->setFocusPolicy(Qt::NoFocus);

    this->collectionStarted = false;
    this->hs = new OpenBCIHS();
    this->eMgr = new EEGManager(cNum, hs);
    resizeTimer = new QTimer();
    dTimer = new QTimer();
    for (int i = 0; i < cNum; i++){
        colours[i] = QColor((rand() % 175),(rand() % 175), (rand() % 175));
    }
    connect(resizeTimer, SIGNAL(timeout()), this, SLOT(updateRange()));
    connect(dTimer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
}

EEGDisplayDialog::EEGDisplayDialog(QWidget *parent, EEGManager *manIn) :
    QDialog(parent),
    ui(new Ui::EEGDisplayDialog)
{
    ui->setupUi(this);
    setStyleSheet("background-color:#B7B8B7;");
    ui->btnStart->setFocusPolicy(Qt::NoFocus);
    ui->btnStop->setFocusPolicy(Qt::NoFocus);

    this->collectionStarted = false;
    this->eMgr = manIn;
    this->hs = this->eMgr->getHeadsetDevice();
    cNum = this->eMgr->getNumChannels();
    resizeTimer = new QTimer();
    dTimer = new QTimer();
    for (int i = 0; i < cNum; i++){
        colours[i] = QColor((rand() % 175),(rand() % 175), (rand() % 175));
    }
    connect(resizeTimer, SIGNAL(timeout()), this, SLOT(updateRange()));
    connect(dTimer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
    connect(this, SIGNAL(bandpassChanged(char*)), this->eMgr, SLOT(changeBandpass(char*)));
    connect(this, SIGNAL(notchChanged(char*)), this->eMgr, SLOT(changeNotch(char*)));
}

EEGDisplayDialog::~EEGDisplayDialog()
{
    delete ui;
    delete hs;
    delete eMgr;
}

/**
 * @brief EEGDisplayDialog::normalizePoint - Adjusts each data point to fit on the screen size
 * @param rawY - raw eeg input
 * @param range - highest raw input - lowest raw input
 * @return adjusted raw eeg - relative size to window
 */
int EEGDisplayDialog::normalizePoint(int rawY, double range){
    int height = this->height();
    return (int)std::abs(((rawY-startY)/range)*(height-90));//90 is padding +10
}


//resets range so can zoom in again
void EEGDisplayDialog::updateRange(){
    startY = defaultStartY;
    endY = defaultEndY;
}


void EEGDisplayDialog::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    int padding = 160;
    if (this->collectionStarted){
    EEGData *eData = eMgr->getEEGData();
    double range = std::abs(startY - endY);
    for (int i = 0; i <displayNum; i++){
        int x = (eData->getLengthOfChannel(i)-1) - ((eData->getLengthOfChannel(i)-1)-(this->width()*2));
        painter.setPen(colours[i]);
        for(x; x > 40; x--){
            eegDatum datum = eData->getDataInChannel(i, (eData->getLengthOfChannel(i)-1)-x);
            eegDatum datum2 = eData->getDataInChannel(i, (eData->getLengthOfChannel(i)-1)-(x-1));
            int newY = datum.pt.y();
            if (newY < startY){
                startY = newY;
            }else if (newY > endY){
                endY = newY;
            }
            range = std::abs(startY - endY);
            painter.drawLine(x*dSpeed, normalizePoint(datum.pt.y(), range)/2+padding, (x-1)*dSpeed, normalizePoint(datum2.pt.y(), range)/2+padding);

            //paint without adapting range
            //painter.drawLine(x*0.5, datum.pt.y()/2+padding, (x-1)*0.5, datum2.pt.y()/2+padding);
        }
            x = (eData->getLengthOfChannel(i)-1) - ((eData->getLengthOfChannel(i)-1)-this->width())+20;
        }
    }
}

void EEGDisplayDialog::updateDisplay(){
    repaint();
}

void EEGDisplayDialog::on_btnStart_clicked()
{
    this->collectionStarted = true;
    eMgr->startDataCollection();
    sleep(2);
    dTimer->start(0);
    resizeTimer->start(3000);
}

void EEGDisplayDialog::on_btnStop_clicked()
{
    eMgr->stopDataCollection();
     dTimer->stop();
}



void EEGDisplayDialog::on_cmbNotch_activated(const QString &notch)
{
    QByteArray ba = notch.toLatin1();
    char *notchOut = ba.data();
    emit notchChanged(notchOut);
}

void EEGDisplayDialog::on_cmbBandpass_activated(const QString &bp)
{
    QByteArray ba = bp.toLatin1();
    char *bpOut = ba.data();
    emit bandpassChanged(bpOut);
}

void EEGDisplayDialog::on_cmbChannels_activated(int displayNumIndex)
{
    displayNum = displayNumIndex+1;
}


void EEGDisplayDialog::on_cmbSpeed_activated(const QString &speedIn)
{
    dSpeed = speedIn.toDouble();
}
