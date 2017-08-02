#include <gtest/gtest.h>

#include <Model/tank.h>


TEST(tst_tank, defaultInitialization) {
    Tank tank;
    ASSERT_EQ(tank.x(), 0);
    ASSERT_EQ(tank.y(), 0);
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

TEST(tst_tank, tankMovement) {
    Tank tank;

    tank.moveRight();
    tank.moveDown();
    tank.moveRight();
    tank.moveRight();
    tank.moveUp();
    tank.moveLeft();
    tank.moveUp();
    tank.moveRight();

    ASSERT_EQ(tank.x(), 1);
    ASSERT_EQ(tank.y(), 0);
}
