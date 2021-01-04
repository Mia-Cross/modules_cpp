#ifndef PLASMA_RIFLE_H
# define PLASMA_RIFLE_H

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:

        PlasmaRifle();
        PlasmaRifle(PlasmaRifle const &src);
        PlasmaRifle &operator=(PlasmaRifle const &that);
        ~PlasmaRifle();

        virtual void attack() const;
};

#endif