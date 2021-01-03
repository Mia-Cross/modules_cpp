#ifndef SUPERTRAP_CLASS_H
# define SUPERTRAP_CLASS_H

# include "NinjaTrap.hpp"

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap {

    public:

        SuperTrap();                        //constructeur par defaut
        SuperTrap(std::string name);
        ~SuperTrap();                       //destructeur par defaut
        SuperTrap(SuperTrap const &src);        //constructeur par copie
        SuperTrap &operator=(SuperTrap const &that); //surcharge d'operateur d'assignation

        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
};

#endif