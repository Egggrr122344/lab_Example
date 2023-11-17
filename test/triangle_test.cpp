#include <gtest/gtest.h>
#include "Triangle.h"
#include "Vector.h"
#include "Point.h"
#include <cmath>

TEST(Constructor_Test1, valid_data) {
    Point p1(0,0);
    Point p2(100,0);
    Point p3(23,150);
    EXPECT_NO_THROW(Triangle(p1, p2, p3));
}

TEST(area_Test2, successful) {
    Point p1(1,0);
    Point p2(0,0);
    Point p3(0,1);

    Triangle tr(p1, p2, p3);
    
    double area = tr.operator double();
    double exception = 1e-10;
    

    EXPECT_TRUE(area - 0.5 < exception);
    
    
}

TEST(centre_test3, valid) {
    Point p1(1,0);
    Point p2(0,0);
    Point p3(0,1);

    Triangle tr(p1, p2, p3);
    
    Point center = tr.calculateCentre();
    double exception = 1e-10;
    

    EXPECT_TRUE(center.getX() - 1 < exception);
    EXPECT_TRUE(center.getY() - 1 < exception);
}

TEST(is_equal, true_test) {
    Point p1(1,0);
    Point p2(0,0);
    Point p3(0,1);

    Point pp1(1,0);
    Point pp2(0,0);
    Point pp3(0,1);

    Triangle tr1(p1, p2, p3);
    Triangle tr2(pp1, pp2, pp3);

    EXPECT_TRUE(tr1 == tr2);
}

TEST(centre_test4, true_test) {

    Triangle test1(Point(0,0), Point(0,1), Point(1,0));
    Triangle test2(Point(0,0), Point(0,1), Point(1,0));

    EXPECT_TRUE(test1 == test2);
}


TEST(constructor_test1_tr, valid_data) {
    EXPECT_NO_THROW(Triangle test(Point(0, 0), Point(5, std::sqrt(3) * 5), Point(10, 0)));

}


TEST(calculate_centre_test_triangle, normal) {

  Triangle test(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));
  Point t = test.calculateCentre();
  double exception = 1e-5;
  EXPECT_TRUE((t.getX() - 7) < exception);
  EXPECT_TRUE((t.getY() - 4.88765) < exception);

}

TEST(is_equal_operator_test2_tr, false_test) {
  Triangle test(Point(3, 3), Point(8, 3 + std::sqrt(3) * 5), Point(13, 3));
  Triangle test1(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));

  EXPECT_FALSE(test == test1);
}