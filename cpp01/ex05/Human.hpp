#ifndef HUMAN_CLASS_H
# define HUMAN_CLASS_H

# include "Brain.hpp"

class Human {
    public :
        Human();
        ~Human();
        Brain *identify();
        Brain &getBrain();
    private :
        Brain *brain;
};

#endif