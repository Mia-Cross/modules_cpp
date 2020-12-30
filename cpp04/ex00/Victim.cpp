#include "Victim.hpp"

Victim::Victim() {}

Victim::Victim(std::string name) : name(name) {
    std::cout << "Some random victim called " << name  << " just appeared!\n";
}

Victim::~Victim() {
    std::cout << "Victim "<< name << " just died for no apparent reason!\n";
}

Victim::Victim(Victim const &src) {
    std::cout << src.name << " gets copied.\n";
    *this = src;
}

Victim &Victim::operator=(Victim const &that) {
    std::cout << "(Assignation operator called)\n";
    if (this != &that)
        this->name = that.name;
    return (*this);
}

void Victim::setName(std::string const name) {
    this->name = name;
}

std::string Victim::getName() const {
    return (this->name);
}

std::string Victim::introduceThemselves(void) const {
    std::string str = "I'm ";
    str += (name + ", and I like otters!\n");
    return (str);
}

void Victim::getPolymorphed() const {
    std::cout << name << " has been turned into a cute little sheep!\n";
}

std::ostream &operator<<(std::ostream &out, Victim const &in) {
    out << in.introduceThemselves();
    return (out);
}