#include "Octagon.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Vector.h"
#include <cmath>

using namespace std;

int main() {
    Triangle* t0 = new Triangle(Point(0,0), Point(100,0), Point (23, 150));
    Point p1(0,0),p2(100,0),p3(23,150);
    Triangle tr (p1,p2,p3);
    cout << tr.calculateCentre() << endl;
    // Hexagon* t1 = new Hexagon(Point(0,0), Point(1,0), Point (2, 0), Point(2,1), Point(1,2), Point(0,2));

    Vector<Figure*> v = {t0};
    double area = 0;
    for (size_t i = 0; i < v.get_size(); i++) {
        area += static_cast<double>(*v[i]);
    }

    cout << area << endl;
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