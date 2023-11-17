#include <gtest/gtest.h>
#include "Octagon.h"
#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <cmath>

TEST(octagonConstructor_Test1, valid_data) {
    Point p1(10, 10);
    Point p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
    Point p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
    Point p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
    Point p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);
    Point p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
    Point p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
    Point p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));
EXPECT_NO_THROW(Octagon(p1, p2, p3, p4, p5, p6, p7, p8));

}


TEST(octagonConstructor_Test2, invalid_data) {
    Point p1(10, 10);
    Point p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
    Point p3(p2.getX() - 10, p2.getY() + 1 + std::sqrt(2));
    Point p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
    Point p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);
    Point p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
    Point p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
    Point p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));
EXPECT_THROW(Octagon(p1, p2, p3, p4, p5, p6, p7, p8), invalid_argument);
} 