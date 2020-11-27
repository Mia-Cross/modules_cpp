#include "Fixed.class.hpp"
#include <cmath>

Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    this->fixedPoint = 0;
}

Fixed::Fixed(int const i) {
    this->fixedPoint = i;
}
Fixed::Fixed(float const f) {
    *this = f;
    //int &ref = this->fixedPoint;
    //const_cast < int & > (ref);
    //this->fixedPoint = ref;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called\n";
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &that) {
    std::cout << "Assignation operator called\n";
    if (this != &that)
        this->fixedPoint = that.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw) {
    this->fixedPoint = raw;
}

float Fixed::toFloat() const {
    //const float res = 0;
}

int Fixed::toInt() const {
    //const int res = 0;
}

std::ostream &operator<<(std::ostream &out, Fixed const &in) {

}