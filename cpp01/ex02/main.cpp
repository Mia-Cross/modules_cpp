#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
    ZombieEvent charming("charming"), cute("cute");

    charming.randomChump();

    Zombie *baby = cute.newZombie("Jane");
    baby->advert();
    delete baby;

    Zombie *baby2 = charming.newZombie ("Marvin");
    baby2->advert();
    delete baby2;

    cute.randomChump();
    
    charming.randomChump();
}