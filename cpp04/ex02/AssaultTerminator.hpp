#ifndef ASSAULT_TERMINATOR_H
# define ASSAULT_TERMINATOR_H

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
    public:
        AssaultTerminator();
        AssaultTerminator(AssaultTerminator const &ref);
        virtual AssaultTerminator &operator=(AssaultTerminator const &ref);
        virtual ~AssaultTerminator();

        virtual AssaultTerminator* clone() const;
        virtual void battleCry() const;
        virtual void rangedAttack() const;
        virtual void meleeAttack() const;
};

#endif