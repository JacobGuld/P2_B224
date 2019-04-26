/********************************************************************************
** Form generated from reading UI file 'vejrmaster1000.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEJRMASTER1000_H
#define UI_VEJRMASTER1000_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VejrMaster1000
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdTemp;
    QLCDNumber *lcdHumidity;
    QLabel *labelTemp;
    QLabel *labelHumidity;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VejrMaster1000)
    {
        if (VejrMaster1000->objectName().isEmpty())
            VejrMaster1000->setObjectName(QString::fromUtf8("VejrMaster1000"));
        VejrMaster1000->resize(400, 300);
        centralWidget = new QWidget(VejrMaster1000);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lcdTemp = new QLCDNumber(centralWidget);
        lcdTemp->setObjectName(QString::fromUtf8("lcdTemp"));
        lcdTemp->setGeometry(QRect(190, 10, 201, 91));
        lcdHumidity = new QLCDNumber(centralWidget);
        lcdHumidity->setObjectName(QString::fromUtf8("lcdHumidity"));
        lcdHumidity->setGeometry(QRect(190, 120, 201, 91));
        labelTemp = new QLabel(centralWidget);
        labelTemp->setObjectName(QString::fromUtf8("labelTemp"));
        labelTemp->setGeometry(QRect(20, 30, 151, 51));
        QFont font;
        font.setPointSize(15);
        labelTemp->setFont(font);
        labelHumidity = new QLabel(centralWidget);
        labelHumidity->setObjectName(QString::fromUtf8("labelHumidity"));
        labelHumidity->setGeometry(QRect(20, 140, 151, 51));
        labelHumidity->setFont(font);
        VejrMaster1000->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VejrMaster1000);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        VejrMaster1000->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VejrMaster1000);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VejrMaster1000->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VejrMaster1000);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VejrMaster1000->setStatusBar(statusBar);

        retranslateUi(VejrMaster1000);

        QMetaObject::connectSlotsByName(VejrMaster1000);
    } // setupUi

    void retranslateUi(QMainWindow *VejrMaster1000)
    {
        VejrMaster1000->setWindowTitle(QApplication::translate("VejrMaster1000", "VejrMaster1000", nullptr));
        labelTemp->setText(QApplication::translate("VejrMaster1000", "Temperature C", nullptr));
        labelHumidity->setText(QApplication::translate("VejrMaster1000", "Humidity %", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VejrMaster1000: public Ui_VejrMaster1000 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEJRMASTER1000_H
