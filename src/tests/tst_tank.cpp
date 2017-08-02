#include <gtest/gtest.h>

#include <Common/gameproperties.h>
#include <Model/tank.h>

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
