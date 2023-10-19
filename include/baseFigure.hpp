// base Figure
#include <iostream>
#include "vector.hpp"
struct Point {
    // структура точки с полями x и y

    double x;
    double y;
    Point (int x, int y): x(x), y(y) {}
};

class BaseFigure {
    public:
        baseFigure() = default;

        virtual Point CalculateCenter() const;
        virtual double CalculateArea() const;

        ~baseFigure() = default;


};
