#include <fstream>
#include <iostream>

std::string file_to_str(std::ifstream input)
{
    std::string file;
    std::string element;

    while (input >> element)
        file.append(element);
    return (file);
}

void search_for_needle(std::ifstream input, std::ofstream output, std::string s1, int index)
{
    
}

int main(int ac, char **av)
{
    std::cout << "bufstr";
    if (ac != 4)
    {
        std::cout << "Wrong input\n./replace filename to_be_replaced replacement\n";
        return 0;
    }

    std::ifstream input(av[1]);
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string name = av[1];
    std::ofstream output(name.append(".out"));
    std::string bufstr;
    std::string candidate;
    std::string sub;
    char c;
    int i;
    char buffer[30];
    size_t ret;

    while (input.read(buffer, 30))
    {
        for (i = 0; buffer[i] != '\0' && i < 30; i++)
            bufstr[i] = buffer[i];
        if ((ret = bufstr.find(av[2][0])) && ret)
        {
            output << bufstr.substr(0, ret);
            if (s1.size() <= 30 - ret)
            {
                candidate = bufstr.substr(ret, s1.size());
                if (candidate.compare(s1) == 0)
                {
                    output << s2;
                    candidate = "";
                }
            }
            else
            {
                sub = bufstr.substr(ret, (30 - ret));
                input.read(buffer, 30);
                bufstr = "";
                for (i = 0; buffer[i] != '\0' && i < 30; i++)
                    bufstr[i] = buffer[i];
                sub.append(bufstr);
                candidate = bufstr.substr(ret, s1.size());
                if (candidate.compare(s1) == 0)
                {
                    output << s2;
                    candidate = "";
                }
                else
                {
                    output << candidate;
                }
            }
        }
        else
        {
            output << bufstr;
            bufstr = "";
        }
    }
 /*
    std::string str ("There are two needles in this haystack with needles.");
  std::string str2 ("needle");

  // different member versions of find in the same order as above:
  std::size_t found = str.find(str2);
  if (found!=std::string::npos)
    std::cout << "first 'needle' found at: " << found << '\n';

  found=str.find("needles are small",found+1,6);
  if (found!=std::string::npos)
    std::cout << "second 'needle' found at: " << found << '\n';

  found=str.find("haystack");
  if (found!=std::string::npos)
    std::cout << "'haystack' also found at: " << found << '\n';

  found=str.find('.');
  if (found!=std::string::npos)
    std::cout << "Period found at: " << found << '\n';

  // let's replace the first needle:
  str.replace(str.find(str2),str2.length(),"preposition");
  std::cout << str << '\n'; */
}