#include <gtest/gtest.h>

#include <Common/gameproperties.h>
#include <Model/bullet.h>
#include <Model/tank.h>

namespace {
//TODO: get rid of helper and including of moc file. Use advanced testing framework
    class ShotHelper: public QObject {
        Q_OBJECT
    public slots:
        void onShotMade(const std::shared_ptr<Bullet>& i_bullet) {
            m_bullet = i_bullet;
        }

        std::shared_ptr<Bullet> bullet() {
            return m_bullet;
        }

    private:
        std::shared_ptr<Bullet> m_bullet;
    };
}

TEST(tst_tank, defaultInitialization) {
    Tank tank;
    ASSERT_EQ(tank.x(), 0);
    ASSERT_EQ(tank.y(), 0);
}

TEST(tst_tank, initializationWithParameters) {
    Tank tank(Position(10, 10), Common::EDirection::LEFT);

    ASSERT_EQ(tank.x(), 10);
    ASSERT_EQ(tank.y(), 10);
}

TEST(tst_tank, tankMoveDown) {
    Tank tank;

    tank.moveDown();

    ASSERT_EQ(tank.x(), 0);
    ASSERT_EQ(tank.y(), 1);
}

TEST(tst_tank, tankMoveRight) {
    Tank tank;

    tank.moveRight();

    ASSERT_EQ(tank.x(), 1);
    ASSERT_EQ(tank.y(), 0);
}

TEST(tst_tank, tankMoveLeft) {
    Tank tank(Position(10, 10));

    tank.moveLeft();

    ASSERT_EQ(tank.x(), 9);
    ASSERT_EQ(tank.y(), 10);
}

TEST(tst_tank, tankMoveUp) {
    Tank tank(Position(10, 10));

    tank.moveUp();

    ASSERT_EQ(tank.x(), 10);
    ASSERT_EQ(tank.y(), 9);
}

TEST(tst_tank, tankMoveOutOfLowerBound) {
    Tank tank(Position(10, GameProperties::fieldHeight()));

    tank.moveDown();

    ASSERT_EQ(tank.x(), 10);
    ASSERT_EQ(tank.y(), GameProperties::fieldHeight());
}

TEST(tst_tank, tankMoveOutOfUpperBound) {
    Tank tank(Position(10, 0));

    tank.moveUp();

    ASSERT_EQ(tank.x(), 10);
    ASSERT_EQ(tank.y(), 0);
}

TEST(tst_tank, tankMoveOutOfLeftBound) {
    Tank tank(Position(0, 0));

    tank.moveLeft();

    ASSERT_EQ(tank.x(), 0);
    ASSERT_EQ(tank.y(), 0);
}

TEST(tst_tank, tankMoveOutOfRightBound) {
    Tank tank(Position(GameProperties::fieldWidth(), 0));

    tank.moveRight();

    ASSERT_EQ(tank.x(), GameProperties::fieldWidth());
    ASSERT_EQ(tank.y(), 0);
}

TEST(tst_tank, tankMakesShotUP) {
    Tank tank(Position(36, 36), Common::EDirection::UP);
    ShotHelper helper;

    QObject::connect(&tank, SIGNAL(shot(std::shared_ptr<Bullet>)), &helper, SLOT(onShotMade(const std::shared_ptr<Bullet>&)));
    tank.makeShot();

    ASSERT_EQ(helper.bullet()->x(), 48);
    ASSERT_EQ(helper.bullet()->y(), 32);
}

TEST(tst_tank, tankMakesShotRIGHT) {
    Tank tank(Position(36, 36), Common::EDirection::RIGHT);
    ShotHelper helper;

    QObject::connect(&tank, SIGNAL(shot(std::shared_ptr<Bullet>)), &helper, SLOT(onShotMade(const std::shared_ptr<Bullet>&)));
    tank.makeShot();

    ASSERT_EQ(helper.bullet()->x(), 68);
    ASSERT_EQ(helper.bullet()->y(), 47);
}

TEST(tst_tank, tankMakesShotDOWN) {
    Tank tank(Position(36, 36), Common::EDirection::DOWN);
    ShotHelper helper;

    QObject::connect(&tank, SIGNAL(shot(std::shared_ptr<Bullet>)), &helper, SLOT(onShotMade(const std::shared_ptr<Bullet>&)));
    tank.makeShot();

    ASSERT_EQ(helper.bullet()->x(), 48);
    ASSERT_EQ(helper.bullet()->y(), 68);
}

TEST(tst_tank, tankMakesShotLEFT) {
    Tank tank(Position(36, 36), Common::EDirection::LEFT);
    ShotHelper helper;

    QObject::connect(&tank, SIGNAL(shot(std::shared_ptr<Bullet>)), &helper, SLOT(onShotMade(const std::shared_ptr<Bullet>&)));
    tank.makeShot();

    ASSERT_EQ(helper.bullet()->x(), 32);
    ASSERT_EQ(helper.bullet()->y(), 47);
}


#include <tst_tank.moc>
