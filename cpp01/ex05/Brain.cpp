#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    this->neurons = 2;
    std::cout << "Brain created with " << this->neurons << " neurons\n";
}

Brain::~Brain() {
    std::cout << "Brain " << this << " destroyed\n";
}

Brain *Brain::identify() {
    return (this);
}