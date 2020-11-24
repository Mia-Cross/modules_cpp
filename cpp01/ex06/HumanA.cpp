#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
    std::cout << "HumanA is born : " << this->name << " (" << this << ")\n";
}

HumanA::~HumanA() {
    std::cout << "HumanA died : " << this->name << " (" << this << ")\n";
}

void HumanA::attack() {
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}