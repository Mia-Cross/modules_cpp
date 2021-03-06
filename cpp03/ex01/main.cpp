#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    FragTrap fragTrap;
    ScavTrap scavTrap;

    srand(std::time(NULL));
    std::cout << std::endl;

    scavTrap.printInfo();
    std::cout << std::endl;

    scavTrap.rangedAttack(fragTrap.getName());
    fragTrap.takeDamage(scavTrap.getRangedAttackDamage());
    std::cout << std::endl;

    scavTrap.meleeAttack(fragTrap.getName());
    fragTrap.takeDamage(scavTrap.getMeleeAttackDamage());
    std::cout << std::endl;

    std::cout << scavTrap.getName() << " is confused, it hurts itself in its confusion : ";
    scavTrap.takeDamage(50);
    scavTrap.beRepaired(10);
    std::cout << scavTrap.getName() << " is confused, it hurts itself in its confusion : ";
    scavTrap.takeDamage(120);
    scavTrap.beRepaired(120);
    fragTrap.beRepaired(120);
    std::cout << std::endl;

    unsigned int damage;
    unsigned int i = 0;

    while (fragTrap.getHitPoints() && (fragTrap.getEnergyPoints() || scavTrap.getEnergyPoints()) )
    {
        std::cout << "-> Round " << ++i << " :\n\n";
        damage = fragTrap.vaulthunter_dot_exe(scavTrap.getName());
        if (damage)
            scavTrap.takeDamage(damage);
        std::cout << std::endl;

        if (scavTrap.getHitPoints() == 0)
            break;
        damage = scavTrap.challengeNewcomer(fragTrap.getName());
        if (damage)
            fragTrap.takeDamage(damage);
        std::cout << std::endl;
    }
}