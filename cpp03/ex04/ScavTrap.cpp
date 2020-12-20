#include "ScavTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

ScavTrap::ScavTrap() {
    std::cout << "A scavenger robot appears, let's call it \"SC4V-TP\" !\n";
    setName("SC4V-TP");
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setMaxEnergyPoints(50);
    setLevel(1);
    setMeleeDamage(20);
    setRangedDamage(15);
    setArmorReduction(3);
}

ScavTrap::ScavTrap(std::string name) {
    setName(name);
    std::cout << "A brand new robot appears, let's call it " << getName() << " !\n";
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setMaxEnergyPoints(50);
    setLevel(1);
    setMeleeDamage(20);
    setRangedDamage(15);
    setArmorReduction(3);
}

ScavTrap::~ScavTrap() {
    std::cout << getName() << " ran out of power, it's dead...\n";
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
        setMaxHitPoints(that.getMaxHitPoints());
        setEnergyPoints(that.getEnergyPoints());
        setMaxEnergyPoints(that.getMaxEnergyPoints());
        setLevel(that.getLevel());
        setMeleeDamage(that.getMeleeAttackDamage());
        setRangedDamage(that.getRangedAttackDamage());
        setArmorReduction(that.getArmorReduction());
    }
    return (*this);
}

//////////////////////// SIMPLE ATTACKS /////////////////////////////////////

void ScavTrap::rangedAttack(std::string const &target) {
    std::cout << getName() << " throws a mini grenade on " ;
    std::cout << target << " from a cowardly distance, causing " ;
    std::cout << getRangedAttackDamage() << " points of damage !\n" ;
}
void ScavTrap::meleeAttack(std::string const &target) {
    std::cout << getName() << " courageously pricks " ;
    std::cout << target << " with its little sting, causing " ;
    std::cout << getMeleeAttackDamage() << " points of damage !\n" ;
}

////////////////////  CHALLENGE NEWCOMER ////////////////////////

void ScavTrap::challengeChess(std::string const &target) {
    std::cout << getName() << " challenges " << target;
    std::cout << " to a game of chess, but there's no board, and it doesn't know how to play chess anyway... " ;
    std::cout << target << " is so confused that it loses 50 health points !\n" ;
}
void ScavTrap::challengeRiddle(std::string const &target) {
    std::cout << getName() << " asks " << target;
    std::cout << " to answer a riddle, but it can't think of a single one... " ;
    std::cout << target << " is so confused that it loses 60 health points !\n" ;
}
void ScavTrap::challengeArmWrestling(std::string const &target) {
    std::cout << getName() << " challenges " << target;
    std::cout << ", to arm wrestle with it, but its arms are so weak that " ;
    std::cout << target << " bursts into laughter. It laughs so hard that it loses 70 health points !\n" ;
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