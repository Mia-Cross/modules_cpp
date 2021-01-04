#ifndef SUPER_MUTANT_H
# define SUPER_MUTANT_H

# include "Enemy.hpp"

class SuperMutant : public virtual Enemy
{
    public:

        SuperMutant();
        SuperMutant(SuperMutant const &src);
        SuperMutant &operator=(SuperMutant const &that);
        ~SuperMutant();

        virtual void takeDamage(int damage);
};

#endif