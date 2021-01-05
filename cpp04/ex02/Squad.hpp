#ifndef SQUAD_H
# define SQUAD_H

# include "ISpaceMarine.hpp"
# include "ISquad.hpp"
# include <vector>

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
        
        void clearUnits();

    private:
        std::vector<ISpaceMarine *> units;
};

#endif