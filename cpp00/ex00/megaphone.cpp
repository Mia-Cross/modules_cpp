#include <iostream>
#include <cstdio>

int main (int ac, char **av)
{
   int i;
   int j;

    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (i = 1; i < ac; i++)
    {
        for (j = 0; av[i][j] != '\0'; j++)
            putchar(toupper(av[i][j]));
    }
    std::cout << std::endl;
    return 0;
}