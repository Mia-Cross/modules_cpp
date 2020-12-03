#include "Fixed.class.hpp"
#include <cmath>

Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    this->fixedPoint = 0;
}

Fixed::Fixed(int const i) {
    std::cout << "Int constructor called\n";
    int factor = 1 << this->nbBits; //= 256;
    this->fixedPoint = i * factor;
}
Fixed::Fixed(float const f) {
    std::cout << "Float constructor called\n";
    float factor = 1 << this->nbBits; //= 256;
    this->fixedPoint = roundf(f * factor);
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
   // std::cout << "getRawBits member function called\n";
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw) {
    //std::cout << "getRawBits member function called\n";
    this->fixedPoint = raw;
}

float Fixed::toFloat() const {
    //std::cout << "toFloat member function called\n";
    float factor = 1 << this->nbBits;
    return ((float)this->fixedPoint / factor);
    
   
}

int Fixed::toInt() const {
    //std::cout << "toInt member function called\n";
    int factor = 1 << this->nbBits;
    return ((int)this->fixedPoint / factor);
}

std::ostream &operator<<(std::ostream &out, Fixed const &in) {
    //out << in.toFloat() << " " << in.toInt() << " " << in.getRawBits();
    out << in.toFloat();
    return (out);
}