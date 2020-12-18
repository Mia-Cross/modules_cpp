#include "NinjaTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

NinjaTrap::NinjaTrap() {
    std::cout << "A brand new robot appears, let's call it \"N1NJ4-TP\" !\n";
    setName("N1NJ4-TP");
    setHitPoints(60);
    setMaxHitPoints(60);
    setEnergyPoints(120);
    setMaxEnergyPoints(120);
    setLevel(1);
    setMeleeDamage(60);
    setRangedDamage(5);
    setArmorReduction(0);
}

NinjaTrap::NinjaTrap(std::string name) {
    setName(name);
    std::cout << "A brand new robot appears, let's call it " << getName() << " !\n";
    setHitPoints(60);
    setMaxHitPoints(60);
    setEnergyPoints(120);
    setMaxEnergyPoints(120);
    setLevel(1);
    setMeleeDamage(60);
    setRangedDamage(5);
    setArmorReduction(0);
}

NinjaTrap::~NinjaTrap(){
    std::cout << getName() << " exploded in a million pieces, it's over...\n";
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) {
    std::cout << src.getName() << " creates a double of itself like some sort of ninja (which it is btw) !\t";
    *this = src;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &that) {
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

void NinjaTrap::rangedAttack(std::string const &target) {
    std::cout << getName() << " throws a shuriken on " ;
    std::cout << target << " from a cowardly distance, causing " ;
    std::cout << getRangedAttackDamage() << " points of damage !\n" ;
}
void NinjaTrap::meleeAttack(std::string const &target) {
    std::cout << getName() << " high-kicks " ;
    std::cout << target << " in the face, causing " ;
    std::cout << getMeleeAttackDamage() << " points of damage !\n" ;
}

////////////////////  NINJA SHOEBOX ////////////////////////


unsigned int NinjaTrap::ninjaShoebox(std::string const &target)
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
           // this->rangedAttack(target);
            return (getRangedAttackDamage());
        case 1:
           // this->meleeAttack(target);
            return (getMeleeAttackDamage());
        case 2:
           // this->laserAttack(target);
            return (50);
        case 3:
           // this->weakAttack(target);
            return (10);
        case 4:
          //  this->electricAttack(target);
            return (40);
    }
    return (0);
}