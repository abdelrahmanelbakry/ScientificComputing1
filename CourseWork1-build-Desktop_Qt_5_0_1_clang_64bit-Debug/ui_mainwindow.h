/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Load_Input;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionLinear_Regression;
    QAction *actionPolynominal_Regression;
    QWidget *CentralWidget;
    QCustomPlot *customPlot;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRun_Technique;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(667, 400);
        action_Load_Input = new QAction(MainWindow);
        action_Load_Input->setObjectName(QStringLiteral("action_Load_Input"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLinear_Regression = new QAction(MainWindow);
        actionLinear_Regression->setObjectName(QStringLiteral("actionLinear_Regression"));
        actionPolynominal_Regression = new QAction(MainWindow);
        actionPolynominal_Regression->setObjectName(QStringLiteral("actionPolynominal_Regression"));
        CentralWidget = new QWidget(MainWindow);
        CentralWidget->setObjectName(QStringLiteral("CentralWidget"));
        customPlot = new QCustomPlot(CentralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(0, 0, 661, 351));
        customPlot->setAutoFillBackground(true);
        MainWindow->setCentralWidget(CentralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 667, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRun_Technique = new QMenu(menuFile);
        menuRun_Technique->setObjectName(QStringLiteral("menuRun_Technique"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_Load_Input);
        menuFile->addAction(menuRun_Technique->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuRun_Technique->addAction(actionLinear_Regression);
        menuRun_Technique->addAction(actionPolynominal_Regression);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Load_Input->setText(QApplication::translate("MainWindow", "Load Input", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionLinear_Regression->setText(QApplication::translate("MainWindow", "Linear Regression", 0));
        actionPolynominal_Regression->setText(QApplication::translate("MainWindow", "Polynominal Regression", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuRun_Technique->setTitle(QApplication::translate("MainWindow", "Run Technique", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
