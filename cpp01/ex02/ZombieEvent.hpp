#ifndef ZOMBIE_EVENT_CLASS_H
# define ZOMBIE_EVENT_CLASS_H

# include "Zombie.hpp"

class ZombieEvent {

    public:
        ZombieEvent(std::string setType);
      //  ~ZombieEvent();
        Zombie *newZombie(std::string name);
        void randomChump();

    private:
        std::string _setZombieType;
};

#endif