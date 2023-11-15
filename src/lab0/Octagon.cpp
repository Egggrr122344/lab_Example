#include "Octagon.h"

#include <cmath>

using namespace std;

bool Octagon::validate(
const Point& p1,
const Point& p2,
const Point& p3,
const Point& p4,
const Point& p5,
const Point& p6,
const Point& p7,
const Point& p8
) noexcept
{
    double sumX = p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX() + p6.getX() + p7.getX() + p8.getX();
    double sumY = p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY() + p6.getY() + p7.getY() + p8.getY();

    Point center = Point::createPoint(sumX / 8.0, sumY / 8.0);

    double exception = 1e-5; 

    // Длина сторон

    double dist_p1p2 = Point::dist(p1,p2);
    double dist_p2p3 = Point::dist(p2,p3);
    double dist_p3p4 = Point::dist(p3,p4);
    double dist_p4p5 = Point::dist(p4,p5);
    double dist_p5p6 = Point::dist(p5,p6);
    double dist_p6p7 = Point::dist(p6,p7);
    double dist_p7p8 = Point::dist(p7,p8);
    double dist_p1p8 = Point::dist(p1,p8);

    // Расстояние от центра до точек

    double center_p1 = Point::dist(center,p1);
    double center_p2 = Point::dist(center,p2);
    double center_p3 = Point::dist(center,p3);
    double center_p4 = Point::dist(center,p4);
    double center_p5 = Point::dist(center,p5);
    double center_p6 = Point::dist(center,p6);
    double center_p7 = Point::dist(center,p7);
    double center_p8 = Point::dist(center,p8);
    

    if (dist_p1p2 > exception && 
        dist_p2p3 > exception && 
        dist_p3p4 > exception &&
        dist_p4p5 > exception && 
        dist_p5p6 > exception &&
        dist_p6p7 > exception &&
        dist_p7p8 > exception &&
        dist_p1p8 > exception
        ) 
        {
            if (abs(dist_p1p2 - dist_p2p3) < exception &&
                abs(dist_p2p3 - dist_p3p4) < exception &&
                abs(dist_p3p4 - dist_p4p5) < exception &&
                abs(dist_p4p5 - dist_p5p6) < exception &&
                abs(dist_p5p6 - dist_p6p7) < exception &&
                abs(dist_p6p7 - dist_p7p8) < exception &&
                abs(dist_p7p8 - dist_p1p8) < exception 
                )
            {
                if (abs (center_p1 - center_p2) < exception &&
                    abs (center_p2 - center_p3) < exception &&
                    abs (center_p3 - center_p4) < exception &&
                    abs (center_p4 - center_p5) < exception &&
                    abs (center_p5 - center_p6) < exception &&
                    abs (center_p6 - center_p7) < exception &&
                    abs (center_p7 - center_p8) < exception 
                    )
                {
                    return true;
                }

            }

        }

        return false;
}


Octagon::Octagon(
const Point& p1,
const Point& p2,
const Point& p3,
const Point& p4,
const Point& p5,
const Point& p6,
const Point& p7,
const Point& p8
) {
    bool is_octagon = validate(p1, p2, p3, p4, p5, p6, p7, p8);

    if (!is_octagon) {
        throw invalid_argument("Invalid points. Octagon can't be created!");
    }

    points = {p1, p2, p3, p4, p5, p6, p7, p8};
}


Point Octagon::calculateCentre() const {
    double center_x = 0;
    double center_y = 0;

  for (size_t i = 0; i < points.get_size(); ++i) {
    center_x += points[i].getX();
    center_y += points[i].getY();
  }

  return Point(center_x / 8.0, center_y / 8.0);
}


Octagon::operator double() const {
    // S = 2 * k * a², k = (1 + sqrt(2))

    double a = Point::dist(points[0], points[1]);

    double area = 2 * (1 + sqrt(2)) * pow(a,2);

    return area;
}


bool operator==(const Octagon& first, const Octagon& second) {
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


ostream& operator<<(ostream& os, const Octagon& oct) {
  for (size_t i = 0; i < oct.points.get_size(); ++i) {
    os << oct.points[i];
  }
  return os;
}

istream& operator>>(istream& is, Octagon& oct) {
  is >> oct.points[0] >> oct.points[1] >> oct.points[2] >> 
        oct.points[3] >> oct.points[4] >> oct.points[5] >>
        oct.points[6] >> oct.points[7];
  return is;
}