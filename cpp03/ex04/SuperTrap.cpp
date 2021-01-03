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

//////////////////////// SIMPLE ATTACKS /////////////////////////////////////

void SuperTrap::rangedAttack(std::string const &target) {
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target) {
    NinjaTrap::meleeAttack(target);
}