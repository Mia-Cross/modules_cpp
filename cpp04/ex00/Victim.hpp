#ifndef VICTIM_CLASS_H
# define VICTIM_CLASS_H

# include <iostream>

class Victim {

    public :
        Victim();
        Victim(std::string name);
        ~Victim();
        Victim(Victim const &src);
        Victim &operator=(Victim const &that);

        void introduceThemselves();
        void getPolymorphed();

    private :
        std::string name;
};

std::ostream &operator<<(std::ostream &out, Victim const &in);

#endif