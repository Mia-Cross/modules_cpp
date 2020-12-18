#include "ClapTrap.hpp"
#include <cstdlib>

//////////////////////// CANON /////////////////////////////////////

ClapTrap::ClapTrap() {
    std::cout << "A shoebox appears ! Oh wait no it's actually a robot, ";
    std::cout << "but its really ugly, ewww... Anyway... ";
    setName("CL4P-TP");
    setHitPoints(0);
    setMaxHitPoints(0);
    setEnergyPoints(0);
    setMaxEnergyPoints(0);
    setLevel(1);
    setMeleeDamage(0);
    setRangedDamage(0);
    setArmorReduction(0);
}

ClapTrap::ClapTrap(std::string name) : name(name) {
    std::cout << "A shoebox appears ! Oh wait no it's actually a robot, ";
    std::cout << "but its really ugly, ewww... Anyway... ";
    setHitPoints(0);
    setMaxHitPoints(0);
    setEnergyPoints(0);
    setMaxEnergyPoints(0);
    setLevel(1);
    setMeleeDamage(0);
    setRangedDamage(0);
    setArmorReduction(0);
}

ClapTrap::~ClapTrap(){
    std::cout << getName() << " exploded in hundreds of pieces, it's over...\n";
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << src.name << " creates a double of itself like some sort of ninja !\t";
    *this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &that) {
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

void ClapTrap::rangedAttack(std::string const &target) {
    // std::cout << getName() << " throws an old rusty grenade on " ;
    // std::cout << target << " from a cowardly distance, causing " ;
    // std::cout << getRangedAttackDamage() << " points of damage !\n" ;
}
void ClapTrap::meleeAttack(std::string const &target) {
    // std::cout << getName() << " courageously pinches " ;
    // std::cout << target << " with its little claws, causing " ;
    // std::cout << getMeleeAttackDamage() << " points of damage !\n" ;
}

////////////////////  HIT POINTS MANAGEMENT ////////////////////////

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << getName() << " was hit, it loses " ;
    std::cout << amount << " health points ! Actually no, I forgot it was wearing armor, ";
    if (amount - getArmorReduction() > getHitPoints())
    {
        std::cout << "and it didn't have enough health points anyway, ";
        amount = hitPoints + getArmorReduction();
    }
    std::cout << "so only " << amount - getArmorReduction() << " health points were lost..." ;
    setHitPoints(getHitPoints() - (amount - getArmorReduction()));
    std::cout << "(health is now " << getHitPoints() << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount + getHitPoints() >= getMaxHitPoints())
        amount = getMaxHitPoints() - getHitPoints();
    std::cout << getName() << " plugs himself in a power outlet to recover " ;
    std::cout << amount << " health points, it seems way better but is still complaining about stuff..." ;
    setHitPoints(getHitPoints() + amount);
    std::cout << "(health is now " << getHitPoints() << ")\n";
}

////////////////////  GETTERS  ////////////////////////

std::string ClapTrap::getName() const {
    return (this->name);
}
unsigned int ClapTrap::getHitPoints() const {
    return (this->hitPoints);
}
unsigned int ClapTrap::getMaxHitPoints() const {
    return (this->maxHitPoints);
}
unsigned int ClapTrap::getEnergyPoints() const {
    return (this->energyPoints);
}
unsigned int ClapTrap::getMaxEnergyPoints() const {
    return (this->maxEnergyPoints);
}
unsigned int ClapTrap::getLevel() const {
    return (this->level);
}
unsigned int ClapTrap::getMeleeAttackDamage() const {
    return (this->meleeAttackDamage);
}
unsigned int ClapTrap::getRangedAttackDamage() const {
    return (this->rangedAttackDamage);
}
unsigned int ClapTrap::getArmorReduction() const {
    return (this->armorDamageReduction);
}

////////////////////  SETTERS  ////////////////////////

void ClapTrap::setName(const std::string name) {
    this->name = name;
}
void ClapTrap::setHitPoints(const unsigned int hitPoints) {
    this->hitPoints = hitPoints;
}
void ClapTrap::setMaxHitPoints(const unsigned int maxHitPoints) {
    this->maxHitPoints = maxHitPoints;
}
void ClapTrap::setEnergyPoints(const unsigned int energyPoints) {
    this->energyPoints = energyPoints;
}
void ClapTrap::setMaxEnergyPoints(const unsigned int maxEnergyPoints) {
    this->maxEnergyPoints = maxEnergyPoints;
}
void ClapTrap::setLevel(const unsigned int level) {
    this->level = level;
}
void ClapTrap::setMeleeDamage(const unsigned int meleeAttackDamage) {
    this->meleeAttackDamage = meleeAttackDamage;
}
void ClapTrap::setRangedDamage(const unsigned int rangedAttackDamage) {
    this->rangedAttackDamage = rangedAttackDamage;
}
void ClapTrap::setArmorReduction(const unsigned int armorDamageReduction) {
    this->armorDamageReduction = armorDamageReduction;
}