#ifndef FIGURE
#define FIGURE

#include <iostream>
#include "Vector.h"
#include "Point.h"
class Figure {
    public:
        virtual Point center() const = 0;
        virtual operator double() const = 0;

    protected:
        Vector<Point> points;
};


#endif