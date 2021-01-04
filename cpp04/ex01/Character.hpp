#ifndef CHARACTER_H
# define CHARACTER_H

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
    private:

        std::string name;
        int ap;
        AWeapon *weapon;
    //    static int recovery;
        Character();

    public:

        Character(std::string const & name);
        Character(Character const &src);
        Character &operator=(Character const &that);
        ~Character();

        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);

        std::string getName() const;
        int getAP() const;
        AWeapon &getWeaponRef() const;
        AWeapon *getWeaponPtr() const;
        void setName(std::string name);
        void setAP(int ap);
};

std::ostream &operator<<(std::ostream &out, Character const &in);

#endif