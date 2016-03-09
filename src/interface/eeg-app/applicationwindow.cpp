#include "applicationwindow.h"
#include "../../build/ui_applicationwindow.h"
#include "eegappmenu.h"
#include "eegdisplaywindow.h"
#include "eegdisplaydialog.h"

ApplicationWindow::ApplicationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApplicationWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color:#B7B8B7;");
    ui->btnDepression->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnFatigue->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnDrone->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnBack->setStyleSheet("QPushButton{background: transparent;}");
    ui->btnDepression->setFocusPolicy(Qt::NoFocus);
    ui->btnFatigue->setFocusPolicy(Qt::NoFocus);
    ui->btnDrone->setFocusPolicy(Qt::NoFocus);
    ui->btnBack->setFocusPolicy(Qt::NoFocus);
    ui->hs1->setDisabled(true);
    ui->hs2->setDisabled(true);
}

ApplicationWindow::~ApplicationWindow()
{
    delete ui;
}

void ApplicationWindow::on_btnBack_clicked()
{
    EEGAppMenu *window = new EEGAppMenu(0);
    window->resize(245, 365);
    window->move(300, 300);
    window->setWindowTitle("");
    window->show();
    hide();
}

void ApplicationWindow::on_btnDepression_clicked()
{
    EEGDisplayWindow *window = new EEGDisplayWindow(0);
    window->resize(window->width(), window->height());
    window->move(300, 300);
    window->setWindowTitle("");
    window->show();
    hide();
}

void ApplicationWindow::on_btnDrone_clicked()
{
    EEGDisplayDialog *dialog = new EEGDisplayDialog(0);
    dialog->setWindowTitle("");
    dialog->show();
    hide();
}
