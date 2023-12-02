#include <iostream>
#include <memory>
#include "Vector.h"
#include "Octagon.h"
#include "Hexagon.h"
#include <Triangle.h>
#include "functions.h"
#include "Point.h"
#include "/com.docker.devenvironments.code/src/lab0/functions.cpp"
#include "/com.docker.devenvironments.code/src/lab0/Point.cpp"
#include "/com.docker.devenvironments.code/src/lab0/Vector.cpp"
#include "/com.docker.devenvironments.code/src/lab0/Triangle.cpp"
#include "/com.docker.devenvironments.code/src/lab0/Hexagon.cpp"
using namespace std;
using triangle = Triangle<double>;
using hexagon = Hexagon<double>;

using point = Point<double>;

int main() {
  shared_ptr<triangle> t1 = make_shared<triangle>(point(1, 1), point(6, 1 + sqrt(3) * 5), point(11, 1));
  shared_ptr<triangle> t0 = make_shared<triangle>(point(0, 0), point(5, sqrt(3) * 5), point(10, 0));
  shared_ptr<hexagon> s0 = make_shared<hexagon>(point(10,10), point(9,10), point(8.5, 10 - std::sqrt(3)/2), point(10.5, 10 - std::sqrt(3)/2), point(9, 10 - std::sqrt(3)), point(10, 10 - std::sqrt(3)));
  
  Vector<shared_ptr<Figure<double>>> v = {t1, t0, s0};
  print_all_areas(v);
  print_all_centres(v);
  double all_area = calculate_all_area(v);
  cout << "Sum of areas: " << all_area << endl;
}