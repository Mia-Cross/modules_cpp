#ifndef PEON_CLASS_H
# define PEON_CLASS_H

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim {

    public :
        Peon(std::string name);
        ~Peon();
        Peon(Peon const &src);
        Peon &operator=(Peon const &that);

    //    std::string introduceThemselves() const;
        virtual void getPolymorphed() const;

    private :
        Peon();
     //   std::string name;
};

std::ostream &operator<<(std::ostream &out, Peon const &in);

#endif