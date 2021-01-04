#include "SuperTrap.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    FragTrap fragTrap;
    ScavTrap scavTrap;
    NinjaTrap ninjaTrap;
    SuperTrap superTrap;

    // FragTrap ft(fragTrap);
    // ScavTrap st(scavTrap);
    // NinjaTrap nt(ninjaTrap);
    // SuperTrap sut(superTrap);

    srand(std::time(NULL));
    std::cout << std::endl;

    superTrap.printInfo();
    std::cout << std::endl;

    superTrap.rangedAttack(scavTrap.getName());
    scavTrap.takeDamage(superTrap.getRangedAttackDamage());
    std::cout << std::endl;

    superTrap.meleeAttack(fragTrap.getName());
    fragTrap.takeDamage(superTrap.getMeleeAttackDamage());
    std::cout << std::endl;

    superTrap.vaulthunter_dot_exe(scavTrap.getName());
    scavTrap.takeDamage(superTrap.getMeleeAttackDamage());
    std::cout << std::endl;

    superTrap.ninjaShoebox(fragTrap);
    std::cout << std::endl;
}