#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name) {
    std::cout << "HumanB is born : " << this->name << " (" << this << ")\n";
}

HumanB::~HumanB() {
    std::cout << "HumanB died : " << this->name << " (" << this << ")\n";
}

void HumanB::attack() {
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}