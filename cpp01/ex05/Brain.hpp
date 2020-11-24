#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

class Brain {
    public :
        Brain();
        ~Brain();
        Brain *identify();
    private :
        int neurons;
};

#endif