#include "Brain.hpp"
#include "Human.hpp"
#include <iostream>

int main()
{
    Human bob;
//    Human *ptr = &bob;
 //   Human &ref = bob;

    //std::cout << &bob (addresse de Human)<< std::endl;
    //std::cout << ptr (contenu de Human*)<< std::endl;
    //std::cout << &ref (addresse de la reference Human&)<< std::endl;
    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
}