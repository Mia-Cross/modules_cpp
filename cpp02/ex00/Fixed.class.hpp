#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed {
    public:
        Fixed();                        //constructeur par defaut
        ~Fixed();                       //destructeur par defaut
        Fixed(Fixed const &src);        //constructeur par copie
        Fixed &operator=(Fixed const &that); //surcharge d'operateur d'assignation
        int getRawBits() const;
        void setRawBits(int const raw);

    private:
        int fixedPoint;
        static const int width = 8;
};

#endif