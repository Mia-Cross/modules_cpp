#include "annuaire.hpp"

int main (int ac, char **av)
{
    std::string input;
    int i;

    std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
    getline (std::cin, input);
    if (input.compare("EXIT") == 0)
        return 0;
    else if (input.compare("ADD") == 0)
    {
        //CREATE CLASS ELEMENT (MALLOC)
        std::cout << "OK, PLEASE ENTER -FIRST NAME- :" << std::endl;
        getline (std::cin, input);
        
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (i = 1; i < ac; i++)
    {
        input = av[i];
        for (char c : input)
            putchar(toupper(c));
    }
    std::cout << std::endl;
    return 0;
}