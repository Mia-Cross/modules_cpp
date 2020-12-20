#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <iostream>

class ClapTrap {

    public:

        ClapTrap();                        //constructeur par defaut
        ClapTrap(std::string name);
        ~ClapTrap();                       //destructeur par defaut
        ClapTrap(ClapTrap const &src);        //constructeur par copie
        ClapTrap &operator=(ClapTrap const &that); //surcharge d'operateur d'assignation

        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        unsigned int getHitPoints() const;
        unsigned int getMaxHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getMaxEnergyPoints() const;
        unsigned int getLevel() const;
        unsigned int getMeleeAttackDamage() const;
        unsigned int getRangedAttackDamage() const;
        unsigned int getArmorReduction() const;

        void setName(const std::string name);
        void setHitPoints(const unsigned int hitPoints);
        void setMaxHitPoints(const unsigned int maxHitPoints);
        void setEnergyPoints(const unsigned int energyPoints);
        void setMaxEnergyPoints(const unsigned int maxEnergyPoints);
        void setLevel(const unsigned int level);
        void setMeleeDamage(const unsigned int meleeAttackDamage);
        void setRangedDamage(const unsigned int rangedAttackDamage);
        void setArmorReduction(const unsigned int armorDamageReduction);

    private:

        std::string name;
        unsigned int hitPoints;
        unsigned int maxHitPoints;
        unsigned int energyPoints;
        unsigned int maxEnergyPoints;
        unsigned int level;
        unsigned int meleeAttackDamage;
        unsigned int rangedAttackDamage;
        unsigned int armorDamageReduction;
};

#endif