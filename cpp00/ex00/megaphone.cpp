#include <iostream>
#include <string>

int main (int ac, char **av)
{
   std::string input;
   int i;

    if (ac < 2)
    {
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