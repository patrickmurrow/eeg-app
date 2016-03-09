#include "eegappmenu.h"
#include "../../build/ui_eegappmenu.h"
#include "../../util/eeg/eegManager.hpp"
#include "../../eeg/dummy/dummyHS.hpp"
#include "calibratewindow.h"
#include "applicationwindow.h"
#include "settingswindow.h"

EEGAppMenu::EEGAppMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EEGAppMenu)
{
    ui->setupUi(this);
    setStyleSheet("background-color:#B7B8B7;");
    ui->btnApplications->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnCalibration->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnSettings->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnApplications->setFocusPolicy(Qt::NoFocus);
    ui->btnCalibration->setFocusPolicy(Qt::NoFocus);
    ui->btnSettings->setFocusPolicy(Qt::NoFocus);
}

EEGAppMenu::~EEGAppMenu()
{
    delete ui;
}

void EEGAppMenu::on_btnApplications_clicked()
{
    ApplicationWindow *aWin = new ApplicationWindow();
    aWin->show();
    aWin->resize(794, 440);
    aWin->move(300, 300);
    hide();

}

void EEGAppMenu::on_btnCalibration_clicked()
{
    CalibrateWindow *cWin = new CalibrateWindow(0);
    cWin->show();
    cWin->resize(940, 580);
    cWin->move(300, 300);
    hide();

}

void EEGAppMenu::on_btnSettings_clicked()
{
    SettingsWindow *sWin = new SettingsWindow(0);
    sWin->show();
    sWin->resize(940, 580);
    sWin->move(300, 300);
    hide();
}
