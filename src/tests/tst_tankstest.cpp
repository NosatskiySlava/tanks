#include <QString>
#include <QtTest>

#include <Model/tank.h>


class TanksTest : public QObject
{
    Q_OBJECT

public:
    TanksTest();

private Q_SLOTS:
    void testCase1();
};

TanksTest::TanksTest()
{
}

void TanksTest::testCase1()
{
    Tank t;
    QVERIFY2(t.x() == 0, "Failure");
}

QTEST_APPLESS_MAIN(TanksTest)

#include "tst_tankstest.moc"
