#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(Cure const &ref) : AMateria("cure") {
    *this = ref;
}
Cure &Cure::operator=(Cure const &ref) {
    if (this != &ref)
    {
        setXP(ref.getXP());
        setType("cure");
    }
    return (*this);
}

void Cure::use(ICharacter &target) {
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "'s wounds *\t\t\txp = ";
    std::cout << this->getXP() - 10 << " -> " << this->getXP() << std::endl;
}

AMateria* Cure::clone() const {
    return (new Cure("cure"));
}