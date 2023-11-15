#ifndef HEXAGON
#define HEXAGON

#include "Figure.h"

#include <iostream>

using namespace std;

class Hexagon: public Figure {
public:    
    Hexagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6);
    operator double() const override;
    Point calculateCentre() const override;

    friend ostream& operator<<(ostream&, const Hexagon& hex);
    friend istream& operator>>(istream&, Hexagon& hex);
    friend bool operator==(const Hexagon& hex1, const Hexagon& hex2);


private:
    bool validate(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6) noexcept;


};

#endif