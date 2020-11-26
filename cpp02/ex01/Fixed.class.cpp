#include "Fixed.class.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    this->rawBits = 0;
}

Fixed::Fixed(int const i) {
    this->rawBits = i;
}
Fixed::Fixed(float const f) {
    this->rawBits = (int)f;
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
        this->rawBits = that.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return (this->rawBits);
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}