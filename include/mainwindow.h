#pragma once

#include <qextserialenumerator.h>
#include <QMainWindow>
#include <QActionGroup>

#include "ui_dashboard.h"

class MainWindow : public QMainWindow, private Ui::Dashboard {
    Q_OBJECT

public:
    MainWindow();

public slots:
    void about();
    void serialMonitor();
    void pressureDepthCalc();
    void voltageDropCalc();

private:
    void createActions();
    void createMenus();
    void createSerialPortMenu(QMenu* menu);
    void setupCompass();

    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *toolMenu;
    QMenu *serialMenu;
    QMenu *calcMenu;

    QAction *exitAct;
    QAction *aboutAct;
    QAction *serialMonitorAct;
    QAction *calcVoltageDropAct;
    QAction *calcPresureDepthAct;

    QActionGroup *serialActGroup;
};
