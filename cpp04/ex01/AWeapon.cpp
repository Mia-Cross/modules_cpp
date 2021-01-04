#include "AWeapon.hpp"

AWeapon::AWeapon() {}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) :
    name(name), apcost(apcost), damage(damage) {
    std::cout << "Weapon \"" << name << "\" is ready.\n";
}

AWeapon::AWeapon(AWeapon const &src) {
    *this = src;
}

AWeapon &AWeapon::operator=(AWeapon const &that) {
    if (this != &that)
    {
        this->name = that.getName();
        this->apcost = that.getAPCost();
        this->damage = that.getDamage();
    }
    return (*this);
}

AWeapon::~AWeapon() {
    std::cout << "Weapon \"" << name << "\" is empty.\n";
}

std::string AWeapon::getName() const {
    return (this->name);
}
int AWeapon::getAPCost() const {
    return (this->apcost);
}
int AWeapon::getDamage() const {
    return (this->damage);
}
void AWeapon::setName(std::string name) {
    this->name = name;
}
void AWeapon::setAPCost(int apcost) {
    this->apcost = apcost;
}
void AWeapon::setDamage(int damage) {
    this->damage = damage;
}