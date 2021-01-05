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
}

void Cure::use(ICharacter &target) {
    AMateria::use(target);
    std::cout << "* health " << target.getName() << "'s wounds *\n";
}

AMateria* Cure::clone() const {
    return (new Cure("cure"));
}