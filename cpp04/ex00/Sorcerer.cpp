#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title) {
    std::cout << name << ", " << title << ", is born!\n";
}

Sorcerer::~Sorcerer() {
    std::cout << name << ", " << title << ", is dead. Consequences will never be the same!\n";
}

Sorcerer::Sorcerer(Sorcerer const &src) {
    std::cout << src.name << " casts a spell to create a copy.\n";
    *this = src;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &that) {
    std::cout << "(Assignation operator called)\n";
    if (this != &that)
    {
        this->name = that.name;
        this->title = that.title;
    }
    return (*this);
}

std::string Sorcerer::introduceThemselves(void) const {
    std::string str = "I am ";
    str += (name + ", " + title + ", and I like ponies!\n");
    return (str);
}

void Sorcerer::polymorph(Victim const &victim) {
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, Sorcerer const &in) {
    out << in.introduceThemselves();
    return (out);
}