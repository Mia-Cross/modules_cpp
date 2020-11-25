#include "Pony.hpp"
#include <iostream>

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

int main(void)
{
    std::cout << "Let's put a Pony on the Stack :" << std::endl << std::endl;
    ponyOnTheStack("white", "golden");
    std::cout << std::endl;

    std::cout << "Let's put a Pony on the Heap :" << std::endl << std::endl;
    ponyOnTheHeap("black", "silver");
    std::cout << std::endl;

    std::cout << "Let's put an Other Pony on the Stack, a grey one now :" << std::endl << std::endl;
    ponyOnTheStack("grey", "red");
}