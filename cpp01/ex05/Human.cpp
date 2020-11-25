#include "Human.hpp"
#include <iostream>

Human::Human() {
    this->brain = new Brain;
    std::cout << "Human born with 2 neurons\n";
}

Human::~Human() {
    delete this->brain;
    std::cout << "Human died\n";
}

Brain *Human::identify() {
    return(this->brain);
}

Brain &Human::getBrain() {
    Brain &ref = *this->brain;
    return (ref);
} 