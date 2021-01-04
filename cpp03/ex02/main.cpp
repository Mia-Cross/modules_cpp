#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    ClapTrap clapTrap;
    FragTrap fragTrap;
    ScavTrap scavTrap;
//    ScavTrap copy(scavTrap);

    srand(std::time(NULL));
    std::cout << std::endl;

    clapTrap.printInfo();
    fragTrap.printInfo();
    scavTrap.printInfo();
    std::cout << std::endl;

    scavTrap.rangedAttack(fragTrap.getName());
    fragTrap.rangedAttack(scavTrap.getName());
    std::cout << std::endl;

    scavTrap.meleeAttack(fragTrap.getName());
    fragTrap.meleeAttack(scavTrap.getName());
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

        fragTrap.beRepaired(rand() % 30);
        scavTrap.beRepaired(rand() % 20);
        std::cout << std::endl;
    }
}