#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(Ice const &ref) : AMateria("ice") {
    *this = ref;
}
Ice &Ice::operator=(Ice const &ref) {
    if (this != &ref)
    {
        setXP(ref.getXP());
        setType("ice");
    }
    return (*this);
}

void Ice::use(ICharacter &target) {
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\t\txp = ";
    std::cout << this->getXP() - 10 << " -> " << this->getXP() << std::endl;
}

AMateria* Ice::clone() const {
    return (new Ice("ice"));
}