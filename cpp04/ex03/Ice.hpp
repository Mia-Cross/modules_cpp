#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
    public:

        Ice();
        Ice(std::string const &type);
        Ice(Ice const &ref);
        Ice &operator=(Ice const &ref);
        ~Ice();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif
