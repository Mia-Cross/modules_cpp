#include <iostream>
#include <stdlib.h>

int main(int ac, char **av)
{
    switch (ac)
    {
        case 2:
            break;
        case 1:
            std::cerr << "Please give me a value to convert\n";
            return (1);
        default:
            std::cerr << "I can only convert 1 value at a time\n";
            return (1);
    }
    const char *str = av[1];
    int i = atoi(str);
}