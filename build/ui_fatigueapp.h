/********************************************************************************
** Form generated from reading UI file 'fatigueapp.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FATIGUEAPP_H
#define UI_FATIGUEAPP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FatigueApp
{
public:
    QLabel *label;
    QPlainTextEdit *txtData;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnTired;
    QProgressBar *pbTired;

    void setupUi(QWidget *FatigueApp)
    {
        if (FatigueApp->objectName().isEmpty())
            FatigueApp->setObjectName(QString::fromUtf8("FatigueApp"));
        FatigueApp->resize(255, 178);
        label = new QLabel(FatigueApp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 151, 17));
        txtData = new QPlainTextEdit(FatigueApp);
        txtData->setObjectName(QString::fromUtf8("txtData"));
        txtData->setGeometry(QRect(20, 30, 101, 51));
        layoutWidget = new QWidget(FatigueApp);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 130, 211, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnStart = new QPushButton(layoutWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        horizontalLayout->addWidget(btnStart);

        btnStop = new QPushButton(layoutWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        horizontalLayout->addWidget(btnStop);

        btnTired = new QPushButton(FatigueApp);
        btnTired->setObjectName(QString::fromUtf8("btnTired"));
        btnTired->setGeometry(QRect(130, 30, 101, 51));
        pbTired = new QProgressBar(FatigueApp);
        pbTired->setObjectName(QString::fromUtf8("pbTired"));
        pbTired->setGeometry(QRect(20, 90, 211, 31));
        pbTired->setValue(24);
        label->raise();
        txtData->raise();
        layoutWidget->raise();
        btnTired->raise();
        btnStop->raise();
        pbTired->raise();

        retranslateUi(FatigueApp);

        QMetaObject::connectSlotsByName(FatigueApp);
    } // setupUi

    void retranslateUi(QWidget *FatigueApp)
    {
        FatigueApp->setWindowTitle(QApplication::translate("FatigueApp", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FatigueApp", "Fatigue Detection", 0, QApplication::UnicodeUTF8));
        btnStart->setText(QApplication::translate("FatigueApp", "Start", 0, QApplication::UnicodeUTF8));
        btnStop->setText(QApplication::translate("FatigueApp", "Stop", 0, QApplication::UnicodeUTF8));
        btnTired->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FatigueApp: public Ui_FatigueApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FATIGUEAPP_H
