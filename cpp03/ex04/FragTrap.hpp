#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

    public:

        FragTrap();                        //constructeur par defaut
        FragTrap(std::string name);
        ~FragTrap();                       //destructeur par defaut
        FragTrap(FragTrap const &src);        //constructeur par copie
        FragTrap &operator=(FragTrap const &that); //surcharge d'operateur d'assignation

        virtual void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);

        unsigned int vaulthunter_dot_exe(std::string const &target);
        void laserAttack(std::string const &target);
        void weakAttack(std::string const &target);
        void electricAttack(std::string const &target);
};

#endif