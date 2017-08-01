#ifndef TST_TANKSTEST_H
#define TST_TANKSTEST_H

#include "testsuits.h"

#include <QtTest>

class TanksTest : public TestSuits
{
    Q_OBJECT

public:
    TanksTest();

private slots:
    void testCase1();
};

#endif // TST_TANKSTEST_H

