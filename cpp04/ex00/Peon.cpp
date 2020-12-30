#include "Peon.hpp"

// Peon::Peon() {}

Peon::Peon(std::string name) : Victim(name) {
    std::cout << "Some random victim called " << name << " just appeared!\n";
    setName(name);
    std::cout << "Zog zog.\n";
}

Peon::~Peon() {
    std::cout << "Victim "<< getName() << " just died for no apparent reason!\n";
    std::cout << "Bleuark...\n";
}

// Peon::Peon(Peon const &src) {
//     std::cout << src.name << " gets copied.\n";
//     *this = src;
// }

// Peon &Peon::operator=(Peon const &that) {
//     std::cout << "(Assignation operator called)\n";
//     if (this != &that)
//         this->name = that.name;
//     return (*this);
// }

// std::string Peon::introduceThemselves(void) const {
//     std::string str = "I'm ";
//     str += (name + ", and I like otters!\n");
//     return (str);
// }

void Peon::getPolymorphed() const {
    std::cout << getName() << " has been turned into a pink pony!\n";
}

std::ostream &operator<<(std::ostream &out, Peon const &in) {
    out << in.introduceThemselves();
    return (out);
}