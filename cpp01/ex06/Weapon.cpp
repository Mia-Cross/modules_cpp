#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : type(type) {
    std::cout << "Weapon created : " << this->type << " (" << this << ")\n";
}

Weapon::~Weapon() {
    std::cout << "Weapon destroyed : " << this->type << " (" << this << ")\n";
}

void Weapon::setType(std::string type) {
    this->type = type;
}

const std::string &Weapon::getType() {
    return(this->type);
}