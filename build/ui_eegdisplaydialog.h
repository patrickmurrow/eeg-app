/********************************************************************************
** Form generated from reading UI file 'eegdisplaydialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EEGDISPLAYDIALOG_H
#define UI_EEGDISPLAYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_EEGDisplayDialog
{
public:
    QSlider *hs2_2;
    QLabel *label;
    QLabel *label_2;
    QComboBox *cmbNotch;
    QLabel *label_3;
    QComboBox *cmbBandpass;
    QComboBox *cmbChannels;
    QLabel *label_4;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QComboBox *cmbSpeed;
    QLabel *label_5;

    void setupUi(QDialog *EEGDisplayDialog)
    {
        if (EEGDisplayDialog->objectName().isEmpty())
            EEGDisplayDialog->setObjectName(QString::fromUtf8("EEGDisplayDialog"));
        EEGDisplayDialog->resize(1333, 604);
        hs2_2 = new QSlider(EEGDisplayDialog);
        hs2_2->setObjectName(QString::fromUtf8("hs2_2"));
        hs2_2->setGeometry(QRect(-160, 40, 1611, 29));
        hs2_2->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs2_2->setOrientation(Qt::Horizontal);
        label = new QLabel(EEGDisplayDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 171, 31));
        label_2 = new QLabel(EEGDisplayDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(890, 10, 51, 31));
        cmbNotch = new QComboBox(EEGDisplayDialog);
        cmbNotch->setObjectName(QString::fromUtf8("cmbNotch"));
        cmbNotch->setGeometry(QRect(940, 10, 125, 27));
        cmbNotch->setCursor(QCursor(Qt::PointingHandCursor));
        cmbNotch->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #2E2E2E;\n"
"    border-radius: 5px;\n"
"    padding: 0px 0px 0px 3px;\n"
"    min-width: 6em;\n"
"	selection-background-color: #CCCCCC;\n"
"	selection-color: #2E2E2E;\n"
"	color: white;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: black;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: #666666;\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"     background: #666666;\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"	background-color: yellow;\n"
"    padding-top: 10px;\n"
"    padding-left: 11px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	background-color: #404040;\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 2px;\n"
"    border-left-color: #2E2E2E;\n"
"    border-left-style: solid; /* just a single line */\n"
"    borde"
                        "r-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(assets/arrow.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #2E2E2E;\n"
"    background-color: #666666;\n"
"}"));
        label_3 = new QLabel(EEGDisplayDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(670, 10, 69, 31));
        cmbBandpass = new QComboBox(EEGDisplayDialog);
        cmbBandpass->setObjectName(QString::fromUtf8("cmbBandpass"));
        cmbBandpass->setGeometry(QRect(750, 10, 127, 27));
        cmbBandpass->setCursor(QCursor(Qt::PointingHandCursor));
        cmbBandpass->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #2E2E2E;\n"
"    border-radius: 5px;\n"
"    padding: 0px 0px 0px 3px;\n"
"    min-width: 6em;\n"
"	selection-background-color: #CCCCCC;\n"
"	selection-color: #2E2E2E;\n"
"	color: white;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: black;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: #666666;\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"     background: #666666;\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"	background-color: yellow;\n"
"    padding-top: 10px;\n"
"    padding-left: 11px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	background-color: #404040;\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 2px;\n"
"    border-left-color: #2E2E2E;\n"
"    border-left-style: solid; /* just a single line */\n"
"    borde"
                        "r-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(assets/arrow.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #2E2E2E;\n"
"    background-color: #666666;\n"
"}"));
        cmbChannels = new QComboBox(EEGDisplayDialog);
        cmbChannels->setObjectName(QString::fromUtf8("cmbChannels"));
        cmbChannels->setGeometry(QRect(592, 10, 61, 27));
        cmbChannels->setMinimumSize(QSize(0, 0));
        cmbChannels->setCursor(QCursor(Qt::PointingHandCursor));
        cmbChannels->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #2E2E2E;\n"
"    border-radius: 5px;\n"
"    padding: 0px 0px 0px 3px;\n"
"	selection-background-color: #CCCCCC;\n"
"	selection-color: #2E2E2E;\n"
"	color: white;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: black;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: #666666;\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"     background: #666666;\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"	background-color: yellow;\n"
"    padding-top: 10px;\n"
"    padding-left: 11px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	background-color: #404040;\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 2px;\n"
"    border-left-color: #2E2E2E;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px;"
                        " /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(assets/arrow.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #2E2E2E;\n"
