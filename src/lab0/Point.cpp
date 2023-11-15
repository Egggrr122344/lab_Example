#include <Point.h>
#include <cmath>

Point::Point() = default;

Point::Point(double x, double y) {
    this -> x = x;
    this -> y = y;
}

Point Point:: createPoint(double x, double y) {
    return Point(x,y);
}

double Point:: dist(const Point& p1, const Point& p2) {
    double distX = p2.getX() - p1.getX();
    double distY = p2.getY() - p1.getY();

    double distance = std::sqrt(distX * distX + distY * distY);
    return distance;

}

double Point::getX() const noexcept {
    return x;
}

double Point::getY() const noexcept {
    return y;
}

void Point::setX(double x) noexcept {
    this -> x = x;
}

void Point::setY(double y) noexcept {
    this -> y = y;
}

bool operator==(const Point& p1, const Point& p2) {
    double exception = 1e-5;

    return (std::abs(p1.getX() - p2.getX())) && (std::abs(p1.getY() == p2.getY()));
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}

std::istream& operator>> (std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<< ( std::ostream& out, const Point& p ) {
    out << '(' << p.x << ',' << p.y << ')';
    return out;
}