#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
    std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(getHP(), getType()) {
    *this = src;
}

RadScorpion &RadScorpion::operator=(RadScorpion const &that) {
    if (this != &that)
    {
        setType(that.getType());
        setHP(that.getHP());
    }
    return (*this);
}

RadScorpion::~RadScorpion() {
    std::cout << "* SPROTCH *\n";
}