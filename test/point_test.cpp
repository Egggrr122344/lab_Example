#include <gtest/gtest.h>
#include "Point.h"
#include <cmath>

TEST(constructor_point_test1, normal) {
  Point test(3, 5);
  EXPECT_EQ(test.getX(), 3);
  EXPECT_EQ(test.getY(), 5);
}

TEST(equal_operator_point_test1, true_test) {
  Point test0(3.1, 5.2);
  Point test1(3.1, 5.2);

  EXPECT_TRUE(test0 == test1);
}

TEST(equal_operator_point_test2, false_test) {
  Point test0(3.1, 5.2);
  Point test1(2, 9);

  EXPECT_FALSE(test0 == test1);
}

TEST(distance_from_point1_to_point2, normal) {
  Point p1(4, 5);
  Point p2(8, 9);

  double len = Point::dist(p1, p2);
  double exception = 1e-5;

  EXPECT_TRUE(len - 5.65685 < exception);
}
