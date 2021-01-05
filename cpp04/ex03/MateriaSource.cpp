#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::~MateriaSource() {}

MateriaSource::MateriaSource(MateriaSource const &ref) {
    *this = ref;
}
MateriaSource &MateriaSource::operator=(MateriaSource const &ref)
{
    if (this != &ref)
    {
        for (unsigned int i = 0; i < ref.memory.size(); i++)
            this->memory[i] = ref.memory[i];
    }
}

void MateriaSource::learnMateria(AMateria *src) 
{
    if (this->memory.size() > 3)
        std::cout << "Memory full\n";
    else
    {
        this->memory.push_back(src);
        std::cout << "Memory : added " << src->getType() <<" in slot ";
        std::cout << this->memory.size() + 1 << std::endl;
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (unsigned int i = 0; i < this->memory.size(); i++)
    {
        AMateria &to_use = *this->memory[i];
        if ( !type.compare(to_use.getType()) )
            return (to_use.clone());
    }
    return (NULL);
}
