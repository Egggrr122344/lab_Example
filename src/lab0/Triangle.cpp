#include "Triangle.h"

#include <cmath>

using namespace std;


bool Triangle:: validate(const Point& p1, const Point& p2, const Point& p3) noexcept {
   
    double sumX = p1.getX() + p2.getX() + p3.getX();
    double sumY = p1.getY() + p2.getY() + p3.getY();

    double centerX = sumX / 3.0;
    double centerY = sumY / 3.0;

    Point center = Point::createPoint(centerX, centerY);
     // distance from points

    double p1_p2 = Point::dist(p1,p2);
    double p2_p3 = Point::dist(p2,p3);
    double p1_p3 = Point::dist(p1,p3);

    // distance from center

    double center_p1 = Point::dist(center,p1);
    double center_p2 = Point::dist(center,p2);
    double center_p3 = Point::dist(center,p3);

    // минимальная штука

    double exception = 1e-5;

    // Сумму каждых двух сторон

    double sum1 = p1_p2 + p2_p3;
    double sum2 = p2_p3 + p1_p3;
    double sum3 = p1_p2 + p1_p3;

    if ( (p1_p2 > exception) && (p2_p3 > exception) && (p1_p3 > exception)) {
        if ( ( sum1 > p1_p3) && (sum2 > p1_p2) && (sum3 > p2_p3) ) {

                return true;
            }
        return false;
        }
    return false;
// Валидация на соответствие свойства треугольника
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)  {

    bool is_triangle = validate(p1,p2,p3);

    if (!is_triangle) {
        throw invalid_argument("Invalid points. Triangle can't be created!");
    }

    points = {p1,p2,p3};

}

Point Triangle::calculateCentre() const {
    double center_x = 0;
    double center_y = 0;

    for (size_t i {0}; i < points.get_size(); i++) {
        center_x += points[i].getX();
        center_y += points[i].getY();
    }

    return Point(center_x / 3.0, center_y / 3.0);
}

 Triangle:: operator double() const {
    

    double A = Point::dist(points[0], points[1]);

    double B = Point::dist(points[1], points[2]);

    double C = Point::dist(points[2], points[3]);

    double p = 0.5 * (A + B + C);

    double area = sqrt(p * (p - A ) * (p - B) * (p - C));

    return area;
}


bool operator==(const Triangle& first, const Triangle& second) {
  for (size_t i = 0; i < first.points.get_size(); ++i) {
    bool flag = false;

    for (size_t j = 0; j < second.points.get_size(); ++j) {
      if (first.points[i] == second.points[j]) {
        flag = true;
        break;
      }
    }

    if (!flag) {
      return false;
    }
  }

  return true;
}


ostream& operator<<(ostream& os, const Triangle& triangle) {
  for (size_t i = 0; i < triangle.points.get_size(); ++i) {
    os << triangle.points[i];
  }
  return os;
}

istream& operator>>(istream& is, Triangle& tr) {
  is >> tr.points[0] >> tr.points[1] >> tr.points[2];
        
  return is;
}





