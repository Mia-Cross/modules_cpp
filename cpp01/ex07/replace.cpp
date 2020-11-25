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

std::string read_to_str(char *name)
{
    std::ifstream input;
    std::string buf("");
    char buffer[1];

    input.open(name);
    if (input.fail() == true)
    {
        std::cout << "Could not open file\n";
        exit(1);
    }
    while (input.read(buffer, 1))
        buf += *buffer;
    return (buf);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong input, must be \"./replace [filename] [to_be_replaced] [replacement]\"\n";
        return 0;
    }
    std::string buf = read_to_str(av[1]);
    std::string s1 = array_to_str(av[2]);
    std::string s2 = array_to_str(av[3]);
    std::string name = av[1];
    std::ofstream output(name.append(".out"));
    int index;

    while ((index = buf.find(s1)) && index >= 0 && index < buf.size())
    {
        output << buf.substr(0, index) << s2;
        buf = buf.substr(index + s1.size());
        index = buf.find(s1);
    }
    output << buf;
}


//  index = buf.find(s1);
//     if (index > buf.size())
//     {
//         output << buf;
//         return 0;
//     }
//     while (index >= 0 && index < buf.size())
//     {
//         output << buf.substr(0, index) << s2;
//         buf = buf.substr(index + s1.size());
//         index = buf.find(s1);
//     }
//     output << buf;
