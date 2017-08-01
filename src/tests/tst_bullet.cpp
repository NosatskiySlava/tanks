#include "tst_bullet.h"

#include <Model/bullet.h>

BulletTest::BulletTest()
{
}

void BulletTest::testCase1()
{
    Bullet b;
    QVERIFY2(b.x() == 1, "Failure");
}

static BulletTest bt;

