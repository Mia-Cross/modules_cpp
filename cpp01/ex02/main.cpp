#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
    ZombieEvent event; //charming("charming"), cute("cute");

    event.randomChump();

    Zombie *baby = event.newZombie("Jane");
    baby->setZombieType("charming");
    baby->advert();
    delete baby;

    Zombie *baby2 = event.newZombie ("Marvin");
    baby2->setZombieType("cute");

    event.randomChump();

    baby2->advert();
    delete baby2;

    event.randomChump();
}