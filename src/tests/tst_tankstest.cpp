#include <QString>
#include <QtTest>

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
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TanksTest)

#include "tst_tankstest.moc"
