#include <gtest/gtest.h>

#include <Common/position.h>

TEST(tst_position, addition) {
    Position p1(10, 10);
    Position p2(4, -3);

    ASSERT_EQ(p1 + p2, Position(14,7));
}

TEST(tst_position, comparisonEQ) {
    Position p1(4, 4);
    Position p2(4, 4);

    ASSERT_TRUE(p1 == p2);
}

TEST(tst_position, comparisonNEQ) {
    Position p1(10, 10);
    Position p2(4, -3);

    ASSERT_TRUE(p1 != p2);
}
