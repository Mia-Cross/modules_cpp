#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed {

    public:

        Fixed();                        //constructeur par defaut
        Fixed(int const i);
        Fixed(float const f);
        ~Fixed();                       //destructeur par defaut
        Fixed(Fixed const &src);        //constructeur par copie
        Fixed &operator=(Fixed const &that); //surcharge d'operateur d'assignation

        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;

    private:

        int fixedPoint;
        static const int nbBits = 8;
};

std::ostream & operator<<(std::ostream &out, Fixed const &in);

#endif