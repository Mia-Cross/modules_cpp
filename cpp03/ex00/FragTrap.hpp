#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

# include <iostream>

class FragTrap {

    public:

        FragTrap();                        //constructeur par defaut
        FragTrap(std::string name);
        ~FragTrap();                       //destructeur par defaut
        FragTrap(FragTrap const &src);        //constructeur par copie
        FragTrap &operator=(FragTrap const &that); //surcharge d'operateur d'assignation

        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string name;
        int hitPoints = 100;
        int maxHitPoints = 100;
        int energyPoints = 100;
        int maxEnergyPoints = 100;
        int level = 1;
        int meleeAttackDamage = 30;
        int rangedAttackDamage = 20;
        int armorDamageReduction = 5;
};

std::ostream & operator<<(std::ostream &out, FragTrap const &in);

#endif