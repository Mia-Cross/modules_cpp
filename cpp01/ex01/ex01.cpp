#include <iostream>

void memoryLeak()
{
    std::string*    panthere = new std::string("String panthere");
    
    std::cout << *panthere << std::endl;
}

void memoryLeakFixed()
{
    std::string*    panthere = new std::string("String panthere");
    
    std::cout << *panthere << std::endl;
    delete panthere;
}

int main(void)
{
    //memoryLeak();
    memoryLeakFixed();
    return 0;
}
