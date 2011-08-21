CONFIG -= app_bundle
CONFIG += qtestlib console silent

INCLUDEPATH += ../external/qextserialport/src
LIBS += -L../external/qextserialport/src/build -lqextserialport


HEADERS += serialtest.h

SOURCES += testmain.cpp