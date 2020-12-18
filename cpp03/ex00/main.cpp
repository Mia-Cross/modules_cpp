#include "FragTrap.hpp"
#include <ctime>
#include <cstdlib>

//"the other shoebox (oh shit no it's actually a robot (but it's really ugly, ewww))"

int main()
{
    FragTrap clapTrap;
    FragTrap unfunnyRobot("UNfUNny-R0b0t");
    FragTrap copy(unfunnyRobot);

    srand(std::time(NULL));
    std::cout << std::endl;

    clapTrap.rangedAttack(unfunnyRobot.getName());
    unfunnyRobot.takeDamage(clapTrap.getRangedAttackDamage());
    std::cout << std::endl;

    unfunnyRobot.meleeAttack(clapTrap.getName());
    clapTrap.takeDamage(unfunnyRobot.getMeleeAttackDamage());
    std::cout << std::endl;

    clapTrap.beRepaired(10);
    std::cout << clapTrap.getName() << " is confused, it hurts itself in its confusion : ";
    clapTrap.takeDamage(120);
    clapTrap.beRepaired(120);
    std::cout << std::endl;

    unsigned int damage;
    unsigned int i = 0;

    while (clapTrap.getHitPoints() && (clapTrap.getEnergyPoints() || copy.getEnergyPoints()) )
    {
        std::cout << "-> Round " << ++i << " :\n\n";
        damage = clapTrap.vaulthunter_dot_exe(copy.getName());
        if (damage)
            copy.takeDamage(damage);
        std::cout << std::endl;

        if (copy.getHitPoints() == 0)
            break;
        damage = copy.vaulthunter_dot_exe(clapTrap.getName());
        if (damage)
            clapTrap.takeDamage(damage);
        std::cout << std::endl;
    }
}