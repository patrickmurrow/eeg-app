/********************************************************************************
** Form generated from reading UI file 'eegdisplaywindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EEGDISPLAYWINDOW_H
#define UI_EEGDISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_EEGDisplayWindow
{
public:
    QCustomPlot *eegDisplayer;
    QSlider *hs2;
    QSlider *hs2_2;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QLabel *label;

    void setupUi(QWidget *EEGDisplayWindow)
    {
        if (EEGDisplayWindow->objectName().isEmpty())
            EEGDisplayWindow->setObjectName(QString::fromUtf8("EEGDisplayWindow"));
        EEGDisplayWindow->resize(1199, 786);
        eegDisplayer = new QCustomPlot(EEGDisplayWindow);
        eegDisplayer->setObjectName(QString::fromUtf8("eegDisplayer"));
        eegDisplayer->setGeometry(QRect(-10, 240, 1221, 501));
        eegDisplayer->setStyleSheet(QString::fromUtf8(""));
        hs2 = new QSlider(EEGDisplayWindow);
        hs2->setObjectName(QString::fromUtf8("hs2"));
        hs2->setGeometry(QRect(-110, 200, 1611, 29));
        hs2->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs2->setOrientation(Qt::Horizontal);
        hs2_2 = new QSlider(EEGDisplayWindow);
        hs2_2->setObjectName(QString::fromUtf8("hs2_2"));
        hs2_2->setGeometry(QRect(-110, 740, 1611, 29));
        hs2_2->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs2_2->setOrientation(Qt::Horizontal);
        btnStart = new QPushButton(EEGDisplayWindow);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(950, 160, 111, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ButtonIcons/btnBegin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStart->setIcon(icon);
        btnStart->setIconSize(QSize(100, 100));
        btnStop = new QPushButton(EEGDisplayWindow);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setGeometry(QRect(1060, 160, 121, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ButtonIcons/btnCancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon1);
        btnStop->setIconSize(QSize(107, 100));
        label = new QLabel(EEGDisplayWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 271, 81));

        retranslateUi(EEGDisplayWindow);

        QMetaObject::connectSlotsByName(EEGDisplayWindow);
    } // setupUi

    void retranslateUi(QWidget *EEGDisplayWindow)
    {
        EEGDisplayWindow->setWindowTitle(QApplication::translate("EEGDisplayWindow", "Form", 0, QApplication::UnicodeUTF8));
        btnStart->setText(QString());
        btnStop->setText(QString());
        label->setText(QApplication::translate("EEGDisplayWindow", "<html><head/><body><p><span style=\" font-size:26pt;\">Raw EEG Data</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EEGDisplayWindow: public Ui_EEGDisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EEGDISPLAYWINDOW_H
