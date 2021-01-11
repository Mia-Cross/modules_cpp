#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::~MateriaSource() {
    for (unsigned int i = 0; i < memory.size(); i++)
        delete memory[i];
}
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
    return (*this);
}

void MateriaSource::learnMateria(AMateria *src) 
{
    if (this->memory.size() > 3)
        std::cout << "Memory full\n";
    else
    {
        std::cout << "< Memory >  added " << src->getType() <<" in slot ";
        std::cout << this->memory.size();
        this->memory.push_back(src);
        std::cout << "\tMemorySize <" << this->memory.size() <<">\n";

    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (unsigned int i = 0; i < this->memory.size(); i++)
    {
        AMateria *to_use = this->memory[i];
        if ( !type.compare(to_use->getType()) )
        {
            std::cout << "< Memory >  Created " << to_use->getType() <<" from slot " << i;
            AMateria *cloneA = to_use->clone();
            delete this->memory[i];
            this->memory.erase(this->memory.begin() + i);
            std::cout << "\tMemorySize <" << this->memory.size() <<">\n";
            return (cloneA);
        }
    }
    return (NULL);
}