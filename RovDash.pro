INCLUDEPATH += ./include \
              ./ui \
              ./external/qextserialport/src \
              ./external/qwt-6.0/src/

LIBS += -L./external/qextserialport/src/build -lqextserialport \
        -L./external/qwt-6.0/lib/ -lqwt

HEADERS += include/mainwindow.h \
           include/depthpressure.h \

SOURCES += src/mainwindow.cpp \
           src/main.cpp \
           src/depthpressure.cpp

FORMS = ui/depthpressure.ui \
        ui/dashboard.ui

UI_DIR = ./ui

macx:LIBS += -framework IOKit -framework CoreFoundation