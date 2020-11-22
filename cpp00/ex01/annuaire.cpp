#include "Contact.class.hpp"

Contact contact[8];
std::string input;
int ind = 0;
int nb_cont = 0;
int c = 0;

void display_contacts(void)
{
    int i;

    std::cout << std::setw(11) << "INDEX|";
    std::cout << std::setw(11) << "FIRST_NAME|";
    std::cout << std::setw(11) << "LAST_NAME|";
    std::cout << std::setw(11) << "NICKNAME|" << std::endl;
    for (i = 0; i < nb_cont; i++)
        contact[i].print_search(i);
}

void get_correct_input(void)
{
    std::cin >> input;
    if (input.compare("EXIT") == 0)
    {
        std::cout << "OK, BYE !" << std::endl;
        exit(0);
    }
    ind = 0;
    std::stringstream(input) >> ind;
    if (ind > 0 && ind <= nb_cont)
        return ;
    else
    {
        std::cout << "NO ENTRY FOR GIVEN INDEX, TRY AGAIN..." << std::endl;
        get_correct_input();
    }
}

void search_contact(void)
{
    if (nb_cont > 0)
    {
        std::cout << "WHICH IS THE INDEX OF THE CONTACT YOU WANT TO DISPLAY ?" << std::endl;
        get_correct_input();
        contact[ind - 1].display_contact_info();
    }
    else
        std::cout << "NO CONTACT YET..." << std::endl;
    std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
}

void add_new_contact(void)
{
    contact[c++].fill_contact_info();
    if (nb_cont < 8)
        nb_cont++;
    if (c == 8)
    {
        std::cout << "YOU NOW HAVE 8 CONTACTS" << std::endl;
        std::cout << "ANY NEW ADDITION WILL OVERWRITE THE OLDEST ENTRY" << std::endl;
        c = 0;
    }
    std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
}

int main (int ac, char **av)
{
    std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
    while (getline (std::cin, input) && input.compare("EXIT") != 0)
    {
        if (input.compare("ADD") == 0)
            add_new_contact();
        else if (input.compare("SEARCH") == 0)
        {
            display_contacts();
            search_contact();
        }
    }
    std::cout << "OK, BYE !" << std::endl;
    return 0;
}