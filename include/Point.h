#ifndef POINT
#define POINT

#include <iostream>

using namespace std;

struct Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);

    static Point createPoint(double x, double y);
    static double dist(const Point& p1, const Point& p2); 

    double getX () const noexcept;
    double getY () const noexcept;

    void setX ( double x ) noexcept;
    void setY ( double y ) noexcept;

    friend bool operator==( const Point& p1, const Point& p2);
    friend bool operator!=( const Point& p1, const Point& p2);

    friend istream& operator>>( istream&, Point& p);
    friend ostream& operator<<( ostream&, const Point& p);

};

#endif