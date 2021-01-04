#include "NinjaTrap.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    FragTrap fragTrap;
    ScavTrap scavTrap;
    NinjaTrap ninjaTrap;
    NinjaTrap ninjaDouble("N1NJ4-D0U8L3");

    srand(std::time(NULL));
    std::cout << std::endl;

    ninjaTrap.printInfo();
    std::cout << std::endl;

    ninjaTrap.rangedAttack(fragTrap.getName());
    fragTrap.takeDamage(ninjaTrap.getRangedAttackDamage());
    std::cout << std::endl;

    ninjaTrap.meleeAttack(scavTrap.getName());
    fragTrap.takeDamage(ninjaTrap.getMeleeAttackDamage());
    std::cout << std::endl;

    ninjaTrap.ninjaShoebox(fragTrap);
    std::cout << std::endl;
    ninjaTrap.ninjaShoebox(scavTrap);
    std::cout << std::endl;
    ninjaTrap.ninjaShoebox(ninjaDouble);
    std::cout << std::endl;
}