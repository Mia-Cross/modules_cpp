#include "FragTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

FragTrap::FragTrap() {
    std::cout << "A fragtrap robot appears, let's call it \"FR4G-TP\" !\n";
    setName("FR4G-TP");
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(100);
    setMaxEnergyPoints(100);
    setLevel(1);
    setMeleeDamage(30);
    setRangedDamage(20);
    setArmorReduction(5);
}

FragTrap::FragTrap(std::string name) {
    setName(name);
    std::cout << "A fragtrap robot appears, let's call it " << getName() << " !\n";
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(100);
    setMaxEnergyPoints(100);
    setLevel(1);
    setMeleeDamage(30);
    setRangedDamage(20);
    setArmorReduction(5);
}

FragTrap::~FragTrap(){
    std::cout << getName() << " exploded in a million pieces, it's over...\n";
}

FragTrap::FragTrap(FragTrap const &src) {
    std::cout << src.getName() << " creates a double of itself like some sort of ninja !\t";
    *this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &that) {
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

void FragTrap::rangedAttack(std::string const &target) {
    std::cout << getName() << " throws an old rusty grenade on " ;
    std::cout << target << " from a cowardly distance, causing " ;
    std::cout << getRangedAttackDamage() << " points of damage !\n" ;
}
void FragTrap::meleeAttack(std::string const &target) {
    std::cout << getName() << " courageously pinches " ;
    std::cout << target << " with its little claws, causing " ;
    std::cout << getMeleeAttackDamage() << " points of damage !\n" ;
}

////////////////////  VAULTHUNTER DOT EXE ////////////////////////

void FragTrap::laserAttack(std::string const &target) {
    std::cout << getName() << " shoots a powerful laser ray on " ;
    std::cout << target << ", causing 50 points of damage !\n" ;
}

void FragTrap::weakAttack(std::string const &target) {
    std::cout << getName() << " punches " ;
    std::cout << target << ", but it was a really weak punch, causing " ;
    std::cout << "only 10 points of damage !\n" ;
}

void FragTrap::electricAttack(std::string const &target) {
    std::cout << getName() << " launches an EMP on " ;
    std::cout << target << ", causing a short circuit and " ;
    std::cout << "40 points of damage !\n" ;
}

unsigned int FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    if (getEnergyPoints() < 25)
    {
        std::cout << getName() << " refuses to attack because it's tired, lazy robot !\n";
        return (0);
    }
    setEnergyPoints(getEnergyPoints() - 25);
    int x = rand() % 5;
    switch (x)
    {
        case 0:
            this->rangedAttack(target);
            return (getRangedAttackDamage());
        case 1:
            this->meleeAttack(target);
            return (getMeleeAttackDamage());
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