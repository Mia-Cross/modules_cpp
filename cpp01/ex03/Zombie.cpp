#include "Zombie.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

std::string names[10] = {"Jim", "Bob", "Nora", "Katy", "Jack", "Taylor", "Jason", "Robert", "Sandy", "Victor"};
std::string types[5] = {"charming", "cute", "nasty", "polite", "jealous"};

int shuffle_random()
{
    int x = rand();
    std::time_t t = std::time(NULL);
    int y = (int)t;
    if (x < y)
        return (y - x);
    else
        return (x - y);
}

Zombie::Zombie() {
    int x = shuffle_random() % 10;
    int y = shuffle_random() % 5;
    this->_name = names[x];
    this->_type = types[y];
    std::cout << this->_name << ", a " << this->_type << " zombie is born.\n";
}

Zombie::~Zombie() {
    std::cout << this->_name << ", the " << this->_type << " zombie just died.\n";
}

void Zombie::advert() {
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiinnnsssss...\n";
}