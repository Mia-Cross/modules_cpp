#include "annuaire.hpp"

int main (int ac, char **av)
{
    std::string input;
    int i;

    std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
    while (getline (std::cin, input) && input.compare("EXIT") != 0)
    {
        if (input.compare("ADD") == 0)
        {
            //CREATE CLASS ELEMENT (MALLOC)
            std::cout << "OK, PLEASE ENTER -FIRST NAME- :" << std::endl;
            getline (std::cin, input);

            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
            return 0;
        }
        else if (input.compare("SEARCH") == 0)
        {
            //methode
        }
        else
        {
            std::cout << "UNKNOWN INSTRUCTION" << std::endl;
            std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
        }
    }
    std::cout << "OK, BYE !" << std::endl;
    return 0;
}