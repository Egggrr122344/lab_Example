#include "Octagon.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Vector.h"
#include "Point.h"
#include <cmath>

using namespace std;

int main() {
    Point p10(0,0),p20(100,0),p30(23,150);
    Triangle* t0 = new Triangle(p10,p20,p30);
    
    Triangle tr (p10,p20,p30);
    cout << tr.calculateCentre() <<endl << tr.operator double() << endl;
Point p1(10, 10);
Point p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
Point p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
Point p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
Point p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);
Point p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
Point p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
Point p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));

    Octagon* t1 = new Octagon(p1,p2,p3,p4,p5,p6,p7,p8);
    Octagon oct1 (p1,p2,p3,p4,p5,p6,p7,p8);
    cout << oct1.calculateCentre() << endl << oct1.operator double() << endl;

    // Hexagon* t1 = new Hexagon(Point(0,0), Point(1,0), Point (2, 0), Point(2,1), Point(1,2), Point(0,2));

    // Vector<Figure*> v = {t0};
    // double area = 0;
    // for (size_t i = 0; i < v.get_size(); i++) {
    //     area += static_cast<double>(*v[i]);
    // }

    // cout << area << endl;
//     Rhombus* t0 = new Rhombus(Point(4, 4), Point(7, 2), Point(4, 0), Point(1, 2));
//     Rhombus* t1 = new Rhombus(Point(3, 0), Point(0, -2), Point(-3, 0), Point(0, 2));
//     Pentagon* s0 = new Pentagon(Point(0, 100), 
//                                 Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)),
//                                 Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(5 + sqrt(5)) / 2.0, -25 - 25 * sqrt(5)),
//                                 Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(5 + sqrt(5)) / 2.0, -25 - 25 * sqrt(5)),
//                                 Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
//     Vector<Figure*> v = {t0, t1, s0};
//     double area = 0;

//     for (size_t i = 0; i < v.get_size(); ++i) {
//         area += static_cast<double>(*v[i]);
//     }

//     cout << area << endl;
 }