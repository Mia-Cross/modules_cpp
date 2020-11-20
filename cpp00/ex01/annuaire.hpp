#include <iostream>
#include <string>

class Contact
{
    std::string f_name;
    std::string l_name;
    std::string nickname;
    std::string login;
    std::string p_addr;
    std::string e_addr;
    std::string p_number;
    std::string b_date;
    std::string fav_meal;
    std::string u_color;
    std::string d_secret;
  public:
    void fill_info (std::string value);
} contact;

void Contact::fill_info (std::string value)
{
    int i;
    std::string input;
    char *to_fill = Contact::f_name;

    for (i = 0; i < 11; i++)
    {
        std::cout << "OK, PLEASE ENTER -FIRST NAME- :" << std::endl;
        getline (std::cin, input);
        to_fill++ = input;
    }
}
