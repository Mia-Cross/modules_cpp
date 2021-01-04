#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
    std::cout << "Gaaah. Me want smash heads!\n";
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(getHP(), getType()) {
    *this = src;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &that) {
    if (this != &that)
    {
        setType(that.getType());
        setHP(that.getHP());
    }
    return (*this);
}

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh...\n";
}

void SuperMutant::takeDamage(int damage) {
    Enemy::takeDamage(damage - 3);
}