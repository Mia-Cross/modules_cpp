#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string h_color, std::string t_color) :
_hair_color(h_color), _tail_color(t_color)
{
    std::cout << "A " << _hair_color << " pony is born, with a "
    << _tail_color << " tail !" << std::endl;
}

Pony::~Pony(void) {
    std::cout << "The " << _hair_color << " pony died ! :(" << std::endl;
}

void Pony::takeStep(int nb) const {
    std::cout << "The " << this->_hair_color << " pony takes "
    << nb << " steps..." << std::endl;
}

void Pony::runThisWay(std::string dir) const {
    std::cout << "The " << this->_hair_color << " pony started running "
    << dir << std::endl;
}

void Pony::magicTail(std::string color) {
    std::cout << "Using its magic, the " << this->_hair_color
    << " pony turns its " << _tail_color << " tail " << color << std::endl;
    this->_tail_color = color;
}