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

void clean_buffer(char *buffer)
{
    int i;

    for (i = 0; i < 30; i++)
        buffer[i] = '\0';
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
        clean_buffer(buffer);
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

    read_to_str(av[1], &buf);
    index = buf.find(s1);
    while (index >= 0)
    {
        if (index < buf.size())
        {
            output << buf.substr(0, index) << s2;
            buf = buf.substr(index + s1.size());
        }
        index = buf.find(s1);
    }
    output << buf;
}
