#ifndef OCTAGON
#define OCTAGON

#include "Figure.h"

#include <iostream>

using namespace std;

class Octagon: public Figure {
public:    
    Octagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6, const Point& p7, const Point& p8);
    operator double() const override;
    Point calculateCentre() const override;

    friend ostream& operator<<(ostream&, const Octagon& oct);
    friend istream& operator>>(istream&, Octagon& oct);
    friend bool operator==(const Octagon& oct1, const Octagon& oct2);


private:
    bool validate(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6, const Point& p7, const Point& p8) noexcept;


};

#endif