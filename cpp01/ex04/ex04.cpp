#include <iostream>
#include <stdio.h>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << *ptr << std::endl;
    std::cout << ref << std::endl;
    std::cout << "ADDRESS DE STR = "<< &str << std::endl;
    std::cout << "ADDRESS DE REF = "<< &ref << std::endl;
}