#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() {
    std::cout << "* teleports from space *\n";
}

AssaultTerminator::~AssaultTerminator() {
    std::cout << "I'll be back...\n";
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) {
    std::cout << "* teleports from space *\n";
    *this = src;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &that) {
    (void)that;
    return (*this);
}

AssaultTerminator* AssaultTerminator::clone() const {
    AssaultTerminator *copy = new AssaultTerminator(*this);
    return (copy);
}
void AssaultTerminator::battleCry() const {
    std::cout << "This code is unclean. PURIFY IT!\n";
}
void AssaultTerminator::rangedAttack() const {
    std::cout << "* does nothing *\n";
}
void AssaultTerminator::meleeAttack() const {
    std::cout << "* attacks with a chainfists *\n";
}