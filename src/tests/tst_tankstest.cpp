#include "tst_tankstest.h"

#include <Model/tank.h>

TanksTest::TanksTest()
{
}

void TanksTest::testCase1()
{
    Tank t;
    QVERIFY2(t.x() == 0, "Failure");
}

static TanksTest tt;

