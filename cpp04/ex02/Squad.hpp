#ifndef SQUAD_H
# define SQUAD_H

# include "ISpaceMarine.hpp"
# include "ISquad.hpp"
//# include <vector>

typedef struct s_list {
    ISpaceMarine *unit;
    s_list *next;
}               t_list;

class Squad : public ISquad
{
    public:
        Squad();
        Squad(Squad const &ref);
        virtual Squad &operator=(Squad const &ref);
        virtual ~Squad();

        virtual int getCount() const;
        virtual ISpaceMarine* getUnit(int) const;
        virtual int push(ISpaceMarine*);

    private:
        //std::vector<ISpaceMarine *> units;
        int count;
        t_list *first;
        t_list *last;
        void clearUnits();
        int searchUnits(ISpaceMarine *);
};

#endif