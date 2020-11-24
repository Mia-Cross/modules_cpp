#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

# include "Weapon.hpp"
# include <string>

class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &weapon);
    private:
        std::string name;
        Weapon *weapon;
};

#endif