#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

NinjaTrap::NinjaTrap() {
    std::cout << "A ninja robot appears, let's call it \"N1NJ4-TP\" !\n";
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
    std::cout << "A ninja robot appears, let's call it " << getName() << " !\n";
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
    std::cout << getName() << " disappeared using an ancestral technique...\n";
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

void NinjaTrap::ninjaShoebox(ClapTrap &target)
{
    if (getEnergyPoints() < 25)
    {
        std::cout << getName() << " refuses to attack because it's tired, lazy robot !\n";
        return ;
    }
    setEnergyPoints(getEnergyPoints() - 25);
    std::cout << getName() << " jumps really high while spinning and lands on " ;
    std::cout << target.getName() << "'s face, causing 40 points of damage !\n" ;
    target.takeDamage(40);
}

void NinjaTrap::ninjaShoebox(FragTrap &target)
{
    if (getEnergyPoints() < 25)
    {
        std::cout << getName() << " refuses to attack because it's tired, lazy robot !\n";
        return ;
    }
    setEnergyPoints(getEnergyPoints() - 25);
    std::cout << getName() << " jumps really high while spinning and lands on " ;
    std::cout << target.getName() << "'s face, causing 40 points of damage !\n" ;
    target.takeDamage(40);
}

void NinjaTrap::ninjaShoebox(ScavTrap &target)
{
    if (getEnergyPoints() < 25)
    {
        std::cout << getName() << " refuses to attack because it's tired, lazy robot !\n";
        return ;
    }
    setEnergyPoints(getEnergyPoints() - 25);
    std::cout << getName() << " jumps really high while spinning and lands on " ;
    std::cout << target.getName() << "'s face, causing 40 points of damage !\n" ;
    target.takeDamage(40);
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
    if (getEnergyPoints() < 25)
    {
        std::cout << getName() << " refuses to attack because it's tired, lazy robot !\n";
        return ;
    }
    setEnergyPoints(getEnergyPoints() - 25);
    std::cout << "Although they are brothers and have the same training, ";
    std::cout << getName() << " jumps really high while spinning and lands on " ;
    std::cout << target.getName() << "'s face, causing 40 points of damage !\n" ;
    target.takeDamage(40);
}