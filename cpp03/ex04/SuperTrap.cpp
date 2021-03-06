#include "SuperTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

SuperTrap::SuperTrap() {
    std::cout << "A robot appears, it's a bird, it's a plane, no it's \"SUP3R-TP\" !\n";
    setName("SUP3R-TP");
    setHitPoints(100);
    setMaxHitPoints(100);
    setRangedDamage(20);
    setArmorReduction(5);
}

SuperTrap::SuperTrap(std::string name) {
    setName(name);
    std::cout << "A robot appears, it's a bird, it's a plane, no it's a SuperTrap, let's call it ";
    std::cout << getName() << " !\n";
    setHitPoints(100);
    setMaxHitPoints(100);
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
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target) {
    NinjaTrap::meleeAttack(target);
}