#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
    public:

        Cure();
        Cure(std::string const &type);
        Cure(Cure const &ref);
        Cure &operator=(Cure const &ref);
        ~Cure();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif
