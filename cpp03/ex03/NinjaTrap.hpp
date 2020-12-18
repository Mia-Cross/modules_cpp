#ifndef NINJARAP_CLASS_H
# define NINJATRAP_CLASS_H

# include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap {

    public:

        NinjaTrap();                        //constructeur par defaut
        NinjaTrap(std::string name);
        ~NinjaTrap();                       //destructeur par defaut
        NinjaTrap(NinjaTrap const &src);        //constructeur par copie
        NinjaTrap &operator=(NinjaTrap const &that); //surcharge d'operateur d'assignation

        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);

        unsigned int ninjaShoebox(std::string const &target);
};

#endif