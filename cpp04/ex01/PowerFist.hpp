#ifndef POWER_FIST_H
# define POWER_FIST_H

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    public:

        PowerFist();
        PowerFist(PowerFist const &src);
        PowerFist &operator=(PowerFist const &that);
        ~PowerFist();

        virtual void attack() const;
};

#endif