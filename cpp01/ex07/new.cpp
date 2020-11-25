#include <fstream>
#include <iostream>
#include <string>

std::string array_to_str(char *arr)
{
    std::string str;
    int i;

    for (i = 0; arr[i] != '\0'; i++)
        str += arr[i];
    return (str);
}

void read_to_str(char *name, std::string *buf)
{
    std::ifstream input(name);
    char buffer[30];
    int i;

    while (input.read(buffer, 30))
    {
        for (i = 0; buffer[i] != '\0' && i < 30; i++)
            *buf += buffer[i];
    }
    for (i = 0; buffer[i] != '\0' && i < 30; i++)
        *buf += buffer[i];
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong input\n./replace filename to_be_replaced replacement\n";
        return 0;
    }
    std::string s1 = array_to_str(av[2]);
    std::string s2 = array_to_str(av[3]);
    std::string name = av[1];
    std::ofstream output(name.append(".out"));
    std::string buf;
    int index;
    int begin = 0;

    read_to_str(av[1], &buf);
    while ((index = buf.find(s1, begin)) && index >= 0)
    {
        std::cout << index << std::endl;
        std::cout << buf.size() << std::endl;
        if (index < buf.size())
        {
            output << buf.substr(0, index) << s2;
            buf = buf.substr(index + s1.size(), buf.size());
            begin = index;
        }
    }
    output << buf;
}
