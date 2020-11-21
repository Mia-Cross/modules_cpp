#include "annuaire.hpp"

std::string input;

void display_contacts(Contact *contact, int nb_cont)
{
    int i;

    std::cout << std::setw(11) << "INDEX|";
    std::cout << std::setw(11) << "FIRST_NAME|";
    std::cout << std::setw(11) << "LAST_NAME|";
    std::cout << std::setw(11) << "NICKNAME|" << std::endl;
    i = -1;
    while (++i < nb_cont)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << contact[i].f_name << "|";
        std::cout << std::setw(10) << contact[i].l_name << "|";
        std::cout << std::setw(10) << contact[i].nickname << "|" << std::endl;
    }
}

void get_correct_input(int *ind, int nb_cont)
{
    *ind = 0;
    if (nb_cont == 0)
        nb_cont = 1;
    std::cin >> input;
    if (input.compare("EXIT") == 0)
    {
        std::cout << "OK, BYE !" << std::endl;
        exit(0);
    }
    std::stringstream(input) >> *ind;
    if (*ind > 0 && *ind <= nb_cont)
        return ;
    else
    {
        std::cout << "NO ENTRY FOR GIVEN INDEX, TRY AGAIN..." << std::endl;
        get_correct_input(ind, nb_cont);
    }
}


int main (int ac, char **av)
{
    Contact contact[8];
    int i = 0;
    int ind = 0;
    int nb_cont = 0;

    std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
    while (getline (std::cin, input) && input.compare("EXIT") != 0)
    {
        if (input.compare("ADD") == 0)
        {
            contact[i++].fill_contact_info();
            if (nb_cont < 8)
                nb_cont++;
            if (i == 8)
            {
                std::cout << "YOU NOW HAVE 8 CONTACTS" << std::endl;
                std::cout << "FROM NOW ON, ANY NEW ADDITION WILL OVERWRITE THE OLDEST ENTRY" << std::endl;
                i = 0;
            }
            std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
        }
        else if (input.compare("SEARCH") == 0)
        {
            display_contacts(contact, nb_cont);
            if (nb_cont > 0)
            {
                std::cout << "WHICH IS THE INDEX OF THE CONTACT YOU WANT TO DISPLAY ?" << std::endl;
                get_correct_input(&ind, nb_cont);
                contact[ind - 1].display_contact_info();
            }
            else
                std::cout << "NO CONTACT YET..." << std::endl;
            std::cout << "WHAT DO YOU WANT TO DO ? (ADD, SEARCH, EXIT)" << std::endl;
        }
    }
    std::cout << "OK, BYE !" << std::endl;
    return 0;
}