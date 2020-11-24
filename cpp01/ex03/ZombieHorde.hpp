#ifndef ZOMBIE_HORDE_CLASS_H
# define ZOMBIE_HORDE_CLASS_H

# include "Zombie.hpp"

class ZombieHorde {
    public:
        ZombieHorde(int n);
        ~ZombieHorde();
        void announce();

    private:
        int _size;
        Zombie *_horde;
};

#endif