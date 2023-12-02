#include <gtest/gtest.h>
#include "Hexagon.h"
#include "Vector.h"
#include "Point.h"
#include <cmath>
#include "/com.docker.devenvironments.code/src/lab0/Hexagon.cpp"
#include "/com.docker.devenvironments.code/src/lab0/Vector.cpp"
#include "/com.docker.devenvironments.code/src/lab0/Point.cpp"

TEST(hexagonConstructor_Test1, valid_data) {
    Point<double> px1(10,10);
    Point<double> px2(px1.get_x()-1, px1.get_y());
    Point<double> px3(px1.get_x()-1.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px4(px1.get_x() + 0.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px5(px1.get_x() - 1, px1.get_y() - std::sqrt(3));
    Point<double> px6(px1.get_x(), px1.get_y() - std::sqrt(3));

    EXPECT_NO_THROW(Hexagon<double>(px1,px2,px3,px4,px5,px6));
}

TEST(hexagonConstructor_Test2, invalid_data) {
    Point<double> px1(10,10);
    Point<double> px2(px1.get_x()-10, px1.get_y());
    Point<double> px3(px1.get_x()-1.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px4(px1.get_x() + 0.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px5(px1.get_x() - 1, px1.get_y() - std::sqrt(3));
    Point<double> px6(px1.get_x(), px1.get_y() - std::sqrt(3));

    EXPECT_THROW(Hexagon<double>(px1,px2,px3,px4,px5,px6), std::invalid_argument );
}

TEST(Calculate_centre_hex_test, true_result) {
    Point<double>  px1(10,10);
    Point<double> px2(px1.get_x()-1, px1.get_y());
    Point<double> px3(px1.get_x()-1.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px4(px1.get_x() + 0.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px5(px1.get_x() - 1, px1.get_y() - std::sqrt(3));
    Point<double> px6(px1.get_x(), px1.get_y() - std::sqrt(3));

    Hexagon<double> hex(px1, px2, px3, px4, px5, px6);

    Point<double> centre = hex.calculate_centre();
    double exception = 1e-5;

    EXPECT_TRUE(centre.get_x() - 10 < exception);
    EXPECT_TRUE(centre.get_y() - 13.4142 < exception);
}

TEST(Calculate_area_hex_test, true_result) {
    Point<double> px1(10,10);
    Point<double> px2(px1.get_x()-1, px1.get_y());
    Point<double> px3(px1.get_x()-1.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px4(px1.get_x() + 0.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px5(px1.get_x() - 1, px1.get_y() - std::sqrt(3));
    Point<double> px6(px1.get_x(), px1.get_y() - std::sqrt(3));

    Hexagon<double> hex(px1, px2, px3, px4, px5, px6);

    double area = static_cast<double>(hex);
    double result = 4.82843;
    double exception = 1e-5;

    EXPECT_TRUE(area - result < exception);
}

TEST(Calculate_center_hex_test, true_result) {
    Point<double> px1(10,10);
    Point<double> px2(px1.get_x()-1, px1.get_y());
    Point<double> px3(px1.get_x()-1.5, px1.get_y() - sqrt(3)/2);
    Point<double> px4(px1.get_x() + 0.5, px1.get_y() - sqrt(3)/2);
    Point<double> px5(px1.get_x() - 1, px1.get_y() - sqrt(3));
    Point<double> px6(px1.get_x(), px1.get_y() - sqrt(3));

    Hexagon<double> hex(px1, px2, px3, px4, px5, px6);

    Point<double> center = hex.calculate_centre();
    
    double exception = 1e-5;

    EXPECT_TRUE(center.get_x() - 9.5 < exception);
    EXPECT_TRUE(center.get_y() - 9.13397 < exception);
    
}

TEST(operator_equal, normal) {
    Point<double> px1(10,10);
    Point<double> px2(px1.get_x()-1, px1.get_y());
    Point<double> px3(px1.get_x()-1.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px4(px1.get_x() + 0.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px5(px1.get_x() - 1, px1.get_y() - std::sqrt(3));
    Point<double> px6(px1.get_x(), px1.get_y() - std::sqrt(3));

    Hexagon<double> hex1(px1, px2, px3, px4, px5, px6);
    Hexagon<double> hex2(px1, px2, px3, px4, px5, px6);

    EXPECT_TRUE(hex1 == hex2);
}

TEST(operator_equal, false_rezult) {
    Point<double> px1(10,10);
    Point<double> px2(px1.get_x()-1, px1.get_y());
    Point<double> px3(px1.get_x()-1.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px4(px1.get_x() + 0.5, px1.get_y() - std::sqrt(3)/2);
    Point<double> px5(px1.get_x() - 1, px1.get_y() - std::sqrt(3));
    Point<double> px6(px1.get_x(), px1.get_y() - std::sqrt(3));

    Hexagon<double> hex1(px1, px2, px3, px4, px5, px6);
    Hexagon<double> hex2(px1, px2, px3, px4, px5, px6);

    EXPECT_FALSE(hex1 != hex2);
}