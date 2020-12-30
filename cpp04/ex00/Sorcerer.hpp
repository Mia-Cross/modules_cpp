#ifndef SORCERER_CLASS_H
# define SORCERER_CLASS_H

# include <iostream>
# include "Victim.hpp"

class Sorcerer {

    public :
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        Sorcerer(Sorcerer const &src);
        Sorcerer &operator=(Sorcerer const &that);

        std::string introduceThemselves() const;
        void polymorph(Victim const &victim);

    private :
        Sorcerer();
        std::string name;
        std::string title;
};

std::ostream &operator<<(std::ostream &out, Sorcerer const &in);

#endif