#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <vector>

class Character : public ICharacter
{
    private:
        std::string name;
        std::vector <AMateria *> inventory; 
        Character();

    public:
        Character(std::string const &name);
        Character(Character const &ref);
        Character &operator=(Character const &ref);
        ~Character();

        virtual std::string const &getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
};

#endif