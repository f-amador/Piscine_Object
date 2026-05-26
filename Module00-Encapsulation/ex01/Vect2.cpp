#include "Vect2.hpp"

Vect2::Vect2(float x, float y) {
    _coordinates.first = x;
    _coordinates.second = y;
}

Vect2::~Vect2() {
    std::cout << "Vector Destructor called" << std::endl;
}

const std::pair<float, float> &Vect2::getCoordinate() const{
    return _coordinates;
}

std::ostream &operator<<( std::ostream &out, const Vect2 &obj) {
        out << "X: " << obj.getCoordinate().first << "\nY: " << obj.getCoordinate().second << std::endl;
        return out;
    }