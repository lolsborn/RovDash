#include <QTest>
#include "serialtest.h"

int main(int argc, char* argv[]) {
    SerialTest serial;
    
    QTest::qExec(&serial, argc, argv);
    
    return 0;
}