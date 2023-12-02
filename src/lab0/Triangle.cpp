#include "Triangle.h"

template <typename T>
bool Triangle<T>::validate(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) noexcept {
  double sum_x = p1.get_x() + p2.get_x() + p3.get_x();
  double sum_y = p1.get_y() + p2.get_y() + p3.get_y();
  Point<T> centre(sum_x / 3.0, sum_y / 3.0);

  // double inaccuracy = 1e-10;

  // double len1 = Point<T>::line_len(centre, p1);
  // double len2 = Point<T>::line_len(centre, p2);
  // double len3 = Point<T>::line_len(centre, p3);

  double AB = Point<T>::line_len(p1,p2);
  double BC = Point<T>::line_len(p2,p3);
  double AC = Point<T>::line_len(p1,p3);

  if ( (AB + BC > AC) && (BC + AC > AB) && (AB + AC > BC) ) {
    return true;
  }

  return false;
}

template <typename T>
Triangle<T>::Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {
  bool is_triangle = validate(p1, p2, p3);

  if (!is_triangle) {
    throw invalid_argument("Invalid Point<T>. Can not create triangle!");
  }

  this->coordinates = {p1, p2, p3};
}

template <typename U>
ostream& operator<<(ostream& os, Triangle<U>& rhs) {
  for (size_t i = 0; i < rhs.coordinates.get_size(); ++i) {
    os << rhs.coordinates[i];
  }
  return os;
}

template <typename U>
istream& operator>>(istream& is, Triangle<U>& rhs) {
  is >> rhs.coordinates[0] >> rhs.coordinates[1] >> rhs.coordinates[2];
  return is;
}

template <typename T>
Point<T> Triangle<T>::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
    centre_x += this->coordinates[i].get_x();
    centre_y += this->coordinates[i].get_y();
  }

  return Point<T>(centre_x / 3.0, centre_y / 3.0);
}

template <typename T>
bool Triangle<T>::operator==(const Triangle<T>& rhs) const {
    if (this->coordinates.get_size() != rhs.coordinates.get_size()) {
        return false;
    }

    for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
        if (this->coordinates[i] != rhs.coordinates[i]) {
            return false;
        }
    }

    return true;
}



template <typename T>
Triangle<T>::operator double() const {
  double p1x = this -> coordinates[0].get_x();
  double p2x = this -> coordinates[1].get_x();
  double p3x = this -> coordinates[2].get_x();
  
  double p1y = this -> coordinates[0].get_y();
  double p2y = this -> coordinates[1].get_y();
  double p3y = this -> coordinates[2].get_y();

  double p1p2 = std::sqrt(std::pow(p1x - p2x, 2) + std::pow(p1y - p2y, 2) );
  double p2p3 = std::sqrt(std::pow(p2x - p3x, 2) + std::pow(p2y - p3y, 2) );
  double p1p3 = std::sqrt(std::pow(p1x - p3x, 2) + std::pow(p1y - p3y, 2) );

  double p = (p1p2 + p2p3 + p1p3) / 2;

  double area = std::sqrt(p * (p - p1p2) * (p - p2p3) * (p - p1p3));

  return area;
}