#ifndef TRIANGLE
#define TRIANGLE
#include <iostream>
#include "Figure.h"

using namespace std;

class Triangle : public Figure {
    public:
        Triangle(const Point& p1, const Point& p2, const Point& p3);

        Point calculateCentre() const override;
        operator double() const override;

        friend ostream& operator<< (ostream& out, const Triangle& triangle);
        friend istream& operator>> (istream& is, Triangle& triangle);
        friend bool operator== (const Triangle& tr1, const Triangle& tr2);

    private:
        bool validate(const Point& p1, const Point& p2, const Point& p3) noexcept;


};


#endif