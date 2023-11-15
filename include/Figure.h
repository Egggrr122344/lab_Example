#ifndef FIGURE
#define FIGURE

#include <iostream>
#include "Vector.h"
#include "Point.h"
#include "/com.docker.devenvironments.code/src/lab0/Vector.cpp"
class Figure {
    public:
        virtual Point calculateCentre() const = 0; // calculate centre
        virtual operator double() const = 0; // calculate area

    protected:
        Vector<Point> points;
};


#endif