#ifndef HUMAN_A_CLASS_H
# define HUMAN_A_CLASS_H

# include "Weapon.hpp"
# include <string>

class HumanA {
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
    private:
        std::string name;
        Weapon &weapon;
};

#endif