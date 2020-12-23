#ifndef PEON_CLASS_H
# define PEON_CLASS_H

# include <iostream>

class Peon : public Victim {

    public :
        Peon();
        Peon(std::string name);
        ~Peon();
        Peon(Peon const &src);
        Peon &operator=(Peon const &that);

    //    void polymorph();

    private :
      //  std::string name;
       // std::string title;
};

std::ostream &operator<<(std::ostream &out, Peon const &in);

#endif