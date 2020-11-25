#include "ZombieHorde.hpp"
#include <iostream>
#include <ctime>

ZombieHorde::ZombieHorde(int n) : _size(n) {
    std::cout << "A horde of " << n << " zombies assembles\n\n";
    this->_horde = new Zombie[this->_size];
}

ZombieHorde::~ZombieHorde() {
    delete [] this->_horde;
    std::cout << "Horde was destroyed\n\n";
}

void ZombieHorde::announce() 
{
    int i;

    for (i = 0; i < this->_size; i++)
        this->_horde[i].advert();
}