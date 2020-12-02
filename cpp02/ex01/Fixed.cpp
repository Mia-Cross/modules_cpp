#include "Fixed.hpp"
#include <iostream>
#include <tgmath.h>

Fixed::Fixed()
{
	this->fixedPointValue = 0;
	return ;
}

Fixed::Fixed(Fixed const &ref)
{
	*this = ref;
	return ;
}

Fixed::Fixed(int const n)
{
	this->fixedPointValue = n << this->n_bits;
	return ;
}

Fixed::Fixed(float const f)
{
	this->fixedPointValue = roundf(f * (1 << this->n_bits));
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed				&Fixed::operator=(Fixed const &ref)
{
	this->fixedPointValue = ref.getRawBits();
	return *this;
}

int					Fixed::getRawBits(void) const
{
	return this->fixedPointValue;
}

void				Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
	return ;
}

int					Fixed::toInt(void) const
{
	return this->fixedPointValue >> this->n_bits;
};

float				Fixed::toFloat(void) const
{
	return (double)this->fixedPointValue / (double)(1 << this->n_bits);
};

std::ostream		&operator<<(std::ostream &stream, Fixed const &ref)
{
	stream << ref.toFloat();
	return stream;
}