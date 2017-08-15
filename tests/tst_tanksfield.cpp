#include <gtest/gtest.h>

#include <Model/tanksfield.h>
#include <Model/bullet.h>

class HitDetector: public QObject {
    Q_OBJECT

public:
    HitDetector()
        : hit(false)
    {

    }

    bool isHit() const {
        return hit;
    }

public slots:
    void onHit() {
        hit = true;
    }

private:
    bool hit;
};

TEST(tst_tanksfiled, isHit) {
    TanksField field;
    std::shared_ptr<Bullet> bullet(new Bullet(Position(), Common::EDirection::UP));
    HitDetector hitDetector;
    QObject::connect(bullet.get(), SIGNAL(hit(void)), &hitDetector, SLOT(onHit(void)));

    field.addBullet(bullet);
    field.update();

    ASSERT_TRUE(hitDetector.isHit());
}

TEST(tst_tanksfiled, noHit) {
    TanksField field;
    std::shared_ptr<Bullet> bullet(new Bullet(Position(10, 10), Common::EDirection::UP));
    HitDetector hitDetector;
    QObject::connect(bullet.get(), SIGNAL(hit(void)), &hitDetector, SLOT(onHit(void)));

    field.addBullet(bullet);
    field.update();

    ASSERT_FALSE(hitDetector.isHit());
}

#include <tst_tanksfield.moc>
