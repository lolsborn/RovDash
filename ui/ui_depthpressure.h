/********************************************************************************
** Form generated from reading UI file 'depthpressure.ui'
**
** Created: Sat Aug 20 20:33:48 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPTHPRESSURE_H
#define UI_DEPTHPRESSURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DepthPressure
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QComboBox *waterType;
    QLabel *depthLabel;
    QLineEdit *depthEdit;
    QComboBox *depthUnits;
    QLabel *pressureLabel;
    QLineEdit *pressureEdit;
    QComboBox *pressureUnits;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *calcButton;

    void setupUi(QDialog *DepthPressure)
    {
        if (DepthPressure->objectName().isEmpty())
            DepthPressure->setObjectName(QString::fromUtf8("DepthPressure"));
        DepthPressure->resize(391, 158);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DepthPressure->sizePolicy().hasHeightForWidth());
        DepthPressure->setSizePolicy(sizePolicy);
        DepthPressure->setSizeGripEnabled(false);
        horizontalLayout_2 = new QHBoxLayout(DepthPressure);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        waterType = new QComboBox(DepthPressure);
        waterType->setObjectName(QString::fromUtf8("waterType"));

        gridLayout->addWidget(waterType, 0, 1, 1, 2);

        depthLabel = new QLabel(DepthPressure);
        depthLabel->setObjectName(QString::fromUtf8("depthLabel"));
        depthLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(depthLabel, 1, 0, 1, 1);

        depthEdit = new QLineEdit(DepthPressure);
        depthEdit->setObjectName(QString::fromUtf8("depthEdit"));

        gridLayout->addWidget(depthEdit, 1, 1, 1, 1);

        depthUnits = new QComboBox(DepthPressure);
        depthUnits->setObjectName(QString::fromUtf8("depthUnits"));

        gridLayout->addWidget(depthUnits, 1, 2, 1, 1);

        pressureLabel = new QLabel(DepthPressure);
        pressureLabel->setObjectName(QString::fromUtf8("pressureLabel"));
        pressureLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pressureLabel, 2, 0, 1, 1);

        pressureEdit = new QLineEdit(DepthPressure);
        pressureEdit->setObjectName(QString::fromUtf8("pressureEdit"));

        gridLayout->addWidget(pressureEdit, 2, 1, 1, 1);

        pressureUnits = new QComboBox(DepthPressure);
        pressureUnits->setObjectName(QString::fromUtf8("pressureUnits"));

        gridLayout->addWidget(pressureUnits, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        calcButton = new QPushButton(DepthPressure);
        calcButton->setObjectName(QString::fromUtf8("calcButton"));

        horizontalLayout->addWidget(calcButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(DepthPressure);

        QMetaObject::connectSlotsByName(DepthPressure);
    } // setupUi

    void retranslateUi(QDialog *DepthPressure)
    {
        DepthPressure->setWindowTitle(QApplication::translate("DepthPressure", "Pressure & Depth", 0, QApplication::UnicodeUTF8));
        depthLabel->setText(QApplication::translate("DepthPressure", "Depth", 0, QApplication::UnicodeUTF8));
        pressureLabel->setText(QApplication::translate("DepthPressure", "Pressure", 0, QApplication::UnicodeUTF8));
        calcButton->setText(QApplication::translate("DepthPressure", "Calculate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DepthPressure: public Ui_DepthPressure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPTHPRESSURE_H
