/********************************************************************************
** Form generated from reading UI file 'calibratewindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATEWINDOW_H
#define UI_CALIBRATEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibrateWindow
{
public:
    QLabel *label;
    QPushButton *btnBegin;
    QPushButton *btnCancel;
    QPushButton *btnBack;
    QLCDNumber *lcdCountdown;
    QTextEdit *txtDisplay;
    QSlider *hs1;
    QSlider *hs2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *cmbHeadset;

    void setupUi(QWidget *CalibrateWindow)
    {
        if (CalibrateWindow->objectName().isEmpty())
            CalibrateWindow->setObjectName(QString::fromUtf8("CalibrateWindow"));
        CalibrateWindow->resize(941, 580);
        label = new QLabel(CalibrateWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 181, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(26);
        label->setFont(font);
        btnBegin = new QPushButton(CalibrateWindow);
        btnBegin->setObjectName(QString::fromUtf8("btnBegin"));
        btnBegin->setGeometry(QRect(710, 510, 101, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ButtonIcons/btnBegin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBegin->setIcon(icon);
        btnBegin->setIconSize(QSize(85, 85));
        btnCancel = new QPushButton(CalibrateWindow);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(810, 510, 101, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ButtonIcons/btnCancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon1);
        btnCancel->setIconSize(QSize(95, 90));
        btnBack = new QPushButton(CalibrateWindow);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setGeometry(QRect(38, 506, 101, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ButtonIcons/btnBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon2);
        btnBack->setIconSize(QSize(80, 80));
        lcdCountdown = new QLCDNumber(CalibrateWindow);
        lcdCountdown->setObjectName(QString::fromUtf8("lcdCountdown"));
        lcdCountdown->setGeometry(QRect(620, 20, 281, 101));
        txtDisplay = new QTextEdit(CalibrateWindow);
        txtDisplay->setObjectName(QString::fromUtf8("txtDisplay"));
        txtDisplay->setGeometry(QRect(100, 250, 731, 201));
        txtDisplay->setReadOnly(true);
        hs1 = new QSlider(CalibrateWindow);
        hs1->setObjectName(QString::fromUtf8("hs1"));
        hs1->setGeometry(QRect(-30, 140, 1001, 29));
        hs1->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs1->setOrientation(Qt::Horizontal);
        hs2 = new QSlider(CalibrateWindow);
        hs2->setObjectName(QString::fromUtf8("hs2"));
        hs2->setGeometry(QRect(-50, 470, 1001, 29));
        hs2->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs2->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(CalibrateWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 80, 241, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        cmbHeadset = new QComboBox(layoutWidget);
        cmbHeadset->setObjectName(QString::fromUtf8("cmbHeadset"));
        cmbHeadset->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: white;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                                stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
""
                        "    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(/usr/share/icons/crystalsvg/16x16/actions/1downarrow.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        horizontalLayout->addWidget(cmbHeadset);


        retranslateUi(CalibrateWindow);

        QMetaObject::connectSlotsByName(CalibrateWindow);
    } // setupUi

    void retranslateUi(QWidget *CalibrateWindow)
    {
        CalibrateWindow->setWindowTitle(QApplication::translate("CalibrateWindow", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CalibrateWindow", "Calibration", 0, QApplication::UnicodeUTF8));
        btnBegin->setText(QString());
        btnCancel->setText(QString());
        btnBack->setText(QString());
        txtDisplay->setHtml(QApplication::translate("CalibrateWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt;\">Click Begin to Start Calibration</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CalibrateWindow", "Headset:", 0, QApplication::UnicodeUTF8));
        cmbHeadset->clear();
        cmbHeadset->insertItems(0, QStringList()
         << QApplication::translate("CalibrateWindow", "Dummy", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CalibrateWindow", "Muse", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CalibrateWindow", "Brainlink", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CalibrateWindow: public Ui_CalibrateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATEWINDOW_H
