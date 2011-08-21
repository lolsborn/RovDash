#include <QtGui>

#include "mainwindow.h"
#include "depthpressure.h"

#include <qwt_compass.h>
#include <qwt_dial_needle.h>
#include <qwt_compass_rose.h>


MainWindow::MainWindow() {
    setupUi(this);
    setupCompass();
    createActions();
    createMenus();
}

void MainWindow::setupCompass() {
    QwtCompassMagnetNeedle *needle = new QwtCompassMagnetNeedle(QwtCompassMagnetNeedle::ThinStyle);
    compass->setNeedle(needle);
    compass->setValue(135);
    compass->setFrameShadow(QwtDial::Sunken);
    compass->setLineWidth(5);
    QwtSimpleCompassRose* rose = new QwtSimpleCompassRose(16, 2);
    compass->setRose(rose);
    
}

void MainWindow::about() {
   QMessageBox::about(this, "About Rov Dashboard", 
        "The <b>QXmlStream Bookmarks</b> example demonstrates how to use Qt's "
               "QXmlStream classes to read and write XML documents.");
}

void MainWindow::serialMonitor() {
    QMessageBox::about(this, "TEST", "adf");
}

void MainWindow::createActions() {
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    serialMonitorAct = new QAction(tr("Serial Monitor"), this);
    serialMonitorAct->setShortcut(QKeySequence(Qt::SHIFT + Qt::CTRL + Qt::Key_M));
    connect(serialMonitorAct, SIGNAL(triggered()), this, SLOT(serialMonitor()));

    calcVoltageDropAct = new QAction(tr("Voltage Drop"), this);
    connect(calcVoltageDropAct, SIGNAL(triggered()), this, SLOT(voltageDropCalc()));

    calcPresureDepthAct = new QAction(tr("Pressure && Depth"), this);
    connect(calcPresureDepthAct, SIGNAL(triggered()), this, SLOT(pressureDepthCalc()));
}

void MainWindow::voltageDropCalc() {
    qDebug() << "voltage drop calculator";
}

void MainWindow::pressureDepthCalc() {
    DepthPressure* pressureCalc = new DepthPressure;
    pressureCalc->show();
    pressureCalc->raise();
    pressureCalc->activateWindow();
    qDebug() << "Calculate Pressure and Depth";
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);

    toolMenu = menuBar()->addMenu(tr("&Tools"));
    serialMenu = toolMenu->addMenu("Serial Port");
    createSerialPortMenu(serialMenu);
    
    toolMenu->addAction(serialMonitorAct);
    
    toolMenu->addSeparator();
    calcMenu = toolMenu->addMenu("Calculate");
    calcMenu->addAction(calcVoltageDropAct);
    calcMenu->addAction(calcPresureDepthAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

void MainWindow::createSerialPortMenu(QMenu* menu) {
    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    serialActGroup = new QActionGroup(this);
    for (int i = 0; i < ports.size(); i++) {
        //TODO: Need to keep these in a list so we can delete on refresh
        QAction* action = new QAction(ports.at(i).portName, this);
        action->setCheckable(true);
        menu->addAction(action);
        serialActGroup->addAction(action);

        qDebug() << "port name:" << ports.at(i).portName;
        qDebug() << "friendly name:" << ports.at(i).friendName;
        qDebug() << "physical name:" << ports.at(i).physName;
        qDebug() << "enumerator name:" << ports.at(i).enumName;
        qDebug() << "vendor ID:" << QString::number(ports.at(i).vendorID, 16);
        qDebug() << "product ID:" << QString::number(ports.at(i).productID, 16);
        qDebug() << "===================================";
    }
 }