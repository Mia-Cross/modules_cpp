#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>

class Zombie {
    public:
        Zombie();
        ~Zombie();
        void advert();
        void setZombieType(std::string type);

    private:
        std::string _name;
        std::string _type;
};

#endif