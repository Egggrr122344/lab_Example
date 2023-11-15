#include "Hexagon.h"

#include <cmath>

using namespace std;

bool Hexagon::validate(    
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
    ) noexcept {

    double sumX = p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX() + p6.getX();

    double sumY = p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY() + p6.getY();

    Point center = Point::createPoint(sumX / 6.0, sumY / 6.0);

    double exception = 1e-5;

    // Длина сторон

    double dist_p1p2 = Point::dist(p1, p2);
    double dist_p2p3 = Point::dist(p2, p3);
    double dist_p3p4 = Point::dist(p3, p4);
    double dist_p4p5 = Point::dist(p4, p5);
    double dist_p5p6 = Point::dist(p5, p6);
    double dist_p1p6 = Point::dist(p1, p6);

    // Расстояние от точек до центра 

    double center_p1 = Point::dist(center, p1);
    double center_p2 = Point::dist(center, p2);
    double center_p3 = Point::dist(center, p3);
    double center_p4 = Point::dist(center, p4);
    double center_p5 = Point::dist(center, p5);
    double center_p6 = Point::dist(center, p6);


    if (dist_p1p2 > exception && dist_p2p3 > exception &&
        dist_p3p4 > exception && dist_p4p5 > exception &&
        dist_p5p6 > exception && dist_p1p6 > exception
    ) {
        if (abs(dist_p1p2 - dist_p2p3) < exception &&
            abs(dist_p2p3 - dist_p3p4) < exception &&
            abs(dist_p3p4 - dist_p4p5) < exception &&
            abs(dist_p4p5 - dist_p5p6) < exception &&
            abs(dist_p4p5 - dist_p1p6) < exception
        ) {
            if (
                abs(center_p1 - center_p2) < exception &&
                abs(center_p2 - center_p3) < exception &&
                abs(center_p3 - center_p4) < exception &&
                abs(center_p4 - center_p5) < exception && 
                abs(center_p5 - center_p6) < exception
            ) {
                return true;
            }
        }
    }

    return false;
}

Hexagon::Hexagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
    ) {

    bool is_hexagon = validate(p1, p2, p3, p4, p5, p6);

    if (!is_hexagon) {
        throw invalid_argument("Invalid points. Hexagon can't be created!");
    }

    points = {p1, p2, p3, p4, p5, p6};
}

Point Hexagon::calculateCentre() const {
  double center_x = 0;
  double center_y = 0;

  for (size_t i = 0; i < points.get_size(); ++i) {
    center_x += points[i].getX();
    center_y += points[i].getY();
  }

  return Point(center_x / 6.0, center_y / 6.0);
}

Hexagon::operator double() const {
  double len = Point::dist(points[0], points[1]);

  return 3.0 * sqrt(3) * pow(len, 2) / 2.0;
}

bool operator==(const Hexagon& first, const Hexagon& second) {
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


ostream& operator<<(ostream& os, const Hexagon& hex) {
  for (size_t i = 0; i < hex.points.get_size(); ++i) {
    os << hex.points[i];
  }
  return os;
}

istream& operator>>(istream& is, Hexagon& hex) {
  is >> hex.points[0] >> hex.points[1] >> hex.points[2] >> 
        hex.points[3] >> hex.points[4] >> hex.points[5];
  return is;
}