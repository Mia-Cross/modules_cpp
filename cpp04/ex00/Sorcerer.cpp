#include "Sorcerer.hpp"

// Sorcerer::Sorcerer() {
//     this->name = "SORCERER NAME";
//     this->title = "SORCERER TITLE";
//     std::cout << name << ", " << title << ", is born!\n";
// }

Sorcerer::Sorcerer(std::string name, std::string title) name(name), title(title) {
    std::cout << name << ", " << title << ", is born!\n";
}

Sorcerer::~Sorcerer() {
    std::cout << name << ", " << title << ", is dead. Consequences will never be the same!\n";
}

Sorcerer::Sorcerer(Sorcerer const &src) {

}

Sorcerer &Sorcerer::operator=(Sorcerer const &that) {

}