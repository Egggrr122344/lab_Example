#include <gtest/gtest.h>
#include "Hexagon.h"
#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <cmath>
TEST(hexagonConstructor_Test1, valid_data) {
    Point px1(10,10);
    Point px2(px1.getX()-1, px1.getY());
    Point px3(px1.getX()-1.5, px1.getY() - sqrt(3)/2);
    Point px4(px1.getX() + 0.5, px1.getY() - sqrt(3)/2);
    Point px5(px1.getX() - 1, px1.getY() - sqrt(3));
    Point px6(px1.getX(), px1.getY() - sqrt(3));

    EXPECT_NO_THROW(Hexagon(px1,px2,px3,px4,px5,px6));
}

TEST(hexagonConstructor_Test2, invalid_data) {
    Point px1(10,10);
    Point px2(px1.getX()-10, px1.getY());
    Point px3(px1.getX()-1.5, px1.getY() - sqrt(3)/2);
    Point px4(px1.getX() + 0.5, px1.getY() - sqrt(3)/2);
    Point px5(px1.getX() - 1, px1.getY() - sqrt(3));
    Point px6(px1.getX(), px1.getY() - sqrt(3));

    EXPECT_THROW(Hexagon(px1,px2,px3,px4,px5,px6), invalid_argument );
}