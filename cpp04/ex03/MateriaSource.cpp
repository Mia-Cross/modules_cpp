#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : nbMateria(0) {
    memset(memory, 0, sizeof(AMateria *) * 4);
}

MateriaSource::~MateriaSource() {
    this->clearMemory();
}
MateriaSource::MateriaSource(MateriaSource const &ref) : nbMateria(ref.getCount())  {
    // std::cout << "Copy called\n";
    memset(memory, 0, sizeof(AMateria *) * 4);
    for (int i = 0; i < this->nbMateria; i++)
        this->memory[i] = ref.memory[i]->clone();
}
MateriaSource &MateriaSource::operator=(MateriaSource const &ref) {
   // std::cout << "Assignation called\n";
    if (this != &ref)
    {
        this->clearMemory(); 
        this->nbMateria = ref.getCount();
        for (int i = 0; i < this->nbMateria; i++)
            this->memory[i] = ref.memory[i]->clone();
    }
    return (*this);
}

int MateriaSource::getCount() const {
    return (this->nbMateria);
}

void MateriaSource::learnMateria(AMateria *src) 
{
    if (this->nbMateria > 3)
        std::cout << "Memory full\n";
    else
    {
        std::cout << "< Memory >  added " << src->getType() <<" in slot ";
        std::cout << this->nbMateria << "\tMemorySize < " << this->nbMateria;
        this->memory[this->nbMateria++] = src;
        std::cout << " -> " << this->nbMateria << " >\n";
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    int idx = searchMateria(type);

    if ( idx == -1 )
        return (NULL);
    std::cout << "< Memory >  Created " << this->memory[idx]->getType();
    std::cout <<" from slot " << idx << std::endl;
    return (this->memory[idx]->clone());
}

void MateriaSource::clearMemory()
{
    std::cout << "Clearing " << this->nbMateria << " materias\n";
    for (int i = 0; i < this->nbMateria; i++)
    {
        if (this->memory[i])
            delete this->memory[i];
        this->memory[i] = NULL;
    }
    this->nbMateria = 0;
}

int MateriaSource::searchMateria(std::string const &ref)
{
    for (int i = 0; i < this->nbMateria; i++)
    {
        if (this->memory[i] && !ref.compare(memory[i]->getType()))
            return (i);
    }
    std::cout << "Can't find " << ref << std::endl;
    return (-1);
}