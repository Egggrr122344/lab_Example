#include <gtest/gtest.h>
#include "Triangle.h"
#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <cmath>

TEST(triangleConstructor_Test1, valid_data) {
    Point p1(0,0);
    Point p2(100,0);
    Point p3(23,150);
    EXPECT_NO_THROW(Triangle(p1, p2, p3));
}

TEST(operator_doubleTest2, successful) {
    Point p1(1,0);
    Point p2(0,0);
    Point p3(0,1);

    Triangle tr(p1, p2, p3);
    
    double area = tr.operator double();
    double exception = 1e-10;

    EXPECT_TRUE(area - 1.0 < exception);
}