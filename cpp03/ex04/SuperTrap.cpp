#include "SuperTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

SuperTrap::SuperTrap() {
    std::cout << "A robot appears, it's a bird, it's a plane, no it's \"SUP3R-TP\" !\n";
    NinjaTrap::setName("SUP3R-TP");
    FragTrap::setHitPoints(FragTrap::getHitPoints());
    FragTrap::setMaxHitPoints(FragTrap::getMaxHitPoints());
    NinjaTrap::setEnergyPoints(NinjaTrap::getEnergyPoints());
    NinjaTrap::setMaxEnergyPoints(NinjaTrap::getMaxEnergyPoints());
    NinjaTrap::setLevel(1);
    NinjaTrap::setMeleeDamage(NinjaTrap::getMeleeAttackDamage());
    FragTrap::setRangedDamage(FragTrap::getRangedAttackDamage());
    FragTrap::setArmorReduction(FragTrap::getArmorReduction());
}

SuperTrap::SuperTrap(std::string name) {
    setName(name);
    std::cout << "A robot appears, it's a bird, it's a plane, no it's a SuperTrap, let's call it ";
    std::cout << getName() << " !\n";
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(100);
    setMaxEnergyPoints(100);
    setLevel(1);
    setMeleeDamage(30);
    setRangedDamage(20);
    setArmorReduction(5);
}

SuperTrap::~SuperTrap(){
    std::cout << getName() << "'s work in done here, it flies away...\n";
}

SuperTrap::SuperTrap(SuperTrap const &src) {
    std::cout << src.getName() << " creates a double of itself like some sort of ninja !\t";
    *this = src;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &that) {
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

void SuperTrap::rangedAttack(std::string const &target) {
    std::cout << getName() << " throws an old rusty grenade on " ;
    std::cout << target << " from a cowardly distance, causing " ;
    std::cout << getRangedAttackDamage() << " points of damage !\n" ;
}
void SuperTrap::meleeAttack(std::string const &target) {
    std::cout << getName() << " courageously pinches " ;
    std::cout << target << " with its little claws, causing " ;
    std::cout << getMeleeAttackDamage() << " points of damage !\n" ;
}