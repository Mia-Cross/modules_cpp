#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;

    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;

    ISpaceMarine* tm1 = new TacticalMarine;
    ISpaceMarine* at1 = new AssaultTerminator;
    ISpaceMarine *tm2 = tm1->clone();
    ISpaceMarine *at2 = at1->clone();
    TacticalMarine *tm3 = new TacticalMarine;
    AssaultTerminator *at3 = new AssaultTerminator;

    Squad *tmsquad = new Squad;
    tmsquad->push(tm1);
    tmsquad->push(tm2);
    tmsquad->push(tm3);

    Squad *atsquad = new Squad;
    atsquad->push(at1);
    atsquad->push(at2);
    atsquad->push(at3);

    Squad *squ1(atsquad);
    squ1->getUnit(3);
    squ1->getUnit(2);
    squ1->getUnit(0)->battleCry();
    delete squ1;
    //delete atsquad;

    vlc = tmsquad;
    vlc->getUnit(3);
    vlc->getUnit(2);
    vlc->getUnit(0)->battleCry();
    delete vlc;
    //delete tmsquad;

    return 0;
}