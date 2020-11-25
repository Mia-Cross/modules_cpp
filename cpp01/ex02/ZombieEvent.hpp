#ifndef ZOMBIE_EVENT_CLASS_H
# define ZOMBIE_EVENT_CLASS_H

# include "Zombie.hpp"

class ZombieEvent {

    public:
        ZombieEvent();
        ~ZombieEvent();
        Zombie *newZombie(std::string name);
        void randomChump();
};

#endif