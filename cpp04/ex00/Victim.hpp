#ifndef VICTIM_CLASS_H
# define VICTIM_CLASS_H

# include <iostream>

class Victim {

    public :
        Victim(std::string name);
        ~Victim();
        Victim(Victim const &src);
        Victim &operator=(Victim const &that);

        std::string introduceThemselves() const;
        virtual void getPolymorphed() const;

        void setName(std::string const name);
        std::string getName() const;

    private :
        Victim();
        std::string name;
};

std::ostream &operator<<(std::ostream &out, Victim const &in);

#endif