#ifndef FIXED
# define FIXED

#include <iostream>

class		Fixed
{
	public :
		Fixed();
		Fixed(int const n);
		Fixed(float const n);
		Fixed(Fixed const &ref);
		~Fixed();
		Fixed				&operator=(Fixed const &ref);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
	private :
		int					fixedPointValue;
		static const int	n_bits = 8;
};

std::ostream		&operator<<(std::ostream &stream, Fixed const &ref);

#endif