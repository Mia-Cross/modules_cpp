#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "A zombie named " << this->_name << " is born.\n";
}

Zombie::~Zombie() {
    std::cout << this->_name << ", the " << this->_type << " zombie just died.\n\n";
}

void Zombie::advert() {
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiinnnsssss...\n";
}

void Zombie::setZombieType(std::string type) {
    this->_type = type;
}