#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {
    std::cout << this->_name << ", a " << this->_type << " zombie is born.\n";
}

Zombie::~Zombie() {
    std::cout << this->_name << ", the " << this->_type << " zombie just died.\n\n";
}

void Zombie::advert() {
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiinnnsssss...\n";
}