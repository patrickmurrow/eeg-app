#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QWidget>

namespace Ui {
class ApplicationWindow;
}

class ApplicationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ApplicationWindow(QWidget *parent = 0);
    ~ApplicationWindow();

private slots:
    void on_btnBack_clicked();
    void on_btnDepression_clicked();

    void on_btnDrone_clicked();

private:
    Ui::ApplicationWindow *ui;
};

#endif // APPLICATIONWINDOW_H
