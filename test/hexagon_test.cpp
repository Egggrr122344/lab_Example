#include <gtest/gtest.h>
#include "Hexagon.h"
#include "Vector.h"
#include "Point.h"
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

TEST(Calculate_centre_hex_test, true_result) {
    Point px1(10,10);
    Point px2(px1.getX()-1, px1.getY());
    Point px3(px1.getX()-1.5, px1.getY() - sqrt(3)/2);
    Point px4(px1.getX() + 0.5, px1.getY() - sqrt(3)/2);
    Point px5(px1.getX() - 1, px1.getY() - sqrt(3));
    Point px6(px1.getX(), px1.getY() - sqrt(3));

    Hexagon hex(px1, px2, px3, px4, px5, px6);

    Point center = hex.calculateCentre();
    double exception = 1e-5;

    EXPECT_TRUE(center.getX() - 10 < exception);
    EXPECT_TRUE(center.getY() - 10 < exception);
}

TEST(Calculate_area_hex_test, true_result) {
    Point px1(10,10);
    Point px2(px1.getX()-1, px1.getY());
    Point px3(px1.getX()-1.5, px1.getY() - sqrt(3)/2);
    Point px4(px1.getX() + 0.5, px1.getY() - sqrt(3)/2);
    Point px5(px1.getX() - 1, px1.getY() - sqrt(3));
    Point px6(px1.getX(), px1.getY() - sqrt(3));

    Hexagon hex(px1, px2, px3, px4, px5, px6);

    double area = hex.operator double();
    double result = 2.59808;
    double exception = 1e-5;

    EXPECT_TRUE(area - result < exception);
}

TEST(Calculate_center_hex_test, true_result) {
    Point px1(10,10);
    Point px2(px1.getX()-1, px1.getY());
    Point px3(px1.getX()-1.5, px1.getY() - sqrt(3)/2);
    Point px4(px1.getX() + 0.5, px1.getY() - sqrt(3)/2);
    Point px5(px1.getX() - 1, px1.getY() - sqrt(3));
    Point px6(px1.getX(), px1.getY() - sqrt(3));

    Hexagon hex(px1, px2, px3, px4, px5, px6);

    Point center = hex.calculateCentre();
    Point result(9.5,9.13397);
    double exception = 1e-5;

    EXPECT_TRUE(center.getX() - result.getX() < exception);
    EXPECT_TRUE(center.getY() - result.getY() < exception);
    
}

TEST(operator_equal, normal) {
    Point px1(10,10);
    Point px2(px1.getX()-1, px1.getY());
    Point px3(px1.getX()-1.5, px1.getY() - sqrt(3)/2);
    Point px4(px1.getX() + 0.5, px1.getY() - sqrt(3)/2);
    Point px5(px1.getX() - 1, px1.getY() - sqrt(3));
    Point px6(px1.getX(), px1.getY() - sqrt(3));

    Hexagon hex1(px1, px2, px3, px4, px5, px6);
    Hexagon hex2(px1, px2, px3, px4, px5, px6);

    EXPECT_TRUE(hex1 == hex2);
}

TEST(operator_equal, false_rezult) {
    Point px1(10,10);
    Point px2(px1.getX()-1, px1.getY());
    Point px3(px1.getX()-1.5, px1.getY() - sqrt(3)/2);
    Point px4(px1.getX() + 0.5, px1.getY() - sqrt(3)/2);
    Point px5(px1.getX() - 1, px1.getY() - sqrt(3));
    Point px6(px1.getX(), px1.getY() - sqrt(3));

    Hexagon hex1(px1, px2, px3, px4, px5, px6);
    Hexagon hex2(px1, px2, px3, px4, px5, px6);

    EXPECT_FALSE(hex1 != hex2);
}