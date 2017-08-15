#include <gtest/gtest.h>

#include <Model/bullet.h>

TEST(tst_bullet, moveUp) {
   Bullet bullet(Position(10, 10), Common::EDirection::UP);
   bullet.move();

   ASSERT_EQ(bullet.x(), 10);
   ASSERT_EQ(bullet.y(), 9);
   ASSERT_EQ(bullet.dir(), Common::EDirection::UP);
}

TEST(tst_bullet, moveLeft) {
   Bullet bullet(Position(10, 10), Common::EDirection::LEFT);
   bullet.move();

   ASSERT_EQ(bullet.x(), 9);
   ASSERT_EQ(bullet.y(), 10);
   ASSERT_EQ(bullet.dir(), Common::EDirection::LEFT);
}

TEST(tst_bullet, moveDown) {
   Bullet bullet(Position(10, 10), Common::EDirection::DOWN);
   bullet.move();

   ASSERT_EQ(bullet.x(), 10);
   ASSERT_EQ(bullet.y(), 11);
   ASSERT_EQ(bullet.dir(), Common::EDirection::DOWN);
}

TEST(tst_bullet, moveRight) {
   Bullet bullet(Position(10, 10), Common::EDirection::RIGHT);
   bullet.move();

   ASSERT_EQ(bullet.x(), 11);
   ASSERT_EQ(bullet.y(), 10);
   ASSERT_EQ(bullet.dir(), Common::EDirection::RIGHT);
}
