/********************************************************************************
** Form generated from reading UI file 'applicationwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONWINDOW_H
#define UI_APPLICATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicationWindow
{
public:
    QPushButton *btnDepression;
    QPushButton *btnDrone;
    QPushButton *btnFatigue;
    QLabel *label;
    QPushButton *btnBack;
    QSlider *hs1;
    QSlider *hs2;

    void setupUi(QWidget *ApplicationWindow)
    {
        if (ApplicationWindow->objectName().isEmpty())
            ApplicationWindow->setObjectName(QString::fromUtf8("ApplicationWindow"));
        ApplicationWindow->resize(794, 440);
        btnDepression = new QPushButton(ApplicationWindow);
        btnDepression->setObjectName(QString::fromUtf8("btnDepression"));
        btnDepression->setGeometry(QRect(30, 100, 231, 231));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ButtonIcons/btnDepression.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDepression->setIcon(icon);
        btnDepression->setIconSize(QSize(220, 220));
        btnDrone = new QPushButton(ApplicationWindow);
        btnDrone->setObjectName(QString::fromUtf8("btnDrone"));
        btnDrone->setGeometry(QRect(280, 100, 231, 231));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ButtonIcons/btnDrone.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDrone->setIcon(icon1);
        btnDrone->setIconSize(QSize(220, 220));
        btnFatigue = new QPushButton(ApplicationWindow);
        btnFatigue->setObjectName(QString::fromUtf8("btnFatigue"));
        btnFatigue->setGeometry(QRect(530, 100, 231, 231));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ButtonIcons/btnFatigue.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFatigue->setIcon(icon2);
        btnFatigue->setIconSize(QSize(220, 220));
        label = new QLabel(ApplicationWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(26);
        label->setFont(font);
        btnBack = new QPushButton(ApplicationWindow);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setGeometry(QRect(660, 380, 99, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ButtonIcons/btnBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon3);
        btnBack->setIconSize(QSize(80, 80));
        hs1 = new QSlider(ApplicationWindow);
        hs1->setObjectName(QString::fromUtf8("hs1"));
        hs1->setGeometry(QRect(-71, 60, 971, 29));
        hs1->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs1->setOrientation(Qt::Horizontal);
        hs2 = new QSlider(ApplicationWindow);
        hs2->setObjectName(QString::fromUtf8("hs2"));
        hs2->setGeometry(QRect(-130, 350, 971, 29));
        hs2->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs2->setOrientation(Qt::Horizontal);

        retranslateUi(ApplicationWindow);

        QMetaObject::connectSlotsByName(ApplicationWindow);
    } // setupUi

    void retranslateUi(QWidget *ApplicationWindow)
    {
        ApplicationWindow->setWindowTitle(QApplication::translate("ApplicationWindow", "Form", 0, QApplication::UnicodeUTF8));
        btnDepression->setText(QString());
        btnDrone->setText(QString());
        btnFatigue->setText(QString());
        label->setText(QApplication::translate("ApplicationWindow", "Applications", 0, QApplication::UnicodeUTF8));
        btnBack->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ApplicationWindow: public Ui_ApplicationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONWINDOW_H
