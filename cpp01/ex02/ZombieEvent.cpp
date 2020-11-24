#include "ZombieEvent.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent(std::string setType) : _setZombieType(setType) {

}

Zombie *ZombieEvent::newZombie(std::string name) {
    Zombie *newZombie = new Zombie(name, this->_setZombieType);
    return (newZombie);
}

std::string names[10] = {"Jim", "Bob", "Nora", "Katy", "Jack", "Taylor", "Jason", "Robert", "Sandy", "Victor"};

int shuffle_random()
{
    int x = std::rand();
    std::time_t t = std::time(NULL);
    int y = (int)t;
    if (x < y)
        return (y - x);
    else
        return (x - y);
}

void ZombieEvent::randomChump()
{
    int x = shuffle_random() % 10;
    Zombie chump(names[x], this->_setZombieType);
    chump.advert();
}

//void ZombieEvent::setZombieType(std::string type)
//{}