#ifndef RAD_SCORPION_H
# define RAD_SCORPION_H

# include "Enemy.hpp"

class RadScorpion : public virtual Enemy
{
    public:

        RadScorpion();
        RadScorpion(RadScorpion const &src);
        RadScorpion &operator=(RadScorpion const &that);
        virtual ~RadScorpion();
};

#endif