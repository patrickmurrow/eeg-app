#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QtGui>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

private slots:
    void on_btnBack_clicked();
    void on_btnSearch_clicked();
    void deviceFound(QString addr, QString name);
    void searchFinished();

    void on_btnConnect_clicked();

private:
    Ui::SettingsWindow *ui;
    QMutex searchMtx;
    bool currentlySearching;
    bool currentlyConnecting;
    int xPos = 0;
};

#endif // SETTINGSWINDOW_H
