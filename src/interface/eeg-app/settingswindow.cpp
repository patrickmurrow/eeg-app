#include "settingswindow.h"
#include "../../build/ui_settingswindow.h"
#include "eegappmenu.h"
#include <unistd.h>
#include "../bluetoothSearchThread.hpp"
#include "../bluetoothItem.hpp"
#include "device.h"
#include "../bluetoothConnectThread.hpp"


SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color:#B7B8B7;");
    ui->btnBack->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnSearch->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnConnect->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnSearch->setFocusPolicy(Qt::NoFocus);
    ui->btnConnect->setFocusPolicy(Qt::NoFocus);
    ui->btnBack->setFocusPolicy(Qt::NoFocus);
    ui->lstDevices->setFrameStyle(QFrame::NoFrame);
    ui->hs1->setDisabled(true);
    ui->hs2->setDisabled(true);
    ui->hs3->setDisabled(true);
    ui->lblTick->setVisible(false);
    ui->loading->setVisible(false);

}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_btnBack_clicked()
{
      EEGAppMenu *window = new EEGAppMenu(0);
      window->resize(245, 365);
      window->move(300, 300);
      window->setWindowTitle("");
      window->show();
      hide();
}

void SettingsWindow::on_btnSearch_clicked()
{
    QMovie *movie = new QMovie("assets/loading.gif");
    ui->loading->setMovie(movie);
    ui->loading->show();
    movie->start();
    this->searchMtx.lock();
    if (this->currentlySearching) {
      printf("Search already in progress.\n");
    } else {
      printf("Search beginning!\n");
      BluetoothSearchThread *sThread = new BluetoothSearchThread();
      connect(sThread, SIGNAL(deviceFound(QString, QString)),
          this, SLOT(deviceFound(QString, QString)));
      connect(sThread, SIGNAL(finished()),
          this, SLOT(searchFinished()));
      sThread->start();
      this->currentlySearching = true;
    }
    this->searchMtx.unlock();
}

void SettingsWindow::deviceFound(QString addr, QString name){
    if (ui->lstDevices->count() < 5 || name == "BrainLink" || name == "Muse"){
        Device *dev = new Device(addr, name);
        QVariant qv;
        qv.setValue(dev);
        QListWidgetItem *listItem = new QListWidgetItem();
        listItem->setText(name.append("\n\n").append(addr));
        listItem->setData(Qt::UserRole, qv);
        ui->lstDevices->addItem(listItem);
        ui->lstDevices->repaint();
    }
}

void SettingsWindow::searchFinished(){
    ui->loading->setVisible(false);
}


void SettingsWindow::on_btnConnect_clicked()
{
    QListWidgetItem *listItem = ui->lstDevices->currentItem();
    int row = ui->lstDevices->currentRow();
    QVariant qvPtr = listItem->data(Qt::UserRole);
    Device *dev = qvPtr.value<Device*>();
    BluetoothConnectThread *cThread = new BluetoothConnectThread("/dev/rfcomm0/", dev->getAddress(), 6);
    cThread->start();
    sleep(2);
    QListWidgetItem *topItem =ui->lstDevices->takeItem(row);
    ui->lstDevices->insertItem(0, topItem);
    ui->lstDevices->clearSelection();
    ui->lblTick->setVisible(true);

}
