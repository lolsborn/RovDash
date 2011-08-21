#include <QtTest/QtTest>
#include <QObject>
#include <QtGlobal>
#include <qextserialenumerator.h>
#include <QList>
#include <QtDebug>


class SerialTest: public QObject {
    Q_OBJECT
    private slots:
    
    void init() {
    }

    void testSerialList() {
        QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
        qDebug() << "List of ports:";
        for (int i = 0; i < ports.size(); i++) {
            qDebug() << "port name:" << ports.at(i).portName;
            qDebug() << "friendly name:" << ports.at(i).friendName;
            qDebug() << "physical name:" << ports.at(i).physName;
            qDebug() << "enumerator name:" << ports.at(i).enumName;
            qDebug() << "vendor ID:" << QString::number(ports.at(i).vendorID, 16);
            qDebug() << "product ID:" << QString::number(ports.at(i).productID, 16);
            qDebug() << "===================================";
        }
    }

};