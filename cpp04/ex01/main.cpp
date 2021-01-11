#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main()
{
    Character* me = new Character("me");

    std::cout << *me;

    Enemy* b = new RadScorpion();
    Enemy* c = new SuperMutant();
    Enemy* d = new Enemy(5, "BloodHound");

    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    std::cout << std::endl;

    me->attack(d);
    me->equip(pr);
    me->attack(d);
    std::cout << std::endl;

    me->attack(c);
    std::cout << *me;
    me->attack(c);
    me->recoverAP();
    me->equip(pf);
    me->attack(c);
    me->recoverAP();
    me->attack(c);
    std::cout << *me;
    me->attack(c);
    std::cout << std::endl;

    me->equip(pf);
    me->attack(b);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->recoverAP();
    me->recoverAP();
    std::cout << *me;
    std::cout << std::endl;

    c = new SuperMutant();
    me->equip(pf);
    me->attack(c);
    std::cout << *me;
    me->attack(c);
    std::cout << *me;
    me->attack(c);
    std::cout << *me;
    me->attack(c);
    me->recoverAP();
    me->equip(pr);
    me->attack(c);
    std::cout << *me;
    std::cout << std::endl;

    delete c;
    delete pr;
    delete pf;
    delete me;
    return 0;
}