/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QPushButton *btnSearch;
    QLabel *label;
    QPushButton *btnConnect;
    QSlider *hs2;
    QSlider *hs1;
    QSlider *hs3;
    QPushButton *btnBack;
    QLabel *loading;
    QListWidget *lstDevices;
    QLabel *lblTick;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(952, 584);
        btnSearch = new QPushButton(SettingsWindow);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setGeometry(QRect(20, 80, 99, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ButtonIcons/btnSearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearch->setIcon(icon);
        btnSearch->setIconSize(QSize(90, 90));
        label = new QLabel(SettingsWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 0, 151, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(24);
        label->setFont(font);
        btnConnect = new QPushButton(SettingsWindow);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(120, 80, 111, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ButtonIcons/btnConnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConnect->setIcon(icon1);
        btnConnect->setIconSize(QSize(102, 80));
        hs2 = new QSlider(SettingsWindow);
        hs2->setObjectName(QString::fromUtf8("hs2"));
        hs2->setGeometry(QRect(-160, 120, 1251, 31));
        hs2->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs2->setOrientation(Qt::Horizontal);
        hs1 = new QSlider(SettingsWindow);
        hs1->setObjectName(QString::fromUtf8("hs1"));
        hs1->setGeometry(QRect(-110, 50, 1251, 29));
        hs1->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs1->setOrientation(Qt::Horizontal);
        hs3 = new QSlider(SettingsWindow);
        hs3->setObjectName(QString::fromUtf8("hs3"));
        hs3->setGeometry(QRect(-50, 490, 1251, 29));
        hs3->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0.5px solid #B2B2B2;\n"
"    height: 5px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #636465, stop:1 #D5D6D5);\n"
"    margin: 2px 0;\n"
"}\n"
""));
        hs3->setOrientation(Qt::Horizontal);
        btnBack = new QPushButton(SettingsWindow);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setGeometry(QRect(830, 520, 91, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ButtonIcons/btnBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon2);
        btnBack->setIconSize(QSize(80, 80));
        loading = new QLabel(SettingsWindow);
        loading->setObjectName(QString::fromUtf8("loading"));
        loading->setGeometry(QRect(870, 80, 41, 41));
        loading->setPixmap(QPixmap(QString::fromUtf8(":/ButtonIcons/loading.gif")));
        loading->setScaledContents(true);
        lstDevices = new QListWidget(SettingsWindow);
        lstDevices->setObjectName(QString::fromUtf8("lstDevices"));
        lstDevices->setGeometry(QRect(20, 160, 901, 321));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lstDevices->setFont(font1);
        lstDevices->setStyleSheet(QString::fromUtf8("QListView {\n"
"    show-decoration-selected: 1;\n"
"	font: 14pt \"Ubuntu\";\n"
"}\n"
"\n"
"QListWidget::item { \n"
"	border: 1px solid gray;\n"
"	margin: 0 0 6px 0;s\n"
"\n"
" }\n"
"\n"
"QListView::item:alternate {\n"
"    background: #EEEEEE;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    border: 1px solid #2e2e2e;\n"
"}\n"
"\n"
"QListView::item:selected:!active {\n"
"    background: #636465;\n"
"}\n"
"\n"
"QListView::item:selected:active {\n"
"    background: #636465;\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"    background:  #CBCCCB;\n"
"}\n"
" \n"
" QListView::item:hover {\n"
"     backgrouQSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 4px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #"
                        "b4b4b4, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}nd:  #CBCCCB;\n"
"     border: 1px solid #9B9C9B;\n"
"}"));
        lblTick = new QLabel(SettingsWindow);
        lblTick->setObjectName(QString::fromUtf8("lblTick"));
        lblTick->setGeometry(QRect(870, 170, 41, 41));
        lblTick->setAutoFillBackground(false);
        lblTick->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        lblTick->setPixmap(QPixmap(QString::fromUtf8(":/ButtonIcons/tick.png")));
        lblTick->setScaledContents(true);
        btnConnect->raise();
        btnSearch->raise();
        label->raise();
        hs2->raise();
        hs1->raise();
        hs3->raise();
        btnBack->raise();
        loading->raise();
        lstDevices->raise();
        lblTick->raise();

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Form", 0, QApplication::UnicodeUTF8));
        btnSearch->setText(QString());
        label->setText(QApplication::translate("SettingsWindow", "Settings", 0, QApplication::UnicodeUTF8));
        btnConnect->setText(QString());
        btnBack->setText(QString());
        loading->setText(QString());
        lblTick->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
