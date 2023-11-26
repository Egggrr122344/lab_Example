#ifndef HEXAGON_HPP_INCLUDED
#define HEXAGON_HPP_INCLUDED

#include "Figure.h"
using namespace std;
template <typename T>
class Hexagon : public Figure<T> {
public:
  Hexagon() = delete;
  Hexagon(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6
  );

  virtual ~Hexagon() = default;

  bool operator==(const Hexagon<T>& rhs) const;

  Point<T> calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(    
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6
    ) noexcept;
};

#endif // HEXAGON_HPP_INCLUDED