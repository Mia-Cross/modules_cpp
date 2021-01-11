#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:

        std::string     name;
        int             nbMateria;
        AMateria        *inventory[4];
        void            clearMemory();
        Character();
        //std::vector <AMateria *> inventory; 

    public:

        Character(std::string const &name);
        Character(Character const &ref);
        Character &operator=(Character const &ref);
        ~Character();

        virtual std::string const &getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
        
        int getCount() const ;
};

#endif