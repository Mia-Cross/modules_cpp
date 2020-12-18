#include "ScavTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

ScavTrap::ScavTrap() {
    std::cout << "A scavenger robot appears, let's call it \"SC4V-TP\" !\n";
    setName("SC4V-TP");
    setHitPoints(100);
    setEnergyPoints(50);
    setLevel(1);
}

ScavTrap::ScavTrap(std::string name) : name(name) {
    //setName(name);
    std::cout << "A brand new robot appears, let's call it " << getName() << " !\n";
    setHitPoints(100);
    setEnergyPoints(50);
    setLevel(1);
}

ScavTrap::~ScavTrap() {
    std::cout << getName() << " exploded in a thousand pieces, it's over...\n";
}

ScavTrap::ScavTrap(ScavTrap const &src) {
    std::cout << src.getName() << " creates a double of itself like some sort of ninja !\t";
    *this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &that) {
    std::cout << "(Assignation operator called)\n";
    if (this != &that)
    {
        setName(that.getName());
        setHitPoints(that.getHitPoints());
        setEnergyPoints(that.getEnergyPoints());
        setLevel(that.getLevel());
    }
    return (*this);
}

//////////////////////// SIMPLE ATTACKS /////////////////////////////////////

void ScavTrap::rangedAttack(std::string const &target) {
    std::cout << getName() << " throws a mini grenade on " ;
    std::cout << target << " from a cowardly distance, causing " ;
    std::cout << this->rangedAttackDamage << " points of damage !\n" ;
}
void ScavTrap::meleeAttack(std::string const &target) {
    std::cout << getName() << " courageously pricks " ;
    std::cout << target << " with its little sting, causing " ;
    std::cout << this->meleeAttackDamage << " points of damage !\n" ;
}

////////////////////  HIT POINTS MANAGEMENT ////////////////////////

void ScavTrap::takeDamage(unsigned int amount)
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

void ScavTrap::beRepaired(unsigned int amount)
{
    if (amount + this->hitPoints >= maxHitPoints)
        amount = maxHitPoints - this->hitPoints;
    std::cout << this->name << " plugs himself in a power outlet to recover " ;
    std::cout << amount << " health points, it seems way better but is still complaining about stuff..." ;
    this->hitPoints += amount;
    std::cout << "(health is now " << this->hitPoints << ")\n";
}

////////////////////  CHALLENGE NEWCOMER ////////////////////////

void ScavTrap::challengeChess(std::string const &target) {
    std::cout << this->name << " challenges " << target;
    std::cout << " to a game of chess, but there's no board, and it doesn't know how to play chess anyway... " ;
    std::cout << target << " is so confused that it loses 50 health points !\n" ;
}
void ScavTrap::challengeRiddle(std::string const &target) {
    std::cout << this->name << " asks " << target;
    std::cout << " to answer a riddle, but it can't think of a single one... " ;
    std::cout << target << " is so confused that it loses 60 health points !\n" ;
}
void ScavTrap::challengeArmWrestling(std::string const &target) {
    std::cout << this->name << " challenges " << target;
    std::cout << ", to arm wrestle with it, but its arms are so weak that " ;
    std::cout << target << " bursts laughter. It laughs so hard that it loses 70 health points !\n" ;
}

unsigned int ScavTrap::challengeNewcomer(std::string const &target)
{
    unsigned int ep = getEnergyPoints();
    if (ep < 25)
    {
        std::cout << getName() << " refuses to attack because it's tired, lazy robot !\n";
        return (0);
    }
    setEnergyPoints(ep - 25);
    int x = rand() % 3;
    switch (x)
    {
        case 0:
            this->challengeChess(target);
            return (50);
        case 1:
            this->challengeRiddle(target);
            return (60);
        case 2:
             this->challengeArmWrestling(target);
             return (70);
    }
    return (0);
}

////////////////////  GETTERS  ////////////////////////

std::string ScavTrap::getName() const {
    return (this->name);
}
unsigned int ScavTrap::getHitPoints() const {
    return (this->hitPoints);
}
unsigned int ScavTrap::getEnergyPoints() const {
    return (this->energyPoints);
}
unsigned int ScavTrap::getMeleeAttackDamage() const {
    return (this->meleeAttackDamage);
}
unsigned int ScavTrap::getRangedAttackDamage() const {
    return (this->rangedAttackDamage);
}
unsigned int ScavTrap::getLevel() const {
    return (this->level);
}

////////////////////  SETTERS  ////////////////////////

void ScavTrap::setName(const std::string name) {
    this->name = name;
}
void ScavTrap::setHitPoints(const unsigned int hitPoints) {
    this->hitPoints = hitPoints;
}
void ScavTrap::setEnergyPoints(const unsigned int energyPoints) {
    this->energyPoints = energyPoints;
}
void ScavTrap::setLevel(const unsigned int level) {
    this->level = level;
}