#include "calibratewindow.h"
#include "../../build/ui_calibratewindow.h"
#include "calibrationthread.hpp"
#include "eegappmenu.h"
#include <unistd.h>
#include "../../util/eeg/eegManager.hpp"
#include "../../eeg/dummy/dummyHS.hpp"
#include "../../eeg/brainlink/brainlinkHS.hpp"

EEGHeadset *hs1 = new DummyHS();
EEGManager *manager = new EEGManager(1, hs1);

CalibrationThread *cThread = new CalibrationThread(0);

CalibrateWindow::CalibrateWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalibrateWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color:#B7B8B7;");
    ui->txtDisplay->viewport()->setAutoFillBackground(false);
    ui->txtDisplay->setFrameStyle(QFrame::NoFrame);
    ui->lcdCountdown->setFrameStyle(QFrame::NoFrame);
    ui->btnBack->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnBegin->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnCancel->setStyleSheet("QPushButton{background: transparent;}");
    ui->txtDisplay->setFont(QFont ("Ubuntu", 48));
    ui->btnBegin->setFocusPolicy(Qt::NoFocus);
    ui->btnCancel->setFocusPolicy(Qt::NoFocus);
    ui->btnBack->setFocusPolicy(Qt::NoFocus);
    ui->hs1->setDisabled(true);
    ui->hs2->setDisabled(true);

    connect(cThread, SIGNAL(txtChanged(QString, int)), this, SLOT(txtChanged(QString, int)));
    connect(cThread, SIGNAL(startCollect()), this, SLOT(startDataCollect()));
    connect(cThread, SIGNAL(stopCollect(bool)), this, SLOT(stopDataCollect(bool)));
}

CalibrateWindow::~CalibrateWindow()
{
    delete ui;
}

void CalibrateWindow::on_btnBack_clicked()
{
    cThread->stop();
    manager->stopDataCollection();
    manager->resetData();
    EEGAppMenu *window = new EEGAppMenu(0);
    window->resize(245, 365);
    window->move(300, 300);
    window->setWindowTitle("");
    window->show();
    hide();
}

void CalibrateWindow::on_btnBegin_clicked()
{
    cThread->start();
}

void CalibrateWindow::txtChanged(QString msg, int time){
    ui->txtDisplay->setText(msg);
    ui->txtDisplay->setAlignment(Qt::AlignCenter);
    ui->lcdCountdown->display(time);
}

void CalibrateWindow::startDataCollect(){
    manager->startDataCollection();
}

void CalibrateWindow::stopDataCollect(bool open){
    manager->stopDataCollection();
    if (open){
        this->eegEyesOpen = manager->getEEGData();
    }else{
        this->eegEyesClosed = manager->getEEGData();
    }
    manager->resetData();
}


void CalibrateWindow::on_btnCancel_clicked()
{
    cThread->stop();
    manager->stopDataCollection();
    manager->resetData();
}

void CalibrateWindow::on_cmbHeadset_activated(const QString &arg1)
{
    if(arg1 == "Brainlink"){
        hs1 = new BrainlinkHS();
        manager = new EEGManager(1, hs1);
    }else if (arg1 == "Dummy"){
        hs1 = new DummyHS();
        manager = new EEGManager(1, hs1);
    }
}
