#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;

    Squad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    std::cout << std::endl;

    ISpaceMarine* tm1 = new TacticalMarine;
    ISpaceMarine* at1 = new AssaultTerminator;
    ISpaceMarine *tm2 = tm1->clone();
    ISpaceMarine *at2 = at1->clone();
    TacticalMarine *tm3 = new TacticalMarine;
    AssaultTerminator *at3 = new AssaultTerminator;
    std::cout << std::endl;

    Squad *tmsquad = new Squad;
    tmsquad->push(tm1);
    tmsquad->push(tm2);
    tmsquad->push(tm3);
    tmsquad->push(tm3);

    *vlc = *tmsquad;
    vlc->getUnit(3);
    vlc->getUnit(2)->battleCry();
    vlc->getUnit(1)->battleCry();
    vlc->getUnit(0)->battleCry();
    delete tmsquad;
    delete vlc;
    std::cout << std::endl;

    Squad *atsquad = new Squad;
    atsquad->push(at1);
    atsquad->push(at2);
    atsquad->push(at3);

    Squad squ(*atsquad);
    squ.getUnit(3);
    squ.getUnit(2)->battleCry();
    squ.getUnit(1)->battleCry();
    squ.getUnit(0)->battleCry();
    delete atsquad;
    return 0;
}