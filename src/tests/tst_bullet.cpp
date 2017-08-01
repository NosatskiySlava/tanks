#include "tst_bullet.h"

#include <Model/bullet.h>

BulletTest::BulletTest()
{
}

void BulletTest::initialDefaultPosition()
{
    Bullet b;
    QCOMPARE(b.x(), 0);
    QCOMPARE(b.y(), 0);
}

void BulletTest::initialPosition() {
    Bullet b(Position(10, 10), Common::EDirection::DOWN);
    QCOMPARE(b.x(), 10);
    QCOMPARE(b.y(), 10);
    QCOMPARE(b.dir(), Common::EDirection::DOWN);
}

static BulletTest bt;

