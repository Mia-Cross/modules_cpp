#include "FragTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

FragTrap::FragTrap() {
    std::cout << "A brand new robot appears, let's call it \"CL4P-TP\" !\n";
    this->name = "CL4P-TP";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->level = 1;
}

FragTrap::FragTrap(std::string name) : name(name) {
    std::cout << "A brand new robot appears, let's call it " << this->name << " !\n";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->level = 1;
}

FragTrap::~FragTrap(){
    std::cout << this->name << " exploded in a million pieces, it's over...\n";
}

FragTrap::FragTrap(FragTrap const &src) {
    std::cout << src.name << " creates a double of itself like some sort of ninja !\t";
    *this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &that) {
    std::cout << "(Assignation operator called)\n";
    if (this != &that)
    {
        this->name = that.name;
        this->hitPoints = that.hitPoints;
        this->energyPoints = that.energyPoints;
        this->level = that.level;
    }
    return *this;
}

//////////////////////// SIMPLE ATTACKS /////////////////////////////////////

void FragTrap::rangedAttack(std::string const &target) {
    std::cout << this->name << " throws an old rusty grenade on " ;
    std::cout << target << " from a cowardly distance, causing " ;
    std::cout << this->rangedAttackDamage << " points of damage !\n" ;
}
void FragTrap::meleeAttack(std::string const &target) {
    std::cout << this->name << " courageously pinches " ;
    std::cout << target << " with its little claws, causing " ;
    std::cout << this->meleeAttackDamage << " points of damage !\n" ;
}

////////////////////  HIT POINTS MANAGEMENT ////////////////////////

void FragTrap::takeDamage(unsigned int amount)
{
    std::cout << this->name << " was hit, it loses " ;
    std::cout << amount << " health points ! Actually no, I forgot it was wearing armor, ";
    if (amount - this->armorDamageReduction > hitPoints)
    {
        std::cout << "and it didn't have enough health points anyway, ";
        amount = hitPoints + this->armorDamageReduction;
    }
    std::cout << "so only " << amount - this->armorDamageReduction << " health points were lost..." ;
    this->hitPoints -= (amount - this->armorDamageReduction);
    std::cout << "(health is now " << this->hitPoints << ")\n";
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (amount + this->hitPoints >= maxHitPoints)
        amount = maxHitPoints - this->hitPoints;
    std::cout << this->name << " plugs himself in a power outlet to recover " ;
    std::cout << amount << " health points, it seems way better but is still complaining about stuff..." ;
    this->hitPoints += amount;
    std::cout << "(health is now " << this->hitPoints << ")\n";
}

////////////////////  VAULTHUNTER DOT EXE ////////////////////////

void FragTrap::laserAttack(std::string const &target) {
    std::cout << this->name << " shoots a powerful laser ray on " ;
    std::cout << target << ", causing 50 points of damage !\n" ;
}

void FragTrap::weakAttack(std::string const &target) {
    std::cout << this->name << " punches " ;
    std::cout << target << ", but it was a really weak punch, causing " ;
    std::cout << "only 10 points of damage !\n" ;
}

void FragTrap::electricAttack(std::string const &target) {
    std::cout << this->name << " launches an EMP on " ;
    std::cout << target << ", causing a short circuit and " ;
    std::cout << "40 points of damage !\n" ;
}

unsigned int FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    if (this->energyPoints < 25)
    {
        std::cout << this->name << " refuses to attack because it's tired, lazy robot !\n";
        return (0);
    }
    this->energyPoints -= 25;
    int x = rand() % 5;
    switch (x)
    {
        case 0:
            this->rangedAttack(target);
            return (this->rangedAttackDamage);
        case 1:
            this->meleeAttack(target);
            return (this->meleeAttackDamage);
        case 2:
            this->laserAttack(target);
            return (50);
        case 3:
            this->weakAttack(target);
            return (10);
        case 4:
            this->electricAttack(target);
            return (40);
    }
    return (0);
}

////////////////////  GETTERS  ////////////////////////

std::string FragTrap::getName() const {
    return (this->name);
}
unsigned int FragTrap::getHitPoints() const {
    return (this->hitPoints);
}
unsigned int FragTrap::getEnergyPoints() const {
    return (this->energyPoints);
}
unsigned int FragTrap::getMeleeAttackDamage() const {
    return (this->meleeAttackDamage);
}
unsigned int FragTrap::getRangedAttackDamage() const {
    return (this->rangedAttackDamage);
}
unsigned int FragTrap::getLevel() const {
    return (this->level);
}

////////////////////  SETTERS  ////////////////////////

void FragTrap::setName(const std::string name) {
    this->name = name;
}
void FragTrap::setHitPoints(const unsigned int hitPoints) {
    this->hitPoints = hitPoints;
}
void FragTrap::setEnergyPoints(const unsigned int energyPoints) {
    this->energyPoints = energyPoints;
}
void FragTrap::setLevel(const unsigned int level) {
    this->level = level;
}