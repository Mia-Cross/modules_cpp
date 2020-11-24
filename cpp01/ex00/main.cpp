#include "Pony.hpp"
#include <iostream>

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