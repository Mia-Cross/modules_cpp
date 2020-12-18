#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <ctime>
#include <cstdlib>

//"the other shoebox (oh shit no it's actually a robot (but it's really ugly, ewww))"

int main()
{
    FragTrap clapTrap;
    ScavTrap scavenger;

    srand(std::time(NULL));
    std::cout << std::endl;

    scavenger.rangedAttack(clapTrap.getName());
    clapTrap.takeDamage(scavenger.getRangedAttackDamage());
    std::cout << std::endl;

    scavenger.meleeAttack(clapTrap.getName());
    clapTrap.takeDamage(scavenger.getMeleeAttackDamage());
    std::cout << std::endl;

    scavenger.beRepaired(10);
    std::cout << scavenger.getName() << " is confused, it hurts itself in its confusion : ";
    scavenger.takeDamage(120);
    scavenger.beRepaired(120);
    clapTrap.beRepaired(120);
    std::cout << std::endl;

    unsigned int damage;
    unsigned int i = 0;

    while (clapTrap.getHitPoints() && (clapTrap.getEnergyPoints() || scavenger.getEnergyPoints()) )
    {
        std::cout << "-> Round " << ++i << " :\n\n";
        damage = clapTrap.vaulthunter_dot_exe(scavenger.getName());
        if (damage)
            scavenger.takeDamage(damage);
        std::cout << std::endl;

        if (scavenger.getHitPoints() == 0)
            break;
        damage = scavenger.challengeNewcomer(clapTrap.getName());
        if (damage)
            clapTrap.takeDamage(damage);
        std::cout << std::endl;
    }
}