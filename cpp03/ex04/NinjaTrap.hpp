#ifndef NINJATRAP_CLASS_H
# define NINJATRAP_CLASS_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

    public:

        NinjaTrap();                        //constructeur par defaut
        NinjaTrap(std::string name);
        ~NinjaTrap();                       //destructeur par defaut
        NinjaTrap(NinjaTrap const &src);        //constructeur par copie
        NinjaTrap &operator=(NinjaTrap const &that); //surcharge d'operateur d'assignation

        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);

        void ninjaShoebox(ClapTrap &target);
        void ninjaShoebox(FragTrap &target);
        void ninjaShoebox(ScavTrap &target);
        void ninjaShoebox(NinjaTrap &target);
};

#endif