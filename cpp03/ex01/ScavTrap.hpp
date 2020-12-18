#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include <iostream>

class ScavTrap {

    public :

        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(ScavTrap const &src);
        ScavTrap &operator=(ScavTrap const &that);

        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        unsigned int challengeNewcomer(std::string const &target);
        void challengeChess(std::string const &target);
        void challengeRiddle(std::string const &target);
        void challengeArmWrestling(std::string const &target);

        std::string getName() const;
        unsigned int getMeleeAttackDamage() const;
        unsigned int getRangedAttackDamage() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getLevel() const;

        void setName(const std::string name);
        void setHitPoints(const unsigned int hitPoints);
        void setEnergyPoints(const unsigned int energyPoints);
        void setLevel(const unsigned int level);

    private :

        std::string name;
        unsigned int hitPoints;
        static const unsigned int maxHitPoints = 100;
        unsigned int energyPoints;
        static const unsigned int maxEnergyPoints = 50;
        unsigned int level;
        static const unsigned int meleeAttackDamage = 20;
        static const unsigned int rangedAttackDamage = 15;
        static const unsigned int armorDamageReduction = 3;
};

#endif