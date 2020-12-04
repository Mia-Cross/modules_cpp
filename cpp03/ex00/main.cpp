#include "FragTrap.hpp"

int main()
{
    FragTrap clapTrap;
    FragTrap unfunnyRobot("UNfUNny-R0b0t");
    FragTrap copy(clapTrap);

    clapTrap.meleeAttack("Handsome Jack");
    unfunnyRobot.rangedAttack("a dustbin");
    copy.takeDamage(13);
    copy.beRepaired(70);

    copy = unfunnyRobot;

    clapTrap.rangedAttack("the other shoebox (oh shit no it's actually a robot (but it's really ugly, ewww))");
    copy.takeDamage(120);
    copy.beRepaired(20);
}