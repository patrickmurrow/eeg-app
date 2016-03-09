#include "eegdisplaywindow.h"
#include "../../build/ui_eegdisplaywindow.h"
#include "qcustomplot.h"
#include <QTimer>
#include <unistd.h>
#include "../../util/eeg/eegManager.hpp"
#include "../../eeg/dummy/dummyHS.hpp"
#include "../../eeg/brainlink/brainlinkHS.hpp"
#include "../../eeg/muse/museHS.hpp"
#include "../../eeg/openBCI/openBCIHS.hpp"
#include "../../util/eeg/eegData.hpp"
#include <stdlib.h>

QTimer *dataTimer;
int noChannels = 4;
EEGHeadset *openhs = new MuseHS();
EEGManager *dMan = new EEGManager(noChannels, openhs);
int count = 2000;


EEGDisplayWindow::EEGDisplayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EEGDisplayWindow)
{
    ui->setupUi(this);

    setStyleSheet("background-color:#B7B8B7;");
    ui->btnStart->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnStop->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnStart->setFocusPolicy(Qt::NoFocus);
    ui->btnStop->setFocusPolicy(Qt::NoFocus);

    dataTimer = new QTimer();
    this->plotGraph();
}

EEGDisplayWindow::~EEGDisplayWindow()
{
    delete ui;
}

void EEGDisplayWindow::plotGraph()
{ 
    int colourR = 0;
    int colourG = 0;
    int colourB = 0;
    for(int i = 0; i<(noChannels*2); i = i+2){
      colourR = rand() % 255;
      colourG = rand() % 255;
      colourB = rand() % 255;
      ui->eegDisplayer->addGraph(); // blue line
      ui->eegDisplayer->graph(i)->setPen(QPen(QColor(colourR, colourG, colourB), 2));

      ui->eegDisplayer->addGraph();
      ui->eegDisplayer->graph(i+1)->setPen(QPen(QColor(colourR, colourG, colourB)));
      ui->eegDisplayer->graph(i+1)->setLineStyle(QCPGraph::lsNone);
      ui->eegDisplayer->graph(i+1)->setScatterStyle(QCPScatterStyle::ssDisc);
    }
    
    ui->eegDisplayer->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->eegDisplayer->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->eegDisplayer->xAxis->setAutoTickStep(false);
    ui->eegDisplayer->xAxis->setTickStep(2);
    ui->eegDisplayer->axisRect()->setupFullAxesBox();

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->eegDisplayer->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->eegDisplayer->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->eegDisplayer->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->eegDisplayer->yAxis2, SLOT(setRange(QCPRange)));


    ui->eegDisplayer->rescaleAxes();
    ui->eegDisplayer->xAxis->setTicks(false);
    ui->eegDisplayer->yAxis->setTicks(false);
    ui->eegDisplayer->xAxis->setTickLabels(false);
    ui->eegDisplayer->yAxis->setTickLabels(false);
    ui->eegDisplayer->xAxis->setBasePen(QColor(183, 184, 183));
    ui->eegDisplayer->yAxis->setBasePen(QColor(183, 184, 183));
    ui->eegDisplayer->xAxis->setTickPen(QColor(183, 184, 183));
    ui->eegDisplayer->yAxis-> setTickPen(QColor(183, 184, 183));
    ui->eegDisplayer->xAxis->setSubTickPen(QColor(183, 184, 183));
    ui->eegDisplayer->yAxis->setSubTickPen(QColor(183, 184, 183));
    ui->eegDisplayer->xAxis->setTickLabelColor(Qt::white);
    ui->eegDisplayer->yAxis->setTickLabelColor(Qt::white);
    ui->eegDisplayer->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->eegDisplayer->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->eegDisplayer->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->eegDisplayer->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->eegDisplayer->xAxis->grid()->setSubGridVisible(false);
    ui->eegDisplayer->yAxis->grid()->setSubGridVisible(false);
    ui->eegDisplayer->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->eegDisplayer->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->eegDisplayer->xAxis2->setTicks(false);
    ui->eegDisplayer->yAxis2->setTicks(false);
    ui->eegDisplayer->xAxis2->setBasePen(QColor(183, 184, 183));
    ui->eegDisplayer->yAxis2->setBasePen(QColor(183, 184, 183));

    //ui->eegDisplayer->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    //ui->eegDisplayer->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 200);
    //plotGradient.setColorAt(0, QColor(183, 184, 183));
    plotGradient.setColorAt(1 , QColor(183, 184, 183));
    ui->eegDisplayer->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 200);
    //axisRectGradient.setColorAt(0, QColor(183, 184, 183));
    axisRectGradient.setColorAt(1, QColor(183, 184, 183));
    ui->eegDisplayer->axisRect()->setBackground(axisRectGradient);

    ui->eegDisplayer->rescaleAxes();
    ui->eegDisplayer->yAxis->setRange(0, 150);









    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(realTimeDataSlot()));
}

