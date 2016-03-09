/********************************************************************************
** Form generated from reading UI file 'eegappmenu.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EEGAPPMENU_H
#define UI_EEGAPPMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EEGAppMenu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *btnApplications;
    QPushButton *btnCalibration;
    QPushButton *btnSettings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EEGAppMenu)
    {
        if (EEGAppMenu->objectName().isEmpty())
            EEGAppMenu->setObjectName(QString::fromUtf8("EEGAppMenu"));
        EEGAppMenu->resize(251, 365);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        EEGAppMenu->setFont(font);
        EEGAppMenu->setCursor(QCursor(Qt::PointingHandCursor));
        EEGAppMenu->setFocusPolicy(Qt::ClickFocus);
        EEGAppMenu->setWindowOpacity(1);
        EEGAppMenu->setAutoFillBackground(false);
        centralwidget = new QWidget(EEGAppMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 211, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(24);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        btnApplications = new QPushButton(centralwidget);
        btnApplications->setObjectName(QString::fromUtf8("btnApplications"));
        btnApplications->setGeometry(QRect(20, 60, 210, 81));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ButtonIcons/btnApplications.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnApplications->setIcon(icon);
        btnApplications->setIconSize(QSize(210, 80));
        btnCalibration = new QPushButton(centralwidget);
        btnCalibration->setObjectName(QString::fromUtf8("btnCalibration"));
        btnCalibration->setGeometry(QRect(20, 140, 210, 81));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ButtonIcons/btnCalibration.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCalibration->setIcon(icon1);
        btnCalibration->setIconSize(QSize(210, 80));
        btnSettings = new QPushButton(centralwidget);
        btnSettings->setObjectName(QString::fromUtf8("btnSettings"));
        btnSettings->setGeometry(QRect(20, 220, 210, 81));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ButtonIcons/btnSettings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSettings->setIcon(icon2);
        btnSettings->setIconSize(QSize(210, 80));
        EEGAppMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EEGAppMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 251, 32));
        EEGAppMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(EEGAppMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EEGAppMenu->setStatusBar(statusbar);

        retranslateUi(EEGAppMenu);

        QMetaObject::connectSlotsByName(EEGAppMenu);
    } // setupUi

    void retranslateUi(QMainWindow *EEGAppMenu)
    {
        EEGAppMenu->setWindowTitle(QApplication::translate("EEGAppMenu", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EEGAppMenu", "EEG Applications", 0, QApplication::UnicodeUTF8));
        btnApplications->setText(QString());
        btnCalibration->setText(QString());
        btnSettings->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EEGAppMenu: public Ui_EEGAppMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EEGAPPMENU_H
