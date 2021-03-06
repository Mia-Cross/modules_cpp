#include "Peon.hpp"

Peon::Peon() : Victim("peon") {}

Peon::Peon(std::string name) : Victim(name) {
    std::cout << "Zog zog.\n";
}
Peon::Peon(Peon const &ref) : Victim(ref.getName()) {
    *this = ref;
}
Peon &Peon::operator=(Peon const &ref) {
    setName(ref.getName());
    return (*this);
}
Peon::~Peon() {
    std::cout << "Bleuark...\n";
}

void Peon::getPolymorphed() const {
    std::cout << getName() << " has been turned into a pink pony!\n";
}

std::ostream &operator<<(std::ostream &out, Peon const &in) {
    out << in.introduceThemselves();
    return (out);
}