void EEGDisplayWindow::realTimeDataSlot()
{
    // calculate two new data points:
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.001) // at most add point every 1 ms
    {
      count++;
      EEGData *data = dMan->getEEGData();
      for (int i = 0; i<(noChannels*2); i = i+2){
        eegDatum datum = data->getDataInChannel(i/2, data->getLengthOfChannel(i/2)-1);
        ui->eegDisplayer->graph(i)->addData(key, datum.pt.y());
        //printf("Displayed X: %d\t Displayed Y: %d\n", datum.pt.x(), datum.pt.y());
        ui->eegDisplayer->graph(i+1)->clearData();
        ui->eegDisplayer->graph(i+1)->addData(key, datum.pt.y());
        ui->eegDisplayer->graph(i)->removeDataBefore(key-8);
      }

/*      eegDatum datum0 = data->getDataInChannel(0, data->getLengthOfChannel(0)-1);
      eegDatum datum1 = data->getDataInChannel(1, data->getLengthOfChannel(1)-1);
      eegDatum datum2 = data->getDataInChannel(2, data->getLengthOfChannel(2)-1);
      eegDatum datum3 = data->getDataInChannel(3, data->getLengthOfChannel(3)-1);


      //Calls bash script which invokes a "space bar press" - used with the Brainlink HS and Google Chrome
      // offline game mode (pressing space to make the dinosaur jump
      //if (datum.pt.y() > 260){
      //    system("bash /home/patrick/Documents/eeg-gui/src/interface/eeg-app/temp.sh");
      //}

      // add data to lines:
      ui->eegDisplayer->graph(0)->addData(key, datum0.pt.y());
      ui->eegDisplayer->graph(1)->addData(key, datum1.pt.y());
      ui->eegDisplayer->graph(2)->addData(key, datum2.pt.y());
      ui->eegDisplayer->graph(3)->addData(key, datum3.pt.y());
      // set data of dots:
      ui->eegDisplayer->graph(4)->clearData();
      ui->eegDisplayer->graph(4)->addData(key, datum0.pt.y());
      ui->eegDisplayer->graph(5)->clearData();
      ui->eegDisplayer->graph(5)->addData(key, datum1.pt.y());
      ui->eegDisplayer->graph(6)->clearData();
      ui->eegDisplayer->graph(6)->addData(key, datum2.pt.y());
      ui->eegDisplayer->graph(7)->clearData();
      ui->eegDisplayer->graph(7)->addData(key, datum3.pt.y());
      // remove data of lines that's outside visible range:
      ui->eegDisplayer->graph(0)->removeDataBefore(key-8);
      ui->eegDisplayer->graph(1)->removeDataBefore(key-8);
      ui->eegDisplayer->graph(2)->removeDataBefore(key-8);
      ui->eegDisplayer->graph(3)->removeDataBefore(key-8);
      */


      lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->eegDisplayer->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
    ui->eegDisplayer->replot();
    ui->eegDisplayer->rescaleAxes();
    QCPRange range = ui->eegDisplayer->yAxis->range();
    ui->eegDisplayer->yAxis->setRange(range.lower-10, range.upper+10);

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
      lastFpsKey = key;
      frameCount = 0;
    }
}


void EEGDisplayWindow::on_btnStart_clicked()
{
    dMan->startDataCollection();
    sleep(2);
    dataTimer->start(0); // Interval 0 means to refresh as fast as possible
}

void EEGDisplayWindow::on_btnStop_clicked()
{
    dMan->stopDataCollection();
    dataTimer->stop();
}
