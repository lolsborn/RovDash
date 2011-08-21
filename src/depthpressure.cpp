#include <QtGui>

#include "depthpressure.h"

DepthPressure::DepthPressure() {
    setupUi(this);

    waterType->addItem("Fresh Water", QVariant(0.43));
    waterType->addItem("Salt Water", QVariant(0.44));

    depthUnits->addItem("ft", QVariant(1.0));
    depthUnits->addItem("meters", QVariant(3.2808399));
    depthUnits->addItem("yards", QVariant(3.0));

    pressureUnits->addItem("psi", QVariant(1.0));
    pressureUnits->addItem("kPa", QVariant(6.89475729));
    pressureUnits->addItem("atm", QVariant(0.0680459639));
    pressureUnits->addItem("bar", QVariant(0.0689475729));
}

float DepthPressure::pressureFactor() {
    return pressureUnits->itemData(pressureUnits->currentIndex()).toFloat();
}

float DepthPressure::depthFactor() {
    return depthUnits->itemData(depthUnits->currentIndex()).toFloat();
}

float DepthPressure::waterConstant() {
    return waterType->itemData(waterType->currentIndex()).toFloat();
}

void DepthPressure::on_calcButton_clicked() {
    QString depthText = depthEdit->text();
    QString pressureText = pressureEdit->text();
    if(!depthText.isEmpty()) {
        float depth = depthText.toFloat();
        calcPressure(depth);
    } else if (!pressureText.isEmpty()) {
        float pressure = pressureText.toFloat();
        calcDepth(pressure);
    }
}

void DepthPressure::calcPressure(float depth) {
    float pressure = (depth * depthFactor()) * waterConstant();
    pressure = pressure * pressureFactor();
    QString pressureText;
    pressureText.setNum(pressure);
    pressureEdit->setText(pressureText);
}

void DepthPressure::calcDepth(float pressure) {
    qDebug() << "Pressure Factor: " << pressureFactor();
    float depth = ( pressure * pressureFactor() ) / waterConstant();
    QString depthText;
    depthText.setNum(depth);
    depthEdit->setText(depthText);
}