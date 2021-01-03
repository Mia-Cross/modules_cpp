#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

    public :

        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(ScavTrap const &src);
        ScavTrap &operator=(ScavTrap const &that);

        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);

        unsigned int challengeNewcomer(std::string const &target);
        void challengeChess(std::string const &target);
        void challengeRiddle(std::string const &target);
        void challengeArmWrestling(std::string const &target);
};

#endif