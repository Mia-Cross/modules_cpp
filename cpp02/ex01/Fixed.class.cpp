#include "Fixed.class.hpp"
#include <tgmath.h>

Fixed::Fixed() {
   // std::cout << "Default constructor called\n";
    this->fixedPoint = 0;
}

Fixed::Fixed(int const i) {
 //   std::cout << "Constructor by int called\n";
    this->fixedPoint = i << this->nbBits; // = i * 256;
    std::cout << "Constructor by int stored " << this->fixedPoint << std::endl;
}
Fixed::Fixed(float const f) {
   // std::cout << "Constructor by float called\n";
    this->fixedPoint = roundf(f * (1 << this->nbBits)); // = roundf(f * 256);
    std::cout << "Constructor by float stored " << this->fixedPoint << std::endl;
}

Fixed::~Fixed() {
    //std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const &src) {
    //std::cout << "Copy constructor called\n";
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &that) {
  //  std::cout << "Assignation operator called\n";
    if (this != &that)
        this->fixedPoint = that.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
   // std::cout << "getRawBits member function called\n";
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw) {
    //std::cout << "Setter called\n";
    this->fixedPoint = raw;
}

float Fixed::toFloat() const {
    //std::cout << "Function toFloat called\n";
    //float factor = ;
    //return ((float)this->fixedPoint / 1 << this->nbBits);
    
    const int *src = &this->fixedPoint;
    char *srcByte = (char *)src;
    float result = 0;
    float *dest = &result;
    char *destByte = (char *)dest;
    int i = 0;
    while (i < 4)
    {
        destByte[i] = srcByte[i];
        i++;
    }
    return (result);
    //float x = static_cast<float>(this->fixedPoint);
    //float x = this->fixedPoint;
    //const int &y = this->fixedPoint;
    //const int &iRef = this->fixedPoint;
   // int &iRef = const_cast<int &>(icRef);
    //float &fRef = static_cast<float>(this->fixedPoint);
    //float &x = dynamic_cast<float &>(y));
    //float x = (float)this->fixedPoint;
    //std::cout << x << " = toFloat called\n";
    //return fRef;
}

int Fixed::toInt() const {
    //std::cout << "Function toInt called\n";
    return ( (int)this->fixedPoint >> this->nbBits); //= fixed / 256;
}

std::ostream &operator<<(std::ostream &out, Fixed const &in) {
    out << in.toFloat() << " " << in.toInt();
    //out << in.toFloat();
    //int raw = in.getRawBits();
    //int *iptr = &raw;
    //float *x = static_cast<float *>(iptr);
    //out << (float)x;
    return (out);
}