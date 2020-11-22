#include "Contact.class.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

void Contact::fill_contact_info(void)
{
    std::cout << "OK, PLEASE ENTER -FIRST NAME- :" << std::endl;
    getline (std::cin, this->f_name);
    std::cout << "OK, PLEASE ENTER -LAST NAME- :" << std::endl;
    getline (std::cin, this->l_name);
    std::cout << "OK, PLEASE ENTER -NICKNAME- :" << std::endl;
    getline (std::cin, this->nickname);
    std::cout << "OK, PLEASE ENTER -LOGIN- :" << std::endl;
    getline (std::cin, this->login);
    std::cout << "OK, PLEASE ENTER -POSTAL ADDRESS- :" << std::endl;
    getline (std::cin, this->p_addr);
    std::cout << "OK, PLEASE ENTER -EMAIL ADDRESS-:" << std::endl;
    getline (std::cin, this->e_addr);
    std::cout << "OK, PLEASE ENTER -PHONE NUMBER- :" << std::endl;
    getline (std::cin, this->p_number);
    std::cout << "OK, PLEASE ENTER -BIRTHDAY DATE- :" << std::endl;
    getline (std::cin, this->b_date);
    std::cout << "OK, PLEASE ENTER -FAVORITE MEAL- :" << std::endl;
    getline (std::cin, this->fav_meal);
    std::cout << "OK, PLEASE ENTER -UNDERWEAR COLOR- :" << std::endl;
    getline (std::cin, this->u_color);
    std::cout << "OK, PLEASE ENTER -DARKEST SECRET- :" << std::endl;
    getline (std::cin, this->d_secret);
    std::cout << this->f_name << " WAS SUCCESFULLY ADDED :)" << std::endl;
}

void Contact::display_contact_info(void)
{
    std::cout << "FIRST NAME : " << this->f_name << std::endl;
    std::cout << "LAST NAME : " << this->l_name << std::endl;
    std::cout << "NICKNAME : " << this->nickname << std::endl;
    std::cout << "LOGIN : " << this->login << std::endl;
    std::cout << "POSTAL ADDRESS : " << this->p_addr << std::endl;
    std::cout << "EMAIL ADDRESS : " << this->e_addr << std::endl;
    std::cout << "PHONE NUMBER : " << this->p_number << std::endl;
    std::cout << "BIRTHDAY DATE : " << this->b_date << std::endl;
    std::cout << "FAVORITE MEAL : " << this->fav_meal << std::endl;
    std::cout << "UNDERWEAR COLOR : " << this->u_color << std::endl;
    std::cout << "DARKEST SECRET : " << this->d_secret << std::endl;
}

void Contact::print_search(int i)
{
    std::cout << std::setw(10) << i + 1 << "|";
    if (this->f_name.length() < 11) 
        std::cout << std::setw(10) << this->f_name << "|";
    else
        std::cout << this->f_name.substr(0, 9) << ".|";
    if (this->l_name.length() < 11) 
        std::cout << std::setw(10) << this->l_name << "|";
    else
        std::cout << this->l_name.substr(0, 9) << ".|";
    if (this->nickname.length() < 11) 
        std::cout << std::setw(10) << this->nickname << "|";
    else
        std::cout << this->nickname.substr(0, 9) << ".|";
    std::cout << std::endl;
}