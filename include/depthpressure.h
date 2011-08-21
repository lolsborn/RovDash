#pragma once

#include "ui_depthpressure.h"
#include <QDialog>

 class DepthPressure : public QDialog, private Ui::DepthPressure {
      Q_OBJECT

    public:
        DepthPressure();
    private:
        void calcPressure(float depth);
        void calcDepth(float pressure);
        float waterConstant();
        float pressureFactor();
        float depthFactor();
    private slots:
        void on_calcButton_clicked();
};