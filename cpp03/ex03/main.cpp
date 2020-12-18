#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    FragTrap fragTrap;
    ScavTrap scavTrap;
    NinjaTrap ninjaTrap;

    srand(std::time(NULL));
    std::cout << std::endl;

    ninjaTrap.rangedAttack(fragTrap.getName());
    fragTrap.takeDamage(ninjaTrap.getRangedAttackDamage());
    std::cout << std::endl;

    ninjaTrap.meleeAttack(fragTrap.getName());
    fragTrap.takeDamage(ninjaTrap.getMeleeAttackDamage());
    std::cout << std::endl;

    unsigned int damage;
    unsigned int i = 0;

    while (ninjaTrap.getHitPoints() && (ninjaTrap.getEnergyPoints() || scavTrap.getEnergyPoints()) )
    {
        std::cout << "-> Round " << ++i << " :\n\n";
        damage = ninjaTrap.ninjaShoebox(scavTrap.getName());
        if (damage)
            scavTrap.takeDamage(damage);
        std::cout << std::endl;

        if (scavTrap.getHitPoints() == 0)
            break;
        damage = scavTrap.challengeNewcomer(ninjaTrap.getName());
        if (damage)
            ninjaTrap.takeDamage(damage);
        std::cout << std::endl;

        ninjaTrap.beRepaired(rand() % 30);
        scavTrap.beRepaired(rand() % 20);
        std::cout << std::endl;
    }
}