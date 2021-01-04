#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::~PowerFist() {}

PowerFist::PowerFist(PowerFist const &src) :
    AWeapon(src.getName(), src.getAPCost(), src.getDamage()) {
    *this = src;
}

PowerFist &PowerFist::operator=(PowerFist const &that) {
    if (this != &that)
    {
        setName(that.getName());
        setAPCost(that.getAPCost());
        setDamage(that.getDamage());
    }
    return (*this);
}

void PowerFist::attack() const {
    std::cout << "* pschhh... SBAM! *\n";
}