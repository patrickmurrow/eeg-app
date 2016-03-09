#ifndef EEGAPPMENU_H
#define EEGAPPMENU_H

#include <QMainWindow>

namespace Ui {
class EEGAppMenu;
}

class EEGAppMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit EEGAppMenu(QWidget *parent = 0);
    ~EEGAppMenu();

private slots:
    void on_btnApplications_clicked();

    void on_btnCalibration_clicked();

    void on_btnSettings_clicked();

private:
    Ui::EEGAppMenu *ui;
};

#endif // EEGAPPMENU_H
