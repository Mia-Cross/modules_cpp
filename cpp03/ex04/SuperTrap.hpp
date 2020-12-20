#ifndef SUPERTRAP_CLASS_H
# define SUPERTRAP_CLASS_H

//# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

    public:

        SuperTrap();                        //constructeur par defaut
        SuperTrap(std::string name);
        ~SuperTrap();                       //destructeur par defaut
        SuperTrap(SuperTrap const &src);        //constructeur par copie
        SuperTrap &operator=(SuperTrap const &that); //surcharge d'operateur d'assignation
};

#endif