#ifndef A_WEAPON_H
# define A_WEAPON_H

# include <iostream>

class AWeapon
{
    private:

        std::string name;
        int apcost;
        int damage;
        AWeapon();
    
    public:

        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(AWeapon const &src);
        AWeapon &operator=(AWeapon const &that);
        ~AWeapon();

        std::string getName() const;
        int getAPCost() const;
        int getDamage() const;

        void setName(std::string name);
        void setAPCost(int apcost);
        void setDamage(int damage);

        virtual void attack() const = 0;
};

#endif