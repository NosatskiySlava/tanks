#include "tst_tankstest.h"
#include "tst_bullet.h"

#include "testsuits.h"

#include <QtTest>

int main(int argc, char *argv[])
{
    QTEST_SET_MAIN_SOURCE_PATH

    int failedSuitsCount = 0;
    for(auto suit: TestSuits::suits()) {
        if (QTest::qExec(suit, argc, argv))
            ++failedSuitsCount;
    }

    return failedSuitsCount;
}
