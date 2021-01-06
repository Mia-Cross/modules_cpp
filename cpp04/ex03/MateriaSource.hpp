#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        std::vector <AMateria *> memory;

    public:
        MateriaSource();
        MateriaSource(MateriaSource const &ref);
        MateriaSource &operator=(MateriaSource const &ref);
        ~MateriaSource();

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const &type);
};

#endif