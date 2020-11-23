//header
#ifndef PONY_CLASS_H
# define PONY_CLASS_H

# include <string>

class Pony {

    public:
        Pony(std::string h_color, std::string t_color);
        ~Pony(void);
        void takeStep(int nb) const;
        void runThisWay(std::string direction) const;
        void magicTail(std::string color);

    private:
        std::string _hair_color;
        std::string _tail_color;
};

void ponyOnTheStack(std::string h_color, std::string t_color);
void ponyOnTheHeap(std::string h_color, std::string t_color);

#endif