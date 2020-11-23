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

void ponyOnTheStack(std::string h_color, std::string t_color)
{
    Pony stackPony(h_color, t_color);

    stackPony.takeStep(5);
    stackPony.magicTail("pink");
    stackPony.runThisWay("north");
}

void ponyOnTheHeap(std::string h_color, std::string t_color)
{
    Pony *heapPony;
    
    heapPony = new Pony(h_color, t_color);
    heapPony->takeStep(10);
    heapPony->magicTail("blue");

    delete heapPony;
}