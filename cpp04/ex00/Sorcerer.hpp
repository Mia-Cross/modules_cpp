#ifndef SORCERER_CLASS_H
# define SORCERER_CLASS_H

# include <iostream>

class Sorcerer {

    public :
        Sorcerer() = 0;
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        Sorcerer(Sorcerer const &src);
        Sorcerer &operator=(Sorcerer const &that);

        void polymorph();

    private :
        std::string name;
        std::string title;
};

std::ostream &operator<<(std::ostream &out, Sorcerer const &in);

#endif