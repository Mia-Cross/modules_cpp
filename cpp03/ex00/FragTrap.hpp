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

        unsigned int vaulthunter_dot_exe(std::string const &target);
        void laserAttack(std::string const &target);
        void weakAttack(std::string const &target);
        void electricAttack(std::string const &target);

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

        void printInfo() const;

    private:

        std::string name;
        unsigned int hitPoints;
        static const unsigned int maxHitPoints = 100;
        unsigned int energyPoints;
        static const unsigned int maxEnergyPoints = 100;
        unsigned int level;
        static const unsigned int meleeAttackDamage = 30;
        static const unsigned int rangedAttackDamage = 20;
        static const unsigned int armorDamageReduction = 5;
};

#endif