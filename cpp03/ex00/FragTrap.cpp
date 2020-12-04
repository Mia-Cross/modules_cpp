#include "FragTrap.hpp"

//////////////////////// CANON /////////////////////////////////////

FragTrap::FragTrap() {
    std::cout << "Default constructor called\n";
    this->name = "CL4P-TP";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->level = 1;
}
FragTrap::FragTrap(std::string name) : name(name) {
    std::cout << "Constructor by name called : Hello " << this->name << " !\n";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->level = 1;
}
FragTrap::~FragTrap() {
    std::cout << "Destructor called\n";
}
FragTrap::FragTrap(FragTrap const &src) {
    std::cout << "Copy constructor called\n";
    *this = src;
}
FragTrap &FragTrap::operator=(FragTrap const &that) {
    std::cout << "Assignation operator called\n";
    if (this != &that)
    {
        this->name = that.name;
        this->hitPoints = that.hitPoints;
        this->energyPoints = that.energyPoints;
        this->level = that.level;
    }
    return *this;
}

//////////////////////// ATTACKS /////////////////////////////////////

void FragTrap::rangedAttack(std::string const &target) {
    std::cout << this->name << " throws an old rusty grenade on " ;
    std::cout << target << " from a cowardly distance, causing " ;
    std::cout << this->rangedAttackDamage << " points of damage !\n" ;
}
void FragTrap::meleeAttack(std::string const &target) {
    std::cout << this->name << " pinches " ;
    std::cout << target << " with its tiny hook hands, causing " ;
    std::cout << this->meleeAttackDamage << " points of damage !\n" ;
}
void FragTrap::takeDamage(unsigned int amount) {
    if (amount - this->armorDamageReduction > hitPoints)
        amount = hitPoints + this->armorDamageReduction;
    std::cout << this->name << " was hit, it loses " ;
    //faut mieux gerer l'affichage de la valeur si max est depassé
    std::cout << amount << " health points !\n" ;
    std::cout << "Actually no, I forgot it was wearing armor, so only ";
    std::cout << amount - this->armorDamageReduction << " health points were lost..." ;
    this->hitPoints -= (amount - this->armorDamageReduction);
    std::cout << "(health is now " << this->hitPoints << ")\n";
}
void FragTrap::beRepaired(unsigned int amount) {
    if (amount + this->hitPoints >= maxEnergyPoints)
        amount = maxEnergyPoints - this->hitPoints;
    std::cout << this->name << " plugs himself in a power outlet to recover " ;
    std::cout << amount << " health points, it seems way better but is still complaining about stuff..." ;
    this->hitPoints += amount;
    std::cout << "(health is now " << this->hitPoints << ")\n";
}

//////////////////////// GETTERS /////////////////////////////////////
// std::string FragTrap::getName() {
//     return (this->name);
// }
