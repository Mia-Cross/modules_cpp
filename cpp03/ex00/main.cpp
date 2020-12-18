#include "FragTrap.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    FragTrap fragTrap;
    FragTrap unfunnyRobot("UNfUNny-R0b0t");
    FragTrap copy(unfunnyRobot);

    srand(std::time(NULL));
    std::cout << std::endl;

    fragTrap.rangedAttack(unfunnyRobot.getName());
    unfunnyRobot.takeDamage(fragTrap.getRangedAttackDamage());
    std::cout << std::endl;

    unfunnyRobot.meleeAttack(fragTrap.getName());
    fragTrap.takeDamage(unfunnyRobot.getMeleeAttackDamage());
    std::cout << std::endl;

    fragTrap.beRepaired(10);
    std::cout << fragTrap.getName() << " is confused, it hurts itself in its confusion : ";
    fragTrap.takeDamage(120);
    fragTrap.beRepaired(120);
    std::cout << std::endl;

    unsigned int damage;
    unsigned int i = 0;

    while (fragTrap.getHitPoints() && (fragTrap.getEnergyPoints() || copy.getEnergyPoints()) )
    {
        std::cout << "-> Round " << ++i << " :\n\n";
        damage = fragTrap.vaulthunter_dot_exe(copy.getName());
        if (damage)
            copy.takeDamage(damage);
        std::cout << std::endl;

        if (copy.getHitPoints() == 0)
            break;
        damage = copy.vaulthunter_dot_exe(fragTrap.getName());
        if (damage)
            fragTrap.takeDamage(damage);
        std::cout << std::endl;
    }
}