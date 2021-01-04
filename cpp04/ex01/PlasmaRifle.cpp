#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) :
    AWeapon(src.getName(), src.getAPCost(), src.getDamage()) {
    *this = src;
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &that) {
    if (this != &that)
    {
        setName(that.getName());
        setAPCost(that.getAPCost());
        setDamage(that.getDamage());
    }
    return (*this);
}

void PlasmaRifle::attack() const {
    std::cout << "* piouuu piouuu piouuu *\n";
}