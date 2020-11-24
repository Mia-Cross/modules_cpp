#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
    ZombieHorde *ptr = new ZombieHorde(7);
    ptr->announce();
    delete ptr;

    ZombieHorde var(3);
    var.announce();
}