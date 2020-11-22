#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <sstream>
# include <iostream>
# include <iomanip>
# include <string>
# include <ctime>

class Contact
{
    private:
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
        Contact(void);
        ~Contact(void);
        void fill_contact_info(void);
        void display_contact_info(void);
        void print_search(int i);
        void trunc_value(std::string str);
};

#endif