"    background-color: #666666;\n"
"}"));
        label_4 = new QLabel(EEGDisplayDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(510, 10, 71, 31));
        btnStart = new QPushButton(EEGDisplayDialog);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(1102, 10, 91, 27));
        btnStart->setCursor(QCursor(Qt::PointingHandCursor));
        btnStart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 3px solid #2E2E2E;\n"
"    border-radius: 5px;\n"
"    padding: 0px 0px 0px 3px;\n"
"	color: white;\n"
"   background-color: #666666;\n"
"	border-style: outset;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"border-style:solid;\n"
"border-width:1px;\n"
"}\n"
""));
        btnStop = new QPushButton(EEGDisplayDialog);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setGeometry(QRect(1210, 10, 91, 27));
        btnStop->setCursor(QCursor(Qt::PointingHandCursor));
        btnStop->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 3px solid #2E2E2E;\n"
"    border-radius: 5px;\n"
"    padding: 0px 0px 0px 3px;\n"
"	color: white;\n"
"   background-color: #666666;\n"
"	border-style: outset;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"border-style:solid;\n"
"border-width:1px;\n"
"}\n"
"\n"
""));
        cmbSpeed = new QComboBox(EEGDisplayDialog);
        cmbSpeed->setObjectName(QString::fromUtf8("cmbSpeed"));
        cmbSpeed->setGeometry(QRect(422, 10, 61, 27));
        cmbSpeed->setMinimumSize(QSize(0, 0));
        cmbSpeed->setCursor(QCursor(Qt::PointingHandCursor));
        cmbSpeed->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #2E2E2E;\n"
"    border-radius: 5px;\n"
"    padding: 0px 0px 0px 3px;\n"
"	selection-background-color: #CCCCCC;\n"
"	selection-color: #2E2E2E;\n"
"	color: white;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: black;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: #666666;\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"     background: #666666;\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"	background-color: yellow;\n"
"    padding-top: 10px;\n"
"    padding-left: 11px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	background-color: #404040;\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 2px;\n"
"    border-left-color: #2E2E2E;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px;"
                        " /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(assets/arrow.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #2E2E2E;\n"
"    background-color: #666666;\n"
"}"));
        label_5 = new QLabel(EEGDisplayDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(360, 10, 51, 31));

        retranslateUi(EEGDisplayDialog);

        QMetaObject::connectSlotsByName(EEGDisplayDialog);
    } // setupUi

    void retranslateUi(QDialog *EEGDisplayDialog)
    {
        EEGDisplayDialog->setWindowTitle(QApplication::translate("EEGDisplayDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EEGDisplayDialog", "<html><head/><body><p><span style=\" font-size:20pt;\">Raw EEG</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EEGDisplayDialog", "Notch:", 0, QApplication::UnicodeUTF8));
        cmbNotch->clear();
        cmbNotch->insertItems(0, QStringList()
         << QApplication::translate("EEGDisplayDialog", "No Notch", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "60 Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "50 Hz", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("EEGDisplayDialog", "Bandpass:", 0, QApplication::UnicodeUTF8));
        cmbBandpass->clear();
        cmbBandpass->insertItems(0, QStringList()
         << QApplication::translate("EEGDisplayDialog", "No BP Filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "1-50 Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "7-13 Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "15-50 Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "5-50 Hz", 0, QApplication::UnicodeUTF8)
        );
        cmbChannels->clear();
        cmbChannels->insertItems(0, QStringList()
         << QApplication::translate("EEGDisplayDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "8", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("EEGDisplayDialog", "Channels:", 0, QApplication::UnicodeUTF8));
        btnStart->setText(QApplication::translate("EEGDisplayDialog", "Start", 0, QApplication::UnicodeUTF8));
        btnStop->setText(QApplication::translate("EEGDisplayDialog", "Stop", 0, QApplication::UnicodeUTF8));
        cmbSpeed->clear();
        cmbSpeed->insertItems(0, QStringList()
         << QApplication::translate("EEGDisplayDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "0.8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "1.2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EEGDisplayDialog", "1.5", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("EEGDisplayDialog", "Speed:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EEGDisplayDialog: public Ui_EEGDisplayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EEGDISPLAYDIALOG_H
