#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : type(type), _xp(0) {}

AMateria::AMateria(AMateria const &ref) {
    *this = ref;
}
AMateria &AMateria::operator=(AMateria const &ref) {
    if (this != &ref)
        this->_xp = ref.getXP();
}
AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
    return (this->type);
}
unsigned int AMateria::getXP() const {
    return (this->_xp);
}
void AMateria::setType(std::string const &type) {
    this->type = type;
}
void AMateria::setXP(unsigned int xp) {
    this->_xp = xp;
}

void AMateria::use(ICharacter &target) {
    this->_xp += 10;
    (void)target;
}